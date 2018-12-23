#include <stdio.h>
#include "nest_list.h"


int 
main()
{
    nest_list *list;
    nest_create_list(&list);
    nest_add_node(list, (void *)"hhh1", NULL, 1, NULL);
    nest_add_node(list, (void *)"hhh2", NULL, 1, NULL);
    nest_add_node(list, (void *)"hhh3", NULL, 1, NULL);
    nest_add_node(list, (void *)"hhh4", NULL, 1, NULL);
    nest_create_list(&(list->header->list));
    nest_add_node(list->header->list, (void *)"hhh1", NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)"hhh2", NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)"hhh3", NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)"hhh4", NULL, 1, NULL);
    nest_node *node;
    nest_node *n;
    nest_reset_cursor(list);
    while(node = nest_foreach_list(list)) {
        printf("%s\n", (char *)node->data);
        nest_reset_cursor(node->list);
        while(n = nest_foreach_list(node->list)) {
            printf("%s\n", (char *)n->data);
        }
    }
    //if(conf_init() != 0) {
    //    printf("configure init error\n");
    //    exit(-1);
    //}
    //conf_val mysql_host;
    //mysql_host = conf_get_option_val(CONF_MYSQL, CONF_MYSQL_HOST);
    //printf("%s\n", mysql_host);
    //conf_free();
    return 0;
}
