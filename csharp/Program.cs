using System;

class Program
{
    static void Main()
    {
        var (verifier, challenge, method) = PKCE.Generate("S256");

        Console.WriteLine("code_verifier: " + verifier);
        Console.WriteLine("code_challenge: " + challenge);
        Console.WriteLine("code_challenge_method: " + method);
    }
}
