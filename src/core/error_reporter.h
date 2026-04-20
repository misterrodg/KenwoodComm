#ifndef ERROR_REPORTER_H
#define ERROR_REPORTER_H

#include "result.h"

#include <iostream>

inline void printError(const core::Error& err) {
    std::cerr << "[ERROR][" << err.code << "] " << err.message << std::endl;
}

#endif
