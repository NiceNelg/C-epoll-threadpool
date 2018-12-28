/****************************************************************************** 
 * FileName: tcp_operations
 * Author: nicenelg@gmail.com
 * Version: v1.0.0
 * Date: 2018-12-26
 * Description:
 *      TCP���ò���
 * Function List:
******************************************************************************/
#ifndef _TCP_OPERATIONS_H_INCLUDED_
#define _TCP_OPERATIONS_H_INCLUDED_

#include "file_operations.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/socket.h>
#include <netinet/in.h>

/******************************************************************************
 * Function name: tcpopt_build_socket
 * Description:
 *      ����TCP����
 * Parameter:
 *      @char    *port_s    �˿ں�
 *      @uint8_t  is_block  �Ƿ�Ϊ����ʽ��0��1��
 * Return:
 *      fd  success��socket�������
 *      -1  fail
******************************************************************************/
int tcpopt_build_socket(char *port_s, uint8_t is_block);

#endif
