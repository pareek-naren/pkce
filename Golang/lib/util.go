package lib

import (
	"encoding/base64"
	"strings"
)

func Base64URLEncode(str []byte) string {
	encoded := base64.StdEncoding.EncodeToString(str)
	encoded = strings.Replace(encoded, "+", "-", -1)
	encoded = strings.Replace(encoded, "/", "_", -1)
	encoded = strings.Replace(encoded, "=", "", -1)
	return encoded
}

func Contains(a []string, x string) bool {
	for _, n := range a {
		if x == n {
			return true
		}
	}
	return false
}