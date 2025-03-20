# log.h

> A simple header-only C library for logging

```c
#include "log.h"

int main(void) {
    // Goes to stdout
    log_info("An info logging message");  // [INFO] An info logging message
    log_warn("A warn logging message");  // [WARN] A warn logging message
    log_info("A debug logging message");  // [DEBUG] A debug logging message

    // Goes to stderr
    log_error("An error logging message");  // [ERROR] An error logging message

    return 0;
}
```
