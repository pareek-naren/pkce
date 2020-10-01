package lib

import (
	"crypto/md5"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/sha512"
	"errors"
	"hash"
	"math/rand"
	"strings"
	"time"
)

var  supportedAlgorithms = []string{"SHA1", "SHA256", "SHA512", "MD5"}

type PKCE struct {
	CodeVerifier string
	CodeChallenge string
	CodeChallengeMethod string
}

func GeneratePKCE(codeChallengeMethod string) (*PKCE,error) {
	if codeChallengeMethod == "" {
		codeChallengeMethod = "SHA256"
	}
	if !Contains(supportedAlgorithms, strings.ToUpper(codeChallengeMethod)){
		return nil, errors.New("code challenge method is not supported")
	}
	pkce := PKCE{
		CodeChallengeMethod: strings.ToUpper(codeChallengeMethod),
	}
	pkce.generateCodeVerifier()
	pkce.generateCodeChallenge()
	return &pkce, nil
}

func (p *PKCE) generateCodeVerifier() {
	length := 32
	r := rand.New(rand.NewSource(time.Now().UnixNano()))
	b := make([]byte, length, length)
	for i := 0; i < length; i++ {
		b[i] = byte(r.Intn(255))
	}
	p.CodeVerifier = Base64URLEncode(b)
}

func (p *PKCE) generateCodeChallenge() {
	var h hash.Hash
	switch p.CodeChallengeMethod {
	case "SHA1":
		h = sha1.New()
	case "SHA256":
		h = sha256.New()
	case "SHA512":
		h = sha512.New()
	case "MD5":
		h = md5.New()
	}
	h.Write([]byte(p.CodeVerifier))
	p.CodeChallenge = Base64URLEncode (h.Sum(nil))
}
