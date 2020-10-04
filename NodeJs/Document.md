# PKCE - Generate a PKCE Code Challenge and a Code Verifier

## Introduction
You can use the NodeJs library to generate a code challenge and a code verifier for OAuth and OIDC authorizarization. The sample program, `index.js`, uses this library.


## How to use this library in a NodeJs application
1. Clone the repository: 
        `git clone https://github.com/pareek-narendra/pkce`
2. Get into the project folder and install node modules: 
        `npm i`
3. Go to the NodeJs folder using the following command:
        `cd NodeJs/`
4. Start and run the project: 
        `node index.js`

It will generate the `code_verifier` and `code_challenge` values. You can use these values in the OAuth and OIDC authorization code flow.




