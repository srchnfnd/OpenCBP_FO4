#include <stdarg.h>
#include "log.h"

#pragma warning(disable : 4996)

// TODO make better macro
#define LOG_ON

CbpLogger::CbpLogger(const char* fname)
{
#ifdef LOG_ON
  filename = fname;
  handle = NULL; 
#endif
}

void CbpLogger::Info(const char* fmt...)
{
#ifdef LOG_ON
    if (handle)
    {
        va_list argptr;
        va_start(argptr, fmt);
        vfprintf(handle, fmt, argptr);
        va_end(argptr);
        fflush(handle);
    }
#endif
}

void CbpLogger::Error(const char* fmt...)
{
#ifdef LOG_ON
    if (handle)
    {
        va_list argptr;
        va_start(argptr, fmt);
        vfprintf(handle, fmt, argptr);
        va_end(argptr);
        fflush(handle);
    }
#endif
}

void CbpLogger::SetEnable(bool enable)
{
#ifdef LOG_ON
  if (enable)
  {
    if (!handle)
    {
      handle = fopen(filename.c_str(), "w");
      fprintf(handle, "CBP Log initialized\n");
    }
  }
  else {
    if (handle)
    {
      fprintf(handle, "CBP Log closing\n");
      fclose(handle);
      handle = NULL;
    }
  }
#endif
}

CbpLogger logger("Data\\F4SE\\Plugins\\cbp.log");
