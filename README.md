# log.h

> A simple header-only C library for logging

```c
#include "log.h"

int main(void) {
    // Goes to stdout
    log_info("An info logging message");    // [ INFO] - An info logging message
    log_warn("A warn logging message");     // [ WARN] - A warn logging message
    log_debug("A debug logging message");    // [DEBUG] - A debug logging message

    // Goes to stderr
    log_error("An error logging message");  // [ERROR] - An error logging message

    return 0;
}
```

Same with `log_{info,warn,debug,error}_with_time` to include the timestamp too.

## About `log.h`

`log.h` is a fairly simple logging library in C, to easily get started with clean
and structured logging messages, rather than relying on the standard `printf` et al.

This library does not bring anything new to the table, as is not intended to do so,
this is just a simple library that I found useful when creating new (toy) C projects,
so please bear that in mind.
