#include "PkceGenerator.h"
#include <iostream>

int main() {
    try {
        std::string verifier = PkceGenerator::GenerateCodeVerifier(64);
        std::string challenge = PkceGenerator::GenerateCodeChallengeS256(verifier);

        std::cout << "code_verifier: " << verifier << "\n";
        std::cout << "verifier length: " << verifier.size() << "\n";
        std::cout << "code_challenge (S256): " << challenge << "\n";
        std::cout << "code_challenge_method: S256\n";
    }
    catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }
    return 0;
}
