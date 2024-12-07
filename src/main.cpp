#include <iostream>
#include <string>
#include <memory>
#include "Encoder.h"
#include "RotEncoder.h"
#include "SbsEncoder.h"

int main(int argc, char* argv[]) {
    // Validate command-line arguments
    if (argc != 4) {
        std::cerr << "Usage: " << argv[0] << " <E|D> <RotEncoder|SbsEncoder> <key>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string encoderType = argv[2];
    std::string key = argv[3];
    std::unique_ptr<Encoder> encoder;

    // Initialize the encoder based on type
    if(encoderType == "RotEncoder"){
        encoder = std::make_unique<RotEncoder>(std::stoi(key));
    } else if (encoderType == "SbsEncoder") {
        encoder = std::make_unique<SbsEncoder>(key);
    }else{
        std::cerr << "Unsupported encoder type: "<<encoderType<< std::endl;
        return 1;
    }
    
    // Print the encoder type and operation
    std::cout << "Encoder Type: " << encoderType << std::endl;
    std::cout << "Operation: " << (mode == "E" ? "Encoding" : "Decoding") << std::endl;


    std::string line;
    if (mode == "E"){
        while (std::getline(std::cin, line)) {
            std::cout << encoder->encode(line) <<std::endl;
        }
    } else if (mode == "D") {
        while (std::getline(std::cin, line)){
            std::cout << encoder->decode(line) <<std::endl;
        }
    } else {
        std::cerr << "Invalid mode: "<< mode << ". use 'E' or 'D' ."<< std::endl;
        return 1;
    }
    return 0;
}
