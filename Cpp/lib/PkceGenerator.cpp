#include "PkceGenerator.h"
#include <openssl/rand.h>
#include <openssl/sha.h>
#include <openssl/evp.h>

#include <vector>
#include <cmath>
#include <stdexcept>

// Generate cryptographically secure random bytes
std::vector<unsigned char> PkceGenerator::SecureRandomBytes(size_t n) {
    std::vector<unsigned char> buf(n);
    if (RAND_bytes(buf.data(), static_cast<int>(n)) != 1) {
        throw std::runtime_error("RAND_bytes failed");
    }
    return buf;
}

// Base64 URL encoding (no padding)
std::string PkceGenerator::Base64UrlEncode(const unsigned char* data, size_t len) {
    if (len == 0) return "";

    int out_len = 4 * static_cast<int>(std::ceil(len / 3.0));
    std::vector<unsigned char> out(out_len + 1); // extra for null terminator
    int written = EVP_EncodeBlock(out.data(), data, static_cast<int>(len));
    if (written <= 0) throw std::runtime_error("EVP_EncodeBlock failed");

    std::string base64(reinterpret_cast<char*>(out.data()), written);

    // Convert to base64url: replace '+' -> '-', '/' -> '_', remove '='
    for (char& c : base64) {
        if (c == '+') c = '-';
        else if (c == '/') c = '_';
    }

    size_t pad = base64.find('=');
    if (pad != std::string::npos) base64.erase(pad);

    return base64;
}

// Generate a random code_verifier
std::string PkceGenerator::GenerateCodeVerifier(int length) {
    if (length < MinVerifierLength || length > MaxVerifierLength) {
        throw std::invalid_argument("Verifier length must be between 43 and 128 characters.");
    }

    int bytesNeeded = static_cast<int>(std::ceil(length * 3.0 / 4.0));
    std::string candidate;

    while (static_cast<int>(candidate.size()) < length) {
        auto bytes = SecureRandomBytes(bytesNeeded);
        candidate += Base64UrlEncode(bytes.data(), bytes.size());
    }

    if (static_cast<int>(candidate.size()) > length) {
        candidate.resize(length);
    }

    return candidate;
}

// Generate a code_challenge using SHA-256
std::string PkceGenerator::GenerateCodeChallengeS256(const std::string& codeVerifier) {
    if (codeVerifier.empty()) throw std::invalid_argument("Code verifier cannot be empty.");

    unsigned char hash[SHA256_DIGEST_LENGTH];
    if (!SHA256(reinterpret_cast<const unsigned char*>(codeVerifier.data()),
                codeVerifier.size(), hash)) {
        throw std::runtime_error("SHA256 hashing failed.");
    }

    return Base64UrlEncode(hash, SHA256_DIGEST_LENGTH);
}

// Return the plain code challenge (not recommended)
std::string PkceGenerator::GenerateCodeChallengePlain(const std::string& codeVerifier) {
    if (codeVerifier.empty()) throw std::invalid_argument("Code verifier cannot be empty.");
    return codeVerifier;
}
