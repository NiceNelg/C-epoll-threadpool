/******************************************************************************
 * FileName: nest_list.h
 * Author: nicenelg@gmail.com
 * Version: v1.0.0
 * Date: 2018-12-21
 * Description:
 *      嵌套式链表
 * Function List: 
******************************************************************************/
#ifndef _NEST_LIST_H_INCLUDED_
#define _NEST_LIST_H_INCLUDED_

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

typedef struct nest_nd nest_node;
typedef struct nest_ls nest_list;

typedef void (*nest_free_data)(void **data);

/*链表节点*/
struct nest_nd{
    nest_node        *prev;
    nest_node        *next;
    nest_list        *list;
    void             *data;
    nest_free_data    free_data;
};

/*链表结构*/
struct nest_ls{
    nest_node *header;
    nest_node *last;
    nest_node *cursor;
    size_t     length;
};

/******************************************************************************
 * Function name: nest_create_list
 * Description:
 *      创建链表
 * Parameter:
 *   @nest_list **list
 * Return:
 * 	 0 success
 *   other fail
******************************************************************************/
uint8_t nest_create_list(nest_list **list);

/******************************************************************************
 * Function name: nest_add_node
 * Description:
 *      添加节点，默认对链表最后的节点操作，可指定节点
 * Parameter:
 *   @nest_list      *list
 *   @void           *data
 *   @nest_free_node *function
 *   @uint8_t         direction 方向 0向前 1向后
 *   @nest_node      *postion
 * Return:
 * 	 0 success
 *   other fail
******************************************************************************/
uint8_t nest_add_node(nest_list *list, void *data, nest_free_data function, 
            uint8_t direction, nest_node *postion);

/******************************************************************************
 * Function name: nest_find_node
 * Description:
 *      根据data的地址在指定链表查找节点位置
 * Parameter:
 *   @nest_list      *list
 *   @void           *data
 * Return:
 * 	 node success
 *   NULL fail
******************************************************************************/
nest_node *nest_find_node(nest_list *list, void *data);


/******************************************************************************
 * Function name: nest_del_node
 * Description:
 *      删除指定节点
 * Parameter:
 *   @nest_list *list
 *   @nest_node *node
 * Return:
 * 	 0 success
 *   other fail
******************************************************************************/
uint8_t nest_del_node(nest_list *list, nest_node *node);

/******************************************************************************
 * Function name: nest_reset_cursor
 * Description:
 *      重置链表游标
 * Parameter:
 *   @nest_list *list
 * Return:
 * 	 @nest_node *node
******************************************************************************/
void nest_reset_cursor(nest_list *list);

/******************************************************************************
 * Function name: nest_foreach_list
 * Description:
 *      从游标下一位开始，遍历链表（为兼容多线程程序，暂无递归式遍历链表方法）
 * Parameter:
 *   @nest_list *list
 * Return:
 * 	 @nest_node *node
******************************************************************************/
nest_node *nest_foreach_list(nest_list *list);

/******************************************************************************
 * Function name: nest_destroy_list
 * Description:
 *      销毁链表
 * Parameter:
 *   @nest_list *list
 * Return:
 * 	 0 success
 *   other fail
******************************************************************************/
uint8_t nest_destroy_list(nest_list *list);

#endif
