/******************************************************************************
 * FileName: str_operations.h
 * Author: nicenelg@gmail.com
 * Version: v1.0
 * Date: 2018-12-19
 * Description:
 *      各种字符串的操作
 * Others:
 * Function List:
******************************************************************************/

#ifndef _STR_OPERATIONS_H_INCLUDED_
#define _STR_OPERATIONS_H_INCLUDED_

#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/******************************************************************************
 * Function name: stropt_del_chr
 * Description:
 *      删除字符串中指定的字符
 * Parameter:
 *      @char *string
 *      @char  ch
******************************************************************************/
void stropt_del_chr(char *string, char ch);

/******************************************************************************
 * Function name: stropt_mencpy
 * Description:
 *      分配新的内存空间并创建字符串，且在字符串最后会添加'\0'结束符
 * Parameter:
 *      @char **string  复制后的字符串
 *      @char  *start   需要复制的起始地址
 *      @char  *end     需要复制的结束地址
 * Return:
 *      0     success
 *      other fail
******************************************************************************/
uint8_t stropt_memcpy(char **data, char *start, char *end);

#endif
