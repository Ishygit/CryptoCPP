#include "RotEncoder.h"
#include <cctype>

// RotEncoder::RotEncoder(int shiftValue) : shift(shiftValue % 26) {}

std::string RotEncoder::encode(const std::string& text) const {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            result += (c - base + shift) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}

std::string RotEncoder::decode(const std::string& text) const {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            result += (c -base - shift + 26) % 26 + base;
        } else {
            result += c;
        }
    }
    return result;
}
