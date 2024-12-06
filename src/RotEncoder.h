#ifndef ROTENCODER_H
#define ROTENCODER_H

#include <string>

class RotEncoder {
public:
    // Encode 
    static std::string encode(const std::string& text, int key);

    // Decode 
    static std::string decode(const std::string& text, int key);

private:
    // Helper to shift a single character
    static char shiftChar(char c, int shift);
};

#endif // ROTENCODER_H
