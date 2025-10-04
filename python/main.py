from lib.pkce import PKCE

if __name__ == "__main__":
    verifier, challenge, method = PKCE.generate("S256")
    print("code_verifier:", verifier)
    print("code_challenge:", challenge)
    print("code_challenge_method:", method)
