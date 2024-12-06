#include "RotEncoder.h"

char RotEncoder::shiftChar(char c, int shift) {
    if (std::isalpha(c)) {
        char base = std::isupper(c) ? 'A' : 'a';
        return base + (c - base + shift + 26) % 26; // Wrap around with modulo
    }
    return c; // Non-alphabetic characters are unchanged
}

std::string RotEncoder::encode(const std::string& text, int key) {
    std::string result;
    for (char c : text) {
        result += shiftChar(c, key);
    }
    return result;
}

std::string RotEncoder::decode(const std::string& text, int key) {
    return encode(text, -key); // Decoding is reverse encoding
}
