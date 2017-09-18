
#include <algorithm>
#include <string>
#include <profilermanager.h>
#include <logger.h>
#include <triviallogger.h>

namespace poc
{

ProfilerManager::ProfilerManager(std::shared_ptr<Logger> pLogger)
    : pLogger(pLogger)
{

}

ProfilerManager::~ProfilerManager()
{
    generateReport();
}

ProfilerManager& ProfilerManager::getInstance()
{
    static ProfilerManager profilerManager(std::make_shared<TrivialLogger>());
    return profilerManager;
}

void ProfilerManager::setLogger(std::shared_ptr<Logger> logger)
{
    pLogger = logger;
}

void ProfilerManager::addExecutionDuration(const std::string& name, duration duration)
{
    auto& tracker = durationTrackerMap[name];

    tracker.min = std::min(tracker.min, duration);
    tracker.max = std::max(tracker.max, duration);
    tracker.sum += duration;
    tracker.count++;
}

void ProfilerManager::generateReport() const
{
    auto reportFromTracker = [](const ExecutionDurationTracker& tracker)
    {
        using std::chrono::duration_cast;

        std::string ret = std::string(" min: ") + std::to_string(duration_cast<time_unit> (tracker.min).count())
            + std::string(" max: ") + std::to_string(duration_cast<time_unit> (tracker.max).count())
            + std::string(" average: ") + std::to_string(duration_cast<time_unit>(tracker.sum).count()/static_cast<double>(tracker.count))
            + std::string(" run count: ") + std::to_string(tracker.count);

        return ret;
    };

    for(const auto& p : durationTrackerMap)
    {
        const auto& name = p.first;
        const auto& tracker = p.second;

        pLogger->log(name, reportFromTracker(tracker));
    }
}

}
