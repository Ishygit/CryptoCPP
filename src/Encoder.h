#ifndef ENCODER_H
#define ENCODER_H

#include <string>

class Encoder {
public:
    virtual ~Encoder() = default;

    // Pure virtual methods to encode and decode text
    virtual std::string encode(const std::string& text) const = 0;
    virtual std::string decode(const std::string& text) const = 0;
};

#endif
