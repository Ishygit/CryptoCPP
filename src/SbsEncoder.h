#ifndef SBSENCODER_H
#define SBSENCODER_H

#include <string>
#include <unordered_map>

class SbsEncoder {
public:
    // Encode the input using the key
    static std::string encode(const std::string& input, const std::string& key);

    // Decode the input using the key
    static std::string decode(const std::string& input, const std::string& key);

private:
    // Helper function to build the substitution map from the key
    static std::unordered_map<char, char> buildSubstitutionMap(const std::string& key, bool reverse);
};

#endif
