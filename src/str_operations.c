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

uint8_t
stropt_memcpy(char **string, char *start, char *end)
{
    int length;
    if(*end == '\0') {
        length = end - start + 1;
    } else {
        length = end - start + 2;
    }
    *string = (char *)malloc(sizeof(char) * length);
    if(*string == NULL) {
        return 1;
    }
    memcpy(*string, start, length);
    (*string)[length-1] = '\0';
    return 0;
}
