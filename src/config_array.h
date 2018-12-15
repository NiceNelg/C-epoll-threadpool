/******************************************************************************
 *Copyright(C),2010-2011,nicenelg@gmail.com
 *FileName: config_array.h
 *Author:nelg
 *Version:v1.0
 *Date:2018-12-11
 *Description: 获取配置文件
 *Others:
 *Function List:
******************************************************************************/

#ifndef _CONFIG_ARRAY_H_INCLUDED_
#define _CONFIG_ARRAY_H_INCLUDED_

#include <stdlib.h>
#include <string.h>
#include "file_operations.h"

#define CONF_FILE "ini.ini"
#define CONF_FILE_MAX_SIZE (10 * 1024)

/*配置项类型*/
typedef int conf_opt;
/*配置项值类型*/
typedef char* conf_val; 

#define CONF_TOP_OPTIONS_MAX 3
#define CONF_OPTIONS_MAX 5

/*顶级配置项*/
static enum {
    CONF_SERVICE,
    CONF_MYSQL,
    CONF_REDIS
}CONF_OPTIONS;

/*服务配置项*/
static enum {
    CONF_SERVICE_HOST,
    CONF_SERVICE_PORT,
    CONF_SERVICE_THREAD_NUM,
    CONF_SERVICE_EPOLL_NUM
}CONF_SERVICE_OPTIONS;

/*Mysql配置项*/
static enum {
    CONF_MYSQL_HOST,
    CONF_MYSQL_PORT,
    CONF_MYSQL_PWD
}CONF_MYSQL_OPTIONS;

/*Redis配置项*/
static enum {
    CONF_REDIS_HOST,
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
 * 	 0      success  
 *   other  fail
******************************************************************************/
int conf_get_option_val(conf_val val, conf_opt config, conf_opt options);

/******************************************************************************
 *
 * Function name: conf_get_options
 * Description: 获取对应顶级配置的所有子级配置项
 * Parameter:
 *   @val       配置项的值         
 *   @config    顶级配置项
 * Return: 
 * 	 0      success  
 *   other  fail
******************************************************************************/
int conf_get_options(conf_val val, conf_opt config);


#endif
