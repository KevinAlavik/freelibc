#include "utils.h"

extern char* test();

void _start() {
    puts(test());
    for(;;);
}