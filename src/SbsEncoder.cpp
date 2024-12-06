#include "SbsEncoder.h"
#include <sstream>
#include <cctype>
#include <unordered_map>

std::string SbsEncoder::encode(const std::string& input, const std::string& key) {
    // Build the substitution map
    auto substitutionMap = buildSubstitutionMap(key, false);

    // Perform substitution
    std::string output;
    for (char ch : input) {
        if (std::isalpha(ch)) {
            char lowerCh = std::tolower(ch);
            char substituted = substitutionMap.count(lowerCh) ? substitutionMap[lowerCh] : lowerCh;
            output += std::isupper(ch) ? std::toupper(substituted) : substituted;
        } else {
            output += ch; // Leave non-alphabetic characters unchanged
        }
    }
    return output;
}

std::string SbsEncoder::decode(const std::string& input, const std::string& key) {
    // Build the reverse substitution map
    auto reverseSubstitutionMap = buildSubstitutionMap(key, true);

    // Perform reverse substitution
    std::string output;
    for (char ch : input) {
        if (std::isalpha(ch)) {
            char lowerCh = std::tolower(ch);
            char substituted = reverseSubstitutionMap.count(lowerCh) ? reverseSubstitutionMap[lowerCh] : lowerCh;
            output += std::isupper(ch) ? std::toupper(substituted) : substituted;
        } else {
            output += ch; // Leave non-alphabetic characters unchanged
        }
    }
    return output;
}

std::unordered_map<char, char> SbsEncoder::buildSubstitutionMap(const std::string& key, bool reverse) {
    std::unordered_map<char, char> substitutionMap;
    std::istringstream keyStream(key);
    std::string pair;

    // Parse the key into letter pairs
    while (std::getline(keyStream, pair, ',')) {
        if (pair.size() == 2) {
            char first = pair[0];
            char second = pair[1];
            if (reverse) {
                substitutionMap[second] = first;
            } else {
                substitutionMap[first] = second;
            }
        }
    }
    return substitutionMap;
}
