/******************************************************************************
 * FileName: process.h
 * Author: nicenelg@gmail.com                                                          
 * Version: v1.0.0                                                             
 * Description:
 *      程序主体流程
 * Others:
 * Function List:
******************************************************************************/

#ifndef _PROCESS_H_INCLUDED_
#define _PROCESS_H_INCLUDED_

#include <stdint.h>
#include <unistd.h>
#include "config_list.h"
#include "tcp_operations.h"
#include <sys/epoll.h>

#define MAX_FDS 10240


/******************************************************************************
 * Function name: process_start
 * Description:
 *      主体流程开始
******************************************************************************/
void process_start(void);

#endif
