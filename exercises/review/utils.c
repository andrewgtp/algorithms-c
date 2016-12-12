#include <stdio.h>
#include "utils.h"


const char *LINE = "----------------------------";
const char *LINE_DBL  = "=========================================";


void print_log_header_dbl(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE_DBL, msg, LINE_DBL);
}

void print_log_header(char *msg) {
    printf("\n%s\n%s\n%s\n\n", LINE, msg, LINE);
}
