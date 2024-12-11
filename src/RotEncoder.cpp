#include "RotEncoder.h"
#include <cctype>

const int maxChar = 26; //total number of characters in alphabet

std::string RotEncoder::encode(const std::string& text) const {
    std::string result;
    for (char c : text) {
        if (std::isalpha(c)) {
            char base = std::islower(c) ? 'a' : 'A';
            result += (c - base + shift) % maxChar + base;
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
            result += (c -base - shift + maxChar) % maxChar + base;
        } else {
            result += c;
        }
    }
    return result;
}
