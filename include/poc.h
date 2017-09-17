#ifndef __POC_H__
#define __POC_H__

#include <profiler.h>
#include <profilermanager.h>

#ifdef PROFILE_ENABLED
#define PROFILE_INIT(logger) poc::ProfilerManager::getInstance().setLogger(logger);
#define PROFILE_BLOCK(name) poc::Profiler poc_profiler(name, poc::ProfilerManager::getInstance());
#define PROFILE_BLOCK_START(name) \
{\
    PROFILE_BLOCK(name)

#define PROFILE_BLOCK_END \
}

#define PROFILE_FUNCTION PROFILE_BLOCK(__FUNCTION__)
#define PROFILE_GENERATE_REPORT poc::ProfilerManager::getInstance().generateReport();
#else
#define PROFILE_INIT(logger)
#define PROFILE_BLOCK(name)
#define PROFILE_BLOCK_START(name)
#define PROFILE_BLOCK_END
#define PROFILE_FUNCTION
#define PROFILE_GENERATE_REPORT
#endif // ENABLE_PROFILE

#endif // __POC_H__

