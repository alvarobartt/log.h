#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>

#ifdef _WIN32
#    define LOG_NEWLINE "\r\n"
#else
#    define LOG_NEWLINE "\n"
#endif

typedef enum {
    LOG_LEVEL_INFO,
    LOG_LEVEL_WARN,
    LOG_LEVEL_DEBUG,
    LOG_LEVEL_ERROR
} LogLevel;

static const char* log_level_to_string(LogLevel lvl) {
    switch (lvl) {
        case LOG_LEVEL_INFO:  return "INFO";
        case LOG_LEVEL_WARN:  return "WARN";
        case LOG_LEVEL_ERROR: return "ERROR";
        case LOG_LEVEL_DEBUG: return "DEBUG";
    }
}

static inline void log_print(LogLevel lvl, const char *fmt, ...)
    __attribute__((format(printf, 2, 3)));

static inline void log_print(LogLevel lvl, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    FILE* stream = (lvl == LOG_LEVEL_ERROR) ? stderr : stdout;
    fprintf(stream, "[%s] ", log_level_to_string(lvl));
    vfprintf(stream, fmt, args);
    fputs(LOG_NEWLINE, stream);

    va_end(args);
}

#define log_info(fmt, ...)  log_print(LOG_LEVEL_INFO, fmt, ##__VA_ARGS__)
#define log_warn(fmt, ...)  log_print(LOG_LEVEL_WARN, fmt, ##__VA_ARGS__)
#define log_debug(fmt, ...) log_print(LOG_LEVEL_DEBUG, fmt, ##__VA_ARGS__)
#define log_error(fmt, ...) log_print(LOG_LEVEL_ERROR, fmt, ##__VA_ARGS__)

#endif // LOG_H
