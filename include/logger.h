#ifndef __LOGGER_H__
#define __LOGGER_H__

#include <string>

namespace poc
{

class ILogger
{
public:

    virtual void log(const std::string& prefix, const std::string& msg) = 0;

    virtual ~ILogger() = default;
};

}
#endif // __LOGGER_H__

