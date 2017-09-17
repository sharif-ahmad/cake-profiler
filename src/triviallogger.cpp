#include <triviallogger.h>
#include <iostream>
#include <string>

namespace poc
{

void TrivialLogger::log(const std::string& prefix, const std::string& msg)
{
    std::cout << "[" << prefix << "] " << msg << std::endl;
}

}

