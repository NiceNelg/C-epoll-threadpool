/******************************************************************************
 * Copyright(C),2010-2011,nicenelg@gmail.com
 * FileName: config_array.h
 * Author:nelg
 * Version:v1.0
 * Date:2018-12-11
 * Description: 
 *  功能：
 *      1、读取配置文件信息，将配置项放置到全局变量CONFIG中。
 *  缺点：
 *      1、很多
 *      2、需要重定义各配置项的枚举值、最大数以及配置项的索引信息。
 *      3、当读取的配置信息不存在时，会因指针操作越界导致程序崩溃，因此规定了
 *         配置文件的信息一定要完整定义及填写。
 *  优点：
 *      1、读取配置信息时以数组形式读取，较快速。适用于读取配置信息频繁的程序。
 * Others:
 * Function List:
 *      1、conf_init
 *      2、conf_get_option_val
 *      3、conf_get_options
 *      4、conf_free
 * Dependent:
 *      1、str_operations.h str_operations.c
 *      2、file_operations.h file_operations.c
******************************************************************************/

#ifndef _CONFIG_ARRAY_H_INCLUDED_
#define _CONFIG_ARRAY_H_INCLUDED_

#include "str_operations.h"
#include "file_operations.h"

#define CONF_FILE "ini.ini"
#define CONF_FILE_MAX_SIZE (10 * 1024)
#define CONF_TOP_OPTIONS_MAX 3
#define CONF_OPTIONS_MAX 5

/*配置项下标类型*/
typedef int conf_opt;
/*配置项值类型*/
typedef char* conf_val;
/*配置项类型*/
typedef char** conf_options;

/*顶级配置项*/
static enum {
    CONF_SERVICE = 0,
    CONF_MYSQL,
    CONF_REDIS
}CONF_OPTIONS;

/*服务配置项*/
static enum {
    CONF_SERVICE_HOST = 0,
    CONF_SERVICE_PORT,
    CONF_SERVICE_THREAD_NUM,
    CONF_SERVICE_EPOLL_NUM
}CONF_SERVICE_OPTIONS;

/*Mysql配置项*/
static enum {
    CONF_MYSQL_HOST = 0,
    CONF_MYSQL_PORT,
    CONF_MYSQL_PWD
}CONF_MYSQL_OPTIONS;

/*Redis配置项*/
static enum {
    CONF_REDIS_HOST = 0,
    CONF_REDIS_PORT,
    CONF_REDIS_PWD,
    CONF_FD_ID_DB,
    CONF_ID_FD_DB
}CONF_REDIS_OPTIONS;

/*顶级配置项索引表*/
static char *_CONF_OPTIONS[CONF_TOP_OPTIONS_MAX] = {
    "service",
    "mysql",
    "redis"
};

/*子级配置索引表*/
static char *_CONF_OPTIONS_VAL[CONF_TOP_OPTIONS_MAX][CONF_OPTIONS_MAX] = {
    {"host", "port", "thread_num", "epoll_num"},
    {"host", "port", "pwd"},
    {"host", "port", "pwd", "fd_id_db", "id_fd_db"}
};

/*指针偏移一位操作*/
#define conf_point_offset(p, m_end) (p==m_end) ? p : p+1;
/*指针释放*/
#define conf_point_free(p) do{                                                \
    free(p);                                                                  \
    p = NULL;                                                                 \
}while(0)

/******************************************************************************
 *
 * Function name: conf_init
 * Description: 初始化配置
 * Return: 
 * 	 0      success  
 *   other  fail
******************************************************************************/
int conf_init();

/******************************************************************************
 *
 * Function name: conf_get_option_val
 * Description: 获取子级配置的值
 * Parameter:
 *   @val       配置项的值         
 *   @config    顶级配置项
 *   @option    子级配置项
 * Return:
 *   char_val   指针地址
 *   NULL       失败
******************************************************************************/
conf_val conf_get_option_val(conf_opt config, conf_opt options);

/******************************************************************************
 *
 * Function name: conf_get_options
 * Description: 获取对应顶级配置的所有子级配置项
 * Parameter:
 *   @val       配置项的值         
 *   @config    顶级配置项
 * Return:
 *   char_options   指针地址
 *   NULL           失败
******************************************************************************/
conf_options conf_get_options(conf_opt config);

/******************************************************************************
 *
 * Function name: conf_free
 * Description: 释放配置内存
******************************************************************************/
void conf_free();

#endif
