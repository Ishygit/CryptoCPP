#include "SbsEncoder.h"
#include <stdexcept>
#include <sstream>
#include <cctype>

std::unordered_map<char, char> SbsEncoder::SubstitutionMap;
std::unordered_map<char, char> SbsEncoder::reverseSubstitutionMap;

SbsEncoder::SbsEncoder(const std::string &key) {
    // Parse the key and populate the substitution maps
    std::istringstream keyStream(key);
    std::string pair;

    while (std::getline(keyStream, pair, ',')) {
        if (pair.length() != 2) {
            throw std::invalid_argument("Invalid key format: " + key);
        }
        char from = pair[0];
        char to = pair[1];

        SubstitutionMap[from] = to;
        reverseSubstitutionMap[to] = from;

        // Handle case insensitivity
        if (std::islower(from) && std::islower(to)) {
            SubstitutionMap[std::toupper(from)] = std::toupper(to);
            reverseSubstitutionMap[std::toupper(to)] = std::toupper(from);
        }
    }
}

std::string SbsEncoder::encode(const std::string &text) const {
    std::string result;
    for (char c : text) {
         result += SubstitutionMap.count(c) ? SubstitutionMap.at(c) : c;
    }
    return result;
}

std::string SbsEncoder::decode(const std::string &text) const {
    std::string result;
    for (char c : text) {
        result += SubstitutionMap.count(c) ? SubstitutionMap.at(c) : c;
    }
    return result;
}
