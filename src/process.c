#include "process.h"

void
process_start(void)
{
    /*初始化配置*/
    if(conf_init() != 0) {
        printf("configure init error\n");
        exit(1);
    }

    /*开启精灵进程*/
    daemon(1,1);
}
