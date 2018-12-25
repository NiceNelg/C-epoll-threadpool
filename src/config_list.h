/******************************************************************************
 * Copyright(C),2018-2018,nicenelg@gmail.com
 * FileName: config_list.h
 * Author:nelg
 * Version:v1.0
 * Date:2018-12-11
 * Description: 
 *  功能：
 *      1、读取配置文件信息，将配置项放置到全局变量CONFIG中。
 * Others:
 * Function List:
 *      1、conf_init
 *      2、conf_get_option_val
 *      3、conf_get_options
 *      4、conf_free
 * Dependent:
 *      1、str_operations.h str_operations.c
 *      2、file_operations.h file_operations.c
 *      3、nest_list.h nest_list.c
******************************************************************************/

#ifndef _CONFIG_LIST_H_INCLUDED_
#define _CONFIG_LIST_H_INCLUDED_

#include "str_operations.h"
#include "file_operations.h"
#include "nest_list.h"

#define CONF_FILE "ini.ini"
#define CONF_FILE_MAX_SIZE (10 * 1024)

/*配置项值类型*/
typedef char* conf_val;
/*配置项类型*/
typedef char* conf_key;

typedef struct {
    conf_key key;
    conf_val value;
}conf_data;

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
 * Description:
 *      初始化配置
 * Return: 
 * 	    0      success  
 *      other  fail
******************************************************************************/
int conf_init(void);

/******************************************************************************
 *
 * Function name: conf_create_data
 * Description:
 *      设置一个配置配置
 * Parameter:
 *      @conf_data **data   配置数据
 *      @conf_key    key    配置键
 *      @conf_value  value  配置值
 * Return:
 *      0      success
 *      other  fail
******************************************************************************/
uint8_t conf_create_data(conf_data **data, conf_key key, conf_val value);

/******************************************************************************
 *
 * Function name: conf_free_data
 * Description:
 *      释放单个配置数据
 * Parameter:
 *      @conf_data **data   配置数据
 * Return:
 *      0      success
 *      other  fail
******************************************************************************/
void conf_free_data(void **data);

/******************************************************************************
 *
 * Function name: conf_get_option_val
 * Description:
 *      获取子级配置的值
 * Parameter:     
 *      @conf_key config     顶级配置项
 *      @conf_key options    子级配置项
 * Return:
 *      char_val   指针地址
 *      NULL       fail
******************************************************************************/
conf_val conf_get_option_val(conf_key config, conf_key options);

/******************************************************************************
 *
 * Function name: conf_get_options
 * Description:
 *      获取对应顶级配置的所有子级配置项
 * Parameter:
 *      @conf_key config    顶级配置项
 * Return:
 *      nest_lisit   链表地址
 *      NULL         fail
******************************************************************************/
nest_list *conf_get_options(conf_key config);

/******************************************************************************
 *
 * Function name: conf_free
 * Description:
 *      释放配置内存
******************************************************************************/
void conf_free(void);

#endif
