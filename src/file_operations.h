/******************************************************************************
 * FileName: file_operations.h
 * Author: nicenelg@gmail.com
 * Version: v1.0
 * Date: 2018-12-11
 * Description:
 *      �ļ�����������
 * Others:
 * Function List:
******************************************************************************/

#ifndef _FILE_OPERATIONS_H_INCLUDED_
#define _FILE_OPERATIONS_H_INCLUDED_

#include <stdio.h>
#include <stdint.h>
#include <fcntl.h>

/*�ļ���Ϣ�ṹ��*/
typedef struct {
    int   fd;
    char *content;
}fopt_info;

/******************************************************************************
 * Function name: fopt_get_file_content
 * Description: ��ʼ������
 * Parameter:
 *   @content   �ļ�����
 *   @path      �ļ�·��
 *   @len       ��ȡ����
 * Return: 
 * 	 0      success  
 *   other  fail
******************************************************************************/
int fopt_get_file_content(char *content, char *path, uint64_t len);

/******************************************************************************
 * Function name: fopt_set_nonblock
 * Description:
 *      ���ļ�������óɷ�������ʽ
 * Parameter:
 *      @int fd �ļ����
 * Return: 
 * 	 0      success  
 *   other  fail
******************************************************************************/
uint8_t fopt_set_nonblock(int fd);

#endif
