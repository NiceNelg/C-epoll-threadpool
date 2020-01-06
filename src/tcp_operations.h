/****************************************************************************** 
 * FileName: tcp_operations                                                     
 * Author: nicenelg@gmail.com                                                   
 * Version: v1.0.0                                                              
 * Date: 2018-12-26                                                             
 * Description:                                                                 
 *      TCP常用操作                                                             
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
 *      建立TCP连接                                                             
 * Parameter:                                                                   
 *      @char    *port_s    端口号                                              
 *      @uint8_t  is_block  是否为阻塞式，0否，1是                              
 * Return:                                                                      
 *      fd  success，socket操作句柄                                             
 *      -1  fail                                                                
******************************************************************************/ 
int tcpopt_build_socket(char *port_s, uint8_t is_block);                        
                                                                                
#endif