#include <iostream>
#include <string>
#include <cstdlib>
#include "RotEncoder.h"
#include "SbsEncoder.h"

int main(int argc, char* argv[]) {
    // Validate command-line arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <E|D> <RotEncoder|SbsEncoder> <key>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string encoder = argv[2];
    std::string key = argv[3];

    // Determine the operation (Encode/Decode)
    bool isEncoding = mode == "E";
    if (!isEncoding && mode != "D") {
        std::cerr << "Invalid mode: " << mode << ". Use 'E' or 'D'." << std::endl;
        return 1;
    }

    // Print the encoder type and operation
    std::cout << "Encoder Type: " << encoder << std::endl;
    std::cout << "Operation: " << (isEncoding ? "Encoding" : "Decoding") << std::endl;
    std::string input, output;

    // Process each line of input
    while (std::getline(std::cin, input)) {
        if (encoder == "RotEncoder") {
            output = isEncoding ? RotEncoder::encode(input, std::stoi(key)) : RotEncoder::decode(input, std::stoi(key));
        } else if (encoder == "SbsEncoder") {
            output = isEncoding ? SbsEncoder::encode(input, key) : SbsEncoder::decode(input, key);
        } else {
            std::cerr << "Unsupported encoder: " << encoder << std::endl;
            return 1;
        }
        std::cout << output << std::endl;
    }

    return 0;
}
