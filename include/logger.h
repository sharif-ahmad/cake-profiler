#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

namespace poc
{

class Logger
{
public:

    virtual void log(const std::string& prefix, const std::string& msg) = 0;

    virtual ~Logger() = default;
};

}
#endif // __LOGGER_H__

