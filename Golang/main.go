package main

import (
	"Golang/lib"
	"fmt"
)

func main() {
	pkce, err := lib.GeneratePKCE("sha512")
	if err!= nil{
		panic(err)
	}
	fmt.Println("code_verifier :", pkce.CodeVerifier)
	fmt.Println("code_challenge :", pkce.CodeChallenge)
	fmt.Println("code_challenge_method :", pkce.CodeChallengeMethod)
}
