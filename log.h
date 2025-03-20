#ifndef LOG_H
#define LOG_H

#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <time.h>

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

static inline void log_print(LogLevel lvl, bool tm, const char *fmt, ...)
    __attribute__((format(printf, 3, 4)));

static inline void log_print(LogLevel lvl, bool tm, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);

    FILE* stream = (lvl == LOG_LEVEL_ERROR) ? stderr : stdout;
    fprintf(stream, "[%5s] - ", log_level_to_string(lvl));

    if (tm == true) {
        time_t current_time;
        struct tm *time_info;
        char time_string[20];

        time(&current_time);
        time_info = localtime(&current_time);
        strftime(time_string, sizeof(time_string), "%Y-%m-%d %H:%M:%S", time_info);
        fprintf(stream, "%19s - ", time_string);
    }

    vfprintf(stream, fmt, args);
    fputs(LOG_NEWLINE, stream);

    va_end(args);
}

#define log_info(fmt, ...)  log_print(LOG_LEVEL_INFO, false, fmt, ##__VA_ARGS__)
#define log_info_with_time(fmt, ...)  log_print(LOG_LEVEL_INFO, true, fmt, ##__VA_ARGS__)

#define log_warn(fmt, ...)  log_print(LOG_LEVEL_WARN, false, fmt, ##__VA_ARGS__)
#define log_warn_with_time(fmt, ...)  log_print(LOG_LEVEL_WARN, true, fmt, ##__VA_ARGS__)

#define log_debug(fmt, ...) log_print(LOG_LEVEL_DEBUG, false, fmt, ##__VA_ARGS__)
#define log_debug_with_time(fmt, ...) log_print(LOG_LEVEL_DEBUG, true, fmt, ##__VA_ARGS__)

#define log_error(fmt, ...) log_print(LOG_LEVEL_ERROR, false, fmt, ##__VA_ARGS__)
#define log_error_with_time(fmt, ...) log_print(LOG_LEVEL_ERROR, true, fmt, ##__VA_ARGS__)

#endif // LOG_H
