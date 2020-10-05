# PKCE - Generate a PKCE Code Challenge and a Code Verifier

## Introduction
You can use the Golang library to generate a code challenge and a code verifier for OAuth and OIDC authorization. 

## How to use this library in a Golang application

### Preprequisite
Golang must be installed on your system. If you haven't installed Golang, install it using the following command:
`sudo apt install golang-go`

1. Make a directory to run your Go files. In this example, I have named the directory `pkce`.
2. Change directory to pkce.  `cd pkce`
3. Clone this GitHub repository `git clone https://github.com/pareek-narendra/pkce`
4. Once the repository is cloned, verify the items in the pkce directory. It must include the following items:
		- Golang
5. Change directory to Golang. 	`cd Golang/`
6. Verify the content in the Golang directory. It must include the following items:
	- Document.md
	- go.mod
	- lib
	- main.go (sample application)
7. Import the Golang library using the following command:
    ```
    import (
	    "./lib"
	   )
     ```
  8. Specify the hashing algorithm using the following command: 
     ```
      pkce, err := lib.GeneratePKCE("sha512")
	     if err!= nil{
		     panic(err)
	     }
     ```
    
     The supported hasing algorithms are: SHA1, SHA256, SHA512, MD5
  9. In your application, invoke the pkce.CodeVerifier and pkce.CodeChallenge functions

  It will generate a unique code verifier and code challenge value. You can use these values in the OAuth and OIDC authorization code flow.
    
  10.  To use the sampple application, you can run the program using the following command: `go run main.go`

### Sample result
`code_verifier` : `w7lBA5Ko4b-JzTcX8pt5gvv0szJxSXvgu-g4htB6BgM`

`code_challenge` : `y9vAH-IyDZLtm3IL3etn6Zvk-8oWQecQS-Imqdqp_NOOTzw862BxadtOMNS8HpuQVGSLbIFOfv6hrMkxouyZeA`

`code_challenge_method` : `SHA512`
