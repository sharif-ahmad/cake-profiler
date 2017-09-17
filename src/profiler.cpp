#include <profiler.h>
#include <profilermanager.h>

namespace poc
{

Profiler::Profiler(const std::string& name, ProfilerManager& manager)
    : start(std::chrono::high_resolution_clock::now()), name(name), manager(manager)
{
}

Profiler::Profiler(std::string&& name, ProfilerManager& manager)
    : start(std::chrono::high_resolution_clock::now()), name(std::move(name)), manager(manager)
{
}

Profiler::~Profiler()
{
    end = std::chrono::high_resolution_clock::now();
    manager.addExecutionDuration(name, end - start);
}

}
