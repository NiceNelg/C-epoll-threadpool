#include "process.h"

void
process_start(void)
{
    conf_val port;
    int      socket_fd;
    int      epoll_fd;

    /*初始化配置*/
    if(conf_init() != 0) {
        printf("configure init error\n");
        exit(1);
    }

    /*开启精灵进程*/
    daemon(1,1);

    /*创建并监听sokcet*/
    port = conf_get_option_val("service", "port");
    socket_fd = tcpopt_build_socket(port, 1);

    /*创建epoll句柄*/
    epoll_fd = epoll_create();
}
