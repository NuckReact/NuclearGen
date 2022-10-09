#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>

namespace NG
{
    class Log
    {
    public:
        static void Init();

        static Ref<spdlog::logger>& GetLogger() { return Logger; }

    private:

        static Ref<spdlog::logger> Logger;
    };
}

#define NG_TRACE(...)      ::NG::Log::GetLogger()->trace(__VA_ARGS__)
#define NG_INFO(...)       ::NG::Log::GetLogger()->info(__VA_ARGS__)
#define NG_WARN(...)       ::NG::Log::GetLogger()->warn(__VA_ARGS__)
#define NG_ERROR(...)      ::NG::Log::GetLogger()->error(__VA_ARGS__)
#define NG_CRITICAL(...)   ::NG::Log::GetLogger()->critical(__VA_ARGS__)