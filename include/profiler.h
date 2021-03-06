#ifndef __PROFILER_H__
#define __PROFILER_H__
#include <string>
#include <cakedef.h>

namespace cake
{

class ProfilerManager;

class Profiler final
{
    time_point start, end;
    std::string name;

    ProfilerManager& manager;
public:
    Profiler(const std::string& name, ProfilerManager& manager);
    Profiler(std::string&& name, ProfilerManager& manager);

    ~Profiler();
};

}

#endif // __PROFILER_H__

