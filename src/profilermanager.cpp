
#include <algorithm>
#include <string>
#include <profilermanager.h>
#include <logger.h>
#include <triviallogger.h>

#ifdef __ANDROID__

#include <sstream>

namespace std
{

template <class T>
std::string to_string(T n)
{
    std::stringstream ss;
    ss << n;

    return ss.str();
}

}

#endif //__ANDROID__

namespace cake
{

ProfilerManager::ProfilerManager(std::shared_ptr<ILogger> pLogger)
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

void ProfilerManager::setLogger(std::shared_ptr<ILogger> logger)
{
    pLogger = logger;
}

void ProfilerManager::addExecutionDuration(const std::string& name, duration duration)
{
    std::lock_guard<std::mutex> durationTrackerLock(durationTrackerMutex);

    auto& tracker = execDurationTrackerMap[name];
    tracker.update(duration);
}

void ProfilerManager::addCallTime(const std::string& name, const clock::time_point& time)
{
    auto iter = callFrequencyTrackerMap.find(name);
    if (iter != callFrequencyTrackerMap.end())
    {
        auto& prevTime = iter->second.prevCallTime;
        auto& tracker = iter->second.durationTracker;

        tracker.update(time - prevTime);
    }

    callFrequencyTrackerMap[name].prevCallTime = time;
}

void ProfilerManager::generateReport() const
{
    auto reportFromTracker = [](const DurationTracker& tracker)
    {
        using std::chrono::duration_cast;

        std::string ret = std::string(" min: ") + std::to_string(duration_cast<time_unit> (tracker.min).count())
            + std::string(" max: ") + std::to_string(duration_cast<time_unit> (tracker.max).count())
            + std::string(" average: ") + std::to_string(duration_cast<time_unit>(tracker.sum).count()/static_cast<double>(tracker.count))
            + std::string(" run count: ") + std::to_string(tracker.count);

        return ret;
    };

    pLogger->log("Tracker", "Execution duration");

    {
        std::lock_guard<std::mutex> durationTrackerLock(durationTrackerMutex);

        for (const auto& p : execDurationTrackerMap)
        {
            const auto& name = p.first;
            const auto& tracker = p.second;

            pLogger->log(name, reportFromTracker(tracker));
        }
    }

    pLogger->log("Tracker", "Call frequency duration");
    
    for(const auto& p : callFrequencyTrackerMap)
    {
        const auto& name = p.first;
        const auto& tracker = p.second.durationTracker;

        if(tracker.count)
        {
            pLogger->log(name, reportFromTracker(tracker));
        }
        else
        {
            pLogger->log(name, "Call count was not enough to measure frequency.");
        }
    }
}

void ProfilerManager::DurationTracker::update(const duration& duration)
{
    min = std::min(min, duration);
    max = std::max(max, duration);
    sum += duration;
    count++;
}

}
