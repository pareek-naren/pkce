import base64
import hashlib
import os

class PKCE:
    @staticmethod
    def generate(method="S256"):
        code_verifier = base64.urlsafe_b64encode(os.urandom(64)).rstrip(b'=').decode('utf-8')

        if method.upper() == "PLAIN":
            code_challenge = code_verifier
        else:
            digest = hashlib.sha256(code_verifier.encode("ascii")).digest()
            code_challenge = base64.urlsafe_b64encode(digest).rstrip(b'=').decode('utf-8')

        return code_verifier, code_challenge, method
