/******************************************************************************
 * FileName: str_operations.h
 * Author: nicenelg@gmail.com
 * Version: v1.0
 * Date: 2018-12-19
 * Description:
 *      �����ַ����Ĳ���
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
 *      ɾ���ַ�����ָ�����ַ�
 * Parameter:
 *      @char *string
 *      @char  ch
******************************************************************************/
void stropt_del_chr(char *string, char ch);

/******************************************************************************
 * Function name: stropt_mencpy
 * Description:
 *      �����µ��ڴ�ռ䲢�����ַ����������ַ����������'\0'������
 * Parameter:
 *      @char **string  ���ƺ���ַ���
 *      @char  *start   ��Ҫ���Ƶ���ʼ��ַ
 *      @char  *end     ��Ҫ���ƵĽ�����ַ
 * Return:
 *      0     success
 *      other fail
******************************************************************************/
uint8_t stropt_memcpy(char **data, char *start, char *end);

#endif
