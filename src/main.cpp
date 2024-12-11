#include <iostream>
#include <string>
#include <memory>
#include "Encoder.h"
#include "RotEncoder.h"
#include "SbsEncoder.h"
#include "MyLib.h"

int main(int argc, char* argv[]) {
    try {
        // Validate command-line arguments
        
        if (argc != 4 ) {
            throw BaseException("Usage: crypto algorithm key");
        }

        const int keyidx = 3; //index value for the key

        std::string mode = argv[1];
        std::string encoderType = argv[2];
        std::string key = argv[keyidx];
        std::unique_ptr<Encoder> encoder;

        // Initialize the encoder based on type
        if (encoderType == "RotEncoder") {
            int offset;
            try {
                offset = std::stoi(key);
                if (offset <= 0) {
                    throw BaseException("Bad offset: " + key);
                }
            } catch (...) {
                throw BaseException("Bad offset: " + key);
            }
            encoder = std::make_unique<RotEncoder>(offset);
        } else if (encoderType == "SbsEncoder") {
            encoder = std::make_unique<SbsEncoder>(key);
        } else {
            throw BaseException("Unknown encoder type: " + encoderType);
        }

        // Print the encoder type and mode
        std::cout << "Encoder Type: " << encoderType << std::endl;
        std::cout << "Mode: " << (mode == "E" ? "Encoding" :
         "Decoding") << std::endl;

        std::string line;
        while (std::getline(std::cin, line)) {
            if (mode == "E") {
                std::cout << encoder->encode(line) << std::endl;
            } else if (mode == "D") {
                std::cout << encoder->decode(line) << std::endl;
            } else {
                throw BaseException("Unknown mode: " + mode);
            }
        }
    } catch (const BaseException& ex) {
        std::cout << ex.what() << std::endl;
    }
    std::cout << "Press Enter to exit...";
    std::cin.get();

    return 0;
}
