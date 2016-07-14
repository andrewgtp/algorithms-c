#include <stdio.h>

const char *LINE = "----------------------------";

void print_log_header(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE, msg, LINE);
}


