#ifndef ROTENCODER_H
#define ROTENCODER_H

#include "Encoder.h"
#include "MyLib.h"
#include <string>

class RotEncoder : public Encoder {
private:
    int shift;

public:
    explicit RotEncoder(int offset) : shift(offset) {
        if (offset <= 0) {
            throw BaseException("Bad offset: " + std::to_string(offset));
        }
    }
    
    std::string encode(const std::string& text) const override;
    std::string decode(const std::string& text) const override;
};

#endif // ROTENCODER_H
