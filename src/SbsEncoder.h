#ifndef SBSENCODER_H
#define SBSENCODER_H

#include "Encoder.h"
#include <unordered_map>
#include <string>

class SbsEncoder : public Encoder {
private:
    // Helper function to build the substitution map from the key
    static std::unordered_map<char, char> SubstitutionMap;
    static std::unordered_map<char, char> reverseSubstitutionMap;

public:
   explicit SbsEncoder(const std::string& key);
   std::string encode(const std::string& text) const override;
   std::string decode(const std::string& text) const override;
};

#endif
