#ifndef SBSENCODER_H
#define SBSENCODER_H

#include "Encoder.h"
#include <unordered_map>
#include <string>
#include <vector>
#include "MyLib.h"


class SbsEncoder : public Encoder {
private:
    // nested class for character pairs
    class CharPair {
    public:
        char from;
        char to;

        // Constructor for CharPair
        CharPair(char fromChar, char toChar) : from(fromChar), to(toChar) {}
    };

   //  Substitution and reverse maps
    static std::unordered_map<char, char> SubstitutionMap;
    static std::unordered_map<char, char> reverseSubstitutionMap;

   //  Helper to parse key into character pairs
   void processKey(const std::string& key);

public:
   explicit SbsEncoder(const std::string& key);
   std::string encode(const std::string& text) const override;
   std::string decode(const std::string& text) const override;
};

#endif
