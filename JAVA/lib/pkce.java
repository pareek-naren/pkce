import java.security.MessageDigest;
import java.security.SecureRandom;
import java.util.Base64;

public class PKCE {
    public static String[] generate(String method) throws Exception {
        SecureRandom secureRandom = new SecureRandom();
        byte[] codeVerifierBytes = new byte[64];
        secureRandom.nextBytes(codeVerifierBytes);
        String codeVerifier = Base64.getUrlEncoder().withoutPadding().encodeToString(codeVerifierBytes);

        String codeChallenge;
        if (method.equalsIgnoreCase("plain")) {
            codeChallenge = codeVerifier;
        } else {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");
            byte[] hashed = digest.digest(codeVerifier.getBytes("US-ASCII"));
            codeChallenge = Base64.getUrlEncoder().withoutPadding().encodeToString(hashed);
        }

        return new String[]{codeVerifier, codeChallenge, method};
    }
}
