#include "nest_list.h"

uint8_t
nest_create_list(nest_list **list)
{
    *list = (nest_list *)malloc(sizeof(nest_list));
    if(*list == NULL) {
        return 1;
    }
    (*list)->header = NULL;
    (*list)->last = NULL;
    (*list)->cursor = NULL;
    (*list)->length = 0;
    return 0;
}

uint8_t
nest_add_node(nest *list, void *data, nest_free_node *function, 
            uint8_t direction, nest_node *postion)
{
    nest_node *node = NULL;
    nest_node *pos  = NULL;

    if(postion == NULL) {
        pos = list->last;
    } else {
        pos = postion;
    }

    /*创建节点*/
    node = (nest_node *)malloc(sizeof(nest_node));
    if(node == NULL) {
        return 1;
    }
    node->prev = NULL;
    node->next = NULL;
    node->nest_list = NULL;
    node->data = data;
    node->free_data = function;

    /*链表无节点*/
    if(list->header == NULL) {
       list->header = node;
       list->last = node;   
       list->length++;
       list->cursor = node;
       return 0;
    }
    
    if(direction == 0) {
        /*向前插入节点*/
        if(postion == list->header) {
            node->next = list->header;
            list->header->prev = node;
            list->header = postion;
        } else {
            node->prev = pos->prev;
            node->next = pos;
            pos->prev = node;
        }
    } else {
        /*向后插入节点*/
        node->prev = pos;
        node->next = pos->next;
        if(pos->next != NULL) {
            pos->next->prev = node;
        }
        pos->next = node;
        if(list->last == pos) {
            list->last = node;
        }
    }    
    list->length++;
    list->cursor = node;
    return 0;
}

uint8_t
nest_del_node(nest_list *list, nest_node *node)
{
    if(node == NULL) {
        return 1;
    }
    if(node->nest_free_node != NULL) {
        nest_free_node(node->data);
    } else {
        free(node->data);
    }
    list->cursor = node->next;
    if(list->header == node) {
        list->header = node->next;
    }
    if(list->last == node) {
        list->last = node->prev;
    }
    list->length--;
    
    if(node->prev != NULL) {
        node->prev->next = node->next;
    }
    if(node->next != NULL) {
        node->next->prev = node->prev;
    }
    node->prev = NULL;
    node->next = NULL;

    /*递归销毁子链表*/
    if(node->nest_list != NULL) {
        nest_destroy_list(node->nest_list);
    }
    free(node);
    node = NULL;
    return 0;
}

void 
nest_reset_cursor(nest_list *list)
{
    list->cursor = list->header;
}

nest_node *
nest_foreach_list(nest_list *list)
{
    nest_node *node;

    node = list->cursor;
    if(list->cursor != NULL) {
        list->cursor = list->cursor->next;
    }
    return node;
}

uint8_t
nest_destory_list(nest_list *list)
{
    nest_node *node;
    nest_reset_cursor(list);
    while(node = nest_foreach_list(list)) {
        nest_del_node(node);
    }
    return 0;
}
