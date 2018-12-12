/******************************************************************************
 *Copyright(C),2010-2011,nicenelg@gmail.com
 *FileName: file_operations.h
 *Author:nelg
 *Version:v1.0
 *Date:2018-12-11
 *Description：文件操作函数集
 *Others:
 *Function List:
******************************************************************************/

#ifndef _FILE_OPERATIONS_H_INCLUDED_
#define _FILE_OPERATIONS_H_INCLUDED_

#include <stdio.h>
#include <stdint.h>

/*文件信息结构体*/
typedef struct {
    int   fd;
    char *content;
}fopt_info;

/******************************************************************************
 *
 * Function name: fopt_get_file_content
 * Description: 初始化配置
 * Parameter:
 *   @content   文件内容
 *   @path      文件路径
 *   @len       读取长度
 * Return: 
 * 	 0      success  
 *   other  fail
******************************************************************************/
int fopt_get_file_content(char *content, char *path, uint64_t len);

#endif
