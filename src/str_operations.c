#include "str_operations.h"

void
stropt_del_chr(char *string, char ch)
{
    char *p = string;
    char *q = string;

    while(*q) {
        if(*q != ch) {
            *p++ = *q;
        }
        q++;
    }
    *p = '\0';
}
