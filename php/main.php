<?php
require_once __DIR__ . '/lib/pkce.php';

try {
    $code_verifier = generateCodeVerifier();
    $code_challenge = generateCodeChallenge($code_verifier);

    echo "=== PKCE Generator ===\n";
    echo "code_verifier:  $code_verifier\n";
    echo "code_challenge: $code_challenge\n";
    echo "method:         S256\n";
} catch (Exception $e) {
    echo "Error generating PKCE: " . $e->getMessage() . "\n";
}
