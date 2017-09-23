#include <profiler.h>
#include <profilermanager.h>

namespace poc
{

Profiler::Profiler(const std::string& name, ProfilerManager& manager)
    : start(clock::now()), name(name), manager(manager)
{
    manager.addCallTime(name, start);
}

Profiler::Profiler(std::string&& name, ProfilerManager& manager)
    : start(clock::now()), name(std::move(name)), manager(manager)
{
    manager.addCallTime(this->name, start);
}

Profiler::~Profiler()
{
    end = clock::now();
    manager.addExecutionDuration(name, end - start);
}

}
