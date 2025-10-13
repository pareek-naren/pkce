<?php
/**
 * PKCE Generator (RFC 7636)
 *
 * Provides functions to create a code_verifier and code_challenge
 * for OAuth 2.0 Authorization Code Flow with PKCE.
 *
 * @version 1.0.0
 */

/**
 * Base64 URL-safe encoding (RFC 4648 §5)
 *
 * @param string $data
 * @return string
 */
function base64url_encode(string $data): string {
    return rtrim(strtr(base64_encode($data), '+/', '-_'), '=');
}

/**
 * Generate a secure code_verifier.
 *
 * @param int $length Length between 43 and 128 characters.
 * @return string
 * @throws Exception
 */
function generateCodeVerifier(int $length = 64): string {
    if ($length < 43) $length = 43;
    if ($length > 128) $length = 128;

    $bytes = random_bytes((int)ceil($length * 3 / 4));
    $verifier = base64url_encode($bytes);

    // Ensure final length exactly matches
    return substr($verifier, 0, $length);
}

/**
 * Generate the S256 code_challenge from a given code_verifier.
 *
 * @param string $verifier
 * @return string
 */
function generateCodeChallenge(string $verifier): string {
    return base64url_encode(hash('sha256', $verifier, true));
}
