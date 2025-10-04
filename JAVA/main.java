public class Main {
    public static void main(String[] args) {
        try {
            String[] result = PKCE.generate("S256");
            System.out.println("code_verifier: " + result[0]);
            System.out.println("code_challenge: " + result[1]);
            System.out.println("code_challenge_method: " + result[2]);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
