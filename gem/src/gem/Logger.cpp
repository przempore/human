#include "gem/Logger.hpp"

#include <windows.h>

namespace Gem
{
    void Logger::Log(const char* message, Level level)
    {
        if (level <= m_threshold)
        {
            OutputDebugStringA(message);
        }
    }

    void Logger::Log(const std::string& message, Level level)
    {
        if (level <= m_threshold)
        {
            OutputDebugStringA(message.c_str());
        }
    }
}
