package main

import (
	"crypto/md5"
	"crypto/sha1"
	"crypto/sha256"
	"crypto/sha512"
)

func SHA256(str string) []byte {
	h := sha256.New()
	h.Write([]byte(str))
	return h.Sum(nil)
}

func SHA1(str string) []byte {
	h := sha1.New()
	h.Write([]byte(str))
	return h.Sum(nil)
}

func SHA512 (str string) []byte {
	h := sha512.New()
	h.Write([]byte(str))
	return h.Sum(nil)
}

func MD5 (str string) []byte {
	h := md5.New()
	h.Write([]byte(str))
	return h.Sum(nil)
}
