#include "process.h"

void
process_start(void)
{
    conf_val      thread_num;
    conf_val      fds_num;
    conf_val      port;
    struct rlimit rl;
    int           socket_fd;
    int           epoll_fd;

    /*初始化配置*/
    if(conf_init() != 0) {
        printf("configure init error\n");
        exit(1);
    }

    /*开启精灵进程*/
    daemon(1,1);

    /*修改进程可操作文件最大数*/
    thread_num = conf_get_option_val("service", "thread_num");
    st_fd_num = conf_get_option_val("service", "st_fd_num");
    rl.rlim_cur = atoi(thread_num) * atoi(st_fd_num);
    rl.rlim_max = atoi(thread_num) * atoi(st_fd_num);
    setrlimit(RLIMIT_NOFILE, &rl);
    getrlimit(RLIMIT_NOFILE, &rl);

    /*创建并监听sokcet*/
    port = conf_get_option_val("service", "port");
    socket_fd = tcpopt_build_socket(port, 1);

}
