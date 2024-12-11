#include "SbsEncoder.h"
#include <stdexcept>
#include <sstream>
#include <cctype>

std::unordered_map<char, char> SbsEncoder::SubstitutionMap;
std::unordered_map<char, char> SbsEncoder::reverseSubstitutionMap;

SbsEncoder::SbsEncoder(const std::string& key) {
   processKey(key);
}

void SbsEncoder::processKey(const std::string& key) {
    std::istringstream keyStream(key);
    std::string pair;

    while (std::getline(keyStream, pair, ',')) {
        if (pair.length() != 2 || !std::isalpha(pair[0]) ||
         !std::isalpha(pair[1])) {
            throw BaseException("Bad code pair: " + pair);
        }

        CharPair charPair(pair[0], pair[1]);
        SubstitutionMap[charPair.from] = charPair.to;
        reverseSubstitutionMap[charPair.to] = charPair.from;

        // Handle case insensitivity
        if (std::islower(charPair.from) && std::islower(charPair.to)) {
            SubstitutionMap[std::toupper(charPair.from)] = 
            std::toupper(charPair.to);
            reverseSubstitutionMap[std::toupper(charPair.to)] =
             std::toupper(charPair.from);
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
        result += reverseSubstitutionMap.count(c) ? reverseSubstitutionMap.at(c)
         : c;
    }
    return result;
}
