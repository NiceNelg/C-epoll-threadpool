#include "tcp_operations.h"

int
tcpopt_build_socket(char *port_s, uint8_t is_block)
{
    int port;
    int fd;

    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    port = atoi(port_s);
    /*创建socket句柄*/
    fd = socket(AF_INET, SOCK_STREAM, 0);
    if(fd < 0) {
        return -1;
    }
    /*将文件句柄设置成非阻塞式*/
    if(is_block && fopt_set_nonblock(fd)) {
        return -1;
    }

    bzero(&server_addr, sizeof(server_addr));
    /*初始化服务器端的套接字，并用htons和htonl将端口和地址转成网络字节序*/
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    /*绑定端口*/
    if(bind(fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        return -1;
    }
    /*监听端口*/
    if(listen(fd, 5) < 0) {
        return -1
    }
    return fd;
}
