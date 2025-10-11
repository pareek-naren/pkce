using System;
using System.Security.Cryptography;
using System.Text;

public class PKCE
{
    public static (string Verifier, string Challenge, string Method) Generate(string method = "S256")
    {
        // Generate a random code verifier
        var rng = RandomNumberGenerator.Create();
        byte[] bytes = new byte[64];
        rng.GetBytes(bytes);
        string codeVerifier = Base64UrlEncode(bytes);

        // Compute the code challenge
        string codeChallenge;
        if (method.Equals("plain", StringComparison.OrdinalIgnoreCase))
        {
            codeChallenge = codeVerifier;
        }
        else
        {
            using var sha256 = SHA256.Create();
            var challengeBytes = sha256.ComputeHash(Encoding.ASCII.GetBytes(codeVerifier));
            codeChallenge = Base64UrlEncode(challengeBytes);
        }

        return (codeVerifier, codeChallenge, method);
    }

    private static string Base64UrlEncode(byte[] input)
    {
        return Convert.ToBase64String(input)
            .Replace("+", "-")
            .Replace("/", "_")
            .Replace("=", "");
    }
}
