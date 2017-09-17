#ifndef __TRIVIALLOGGER_H__
#define __TRIVIALLOGGER_H__

#include <logger.h>
#include <string>

namespace poc
{

class TrivialLogger : public Logger
{
public:
    void log(const std::string& prefix, const std::string& msg) override;
    ~TrivialLogger() override = default;
};

}
#endif // __TRIVIALLOGGER_H__

