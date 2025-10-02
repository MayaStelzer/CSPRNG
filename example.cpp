#include <iostream>
#include <vector>
#include <bitset>
#include <sstream>
#include <openssl/rand.h> // OpenSSL CSPRNG

// Generate a bitstring of length nbits
std::string csprng_bitstring(int nbits) {
    if (nbits <= 0) return "";

    int nbytes = (nbits + 7) / 8; // round up
    std::vector<unsigned char> buf(nbytes);

    if (RAND_bytes(buf.data(), nbytes) != 1) {
        throw std::runtime_error("CSPRNG failed");
    }

    std::stringstream ss;
    for (int i = 0; i < nbytes; ++i) {
        if (i == nbytes - 1 && nbits % 8 != 0) {
            // Mask extra bits in the last byte
            unsigned char mask = (1 << (nbits % 8)) - 1;
            ss << std::bitset<8>(buf[i] & mask).to_string().substr(8 - (nbits % 8));
        } else {
            ss << std::bitset<8>(buf[i]);
        }
    }

    return ss.str();
}

// Generate a bytestring (as a bitstring) of length nbytes
std::string csprng_bytestring(int nbytes) {
    if (nbytes <= 0) return "";

    std::vector<unsigned char> buf(nbytes);
    if (RAND_bytes(buf.data(), nbytes) != 1) {
        throw std::runtime_error("CSPRNG failed");
    }

    std::stringstream ss;
    for (auto b : buf) {
        ss << std::bitset<8>(b);
    }

    return ss.str();
}

int main() {
    std::string bits10 = csprng_bitstring(10);
    std::cout << "10-bit: " << bits10 << "\n";

    std::string bits128 = csprng_bitstring(128);
    std::cout << "128-bit: " << bits128 << "\n";

    std::string bytes8 = csprng_bytestring(8);
    std::cout << "8-byte: " << bytes8 << "\n";

    std::string bytes16 = csprng_bytestring(16);
    std::cout << "16-byte: " << bytes16 << "\n";

    return 0;
}
