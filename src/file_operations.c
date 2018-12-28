#include "file_operations.h"

int
fopt_get_file_content(char *content, char *file_path, uint64_t len)
{
    int result = -1;
    FILE *fp = NULL;

    if((fp = fopen(file_path, "r")) == NULL) {
        return -1;    
    }

    if(fread(content, 1, len, fp) > 0) {
        result = 0;
    }

    fclose(fp);
    return result;
}

uint8_t 
fopt_set_nonblock(int fd)
{
    int flag;
    int ret;

    flag = fcntl(fd, F_GETFL, 0);
    if(flag < 0) {
        return 1;
    }
    ret = fcntl(fd, F_SETFL, flag|O_NONBLOCK);
    if(ret < 0) {
        return 1;
    }
    return 0;
}
