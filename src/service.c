#include <stdio.h>
#include "nest_list.h"


int 
main()
{
    char *h1;
    char *h2;
    char *h3;
    char *h4;
    h1 = (char *)malloc(sizeof(char) * 4);
    h2 = (char *)malloc(sizeof(char) * 4);
    h3 = (char *)malloc(sizeof(char) * 4);
    h4 = (char *)malloc(sizeof(char) * 4);
    char *h5;
    char *h6;
    char *h7;
    char *h8;
    h5 = (char *)malloc(sizeof(char) * 4);
    h6 = (char *)malloc(sizeof(char) * 4);
    h7 = (char *)malloc(sizeof(char) * 4);
    h8 = (char *)malloc(sizeof(char) * 4);
   
    nest_list *list;
    nest_create_list(&list);
    nest_add_node(list, (void *)h1, NULL, 1, NULL);
    nest_add_node(list, (void *)h2, NULL, 1, NULL);
    nest_add_node(list, (void *)h3, NULL, 1, NULL);
    nest_add_node(list, (void *)h4, NULL, 1, NULL);
    nest_create_list(&(list->header->list));
    nest_add_node(list->header->list, (void *)h5, NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)h6, NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)h7, NULL, 1, NULL);
    nest_add_node(list->header->list, (void *)h8, NULL, 1, NULL);    
    nest_del_node(list->header->list, list->header->list->header);
    printf("%s\n", (char *)list->header->list->header->data);
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
