#ifndef MYLIB_H
#define MYLIB_H

#include <string>
#include <stdexcept>

class BaseException : public std::exception {
private:
    std::string message;

public:
    explicit BaseException(const std::string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

#endif
