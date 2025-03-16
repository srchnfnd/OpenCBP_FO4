#pragma once
#include <stdio.h>
#include <shared_mutex>

class CbpLogger
{
  bool enabled;
public:
    CbpLogger(const char* fname);
    void Info(const char* args...);
    void Error(const char* args...);
    void SetEnable(bool enable);
    FILE* handle;
    std::string filename;
    std::shared_mutex log_lock;
};

extern CbpLogger logger;