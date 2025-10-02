package main

import (
	"crypto/rand"
	"fmt"
)

func RandBytes(nbytes int) ([]byte, error) {
	buf := make([]byte, nbytes)
	_, err := rand.Read(buf)
	return buf, err
}

// BitString returns exactly nbits as a string of 0s and 1s
func BitString(nbits int) (string, error) {
	if nbits <= 0 {
		return "", nil
	}
	nbytes := (nbits + 7) / 8
	buf, err := RandBytes(nbytes)
	if err != nil {
		return "", err
	}

	// mask extra bits in the last byte if needed
	extraBits := nbytes*8 - nbits
	if extraBits != 0 {
		mask := byte(0xFF >> extraBits)
		buf[nbytes-1] &= mask
	}

	// convert to string of '0' and '1'
	out := make([]byte, 0, nbits)
	for i := 0; i < nbytes; i++ {
		for bit := 7; bit >= 0; bit-- {
			if len(out) >= nbits {
				break
			}
			if (buf[i]>>bit)&1 == 1 {
				out = append(out, '1')
			} else {
				out = append(out, '0')
			}
		}
	}
	return string(out), nil
}

// ByteString returns exactly nbytes*8 bits as a string of 0s and 1s
func ByteString(nbytes int) (string, error) {
	buf, err := RandBytes(nbytes)
	if err != nil {
		return "", err
	}

	out := make([]byte, 0, nbytes*8)
	for i := 0; i < nbytes; i++ {
		for bit := 7; bit >= 0; bit-- {
			if (buf[i]>>bit)&1 == 1 {
				out = append(out, '1')
			} else {
				out = append(out, '0')
			}
		}
	}
	return string(out), nil
}

func main() {
	bits, _ := BitString(10)
	fmt.Println("10-bit:", bits)

	bits128, _ := BitString(128)
	fmt.Println("128-bit:", bits128)

	bytes8, _ := ByteString(8)
	fmt.Println("8-byte:", bytes8)

	bytes16, _ := ByteString(16)
	fmt.Println("16-byte:", bytes16)
}
