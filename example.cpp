#include <openssl/rand.h>
#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

std::string bytes_to_bitstring(const std::vector<unsigned char>& bytes, size_t nbits) {
    std::string s;
    s.reserve(nbits);
    size_it produced = 0;
    for (unsigned char b : bytes) {
        for (int i = 7; i >= 0 && produced < nbits; --i, ++produced) {
            s.push_back(((b >> i) & 1) ? '1' : '0');
        }
    }
    return s;
}