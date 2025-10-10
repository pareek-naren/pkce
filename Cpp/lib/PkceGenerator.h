#ifndef PKCE_GENERATOR_H
#define PKCE_GENERATOR_H

#include <string>

class PkceGenerator {
public:
    static constexpr int MinVerifierLength = 43;
    static constexpr int MaxVerifierLength = 128;

    // Generate a random code_verifier (RFC 7636)
    static std::string GenerateCodeVerifier(int length = 64);

    // Generate a code_challenge using S256 method (recommended)
    static std::string GenerateCodeChallengeS256(const std::string& codeVerifier);

    // Generate a plain code_challenge (only if server supports it)
    static std::string GenerateCodeChallengePlain(const std::string& codeVerifier);

private:
    static std::string Base64UrlEncode(const unsigned char* data, size_t len);
    static std::vector<unsigned char> SecureRandomBytes(size_t n);
};

#endif // PKCE_GENERATOR_H
