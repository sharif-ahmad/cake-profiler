#include <profiler.h>
#include <profilermanager.h>

namespace cake
{

Profiler::Profiler(const std::string& name, ProfilerManager& manager)
    : start(clock::now()), name(name), manager(manager)
{
}

Profiler::Profiler(std::string&& name, ProfilerManager& manager)
    : start(clock::now()), name(std::move(name)), manager(manager)
{
}

Profiler::~Profiler()
{
    end = clock::now();
    manager.addExecutionDuration(name, end - start);
}

}
