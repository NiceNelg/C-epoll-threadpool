#include <stdio.h>
#include "config_list.h"

int 
main()
{
    if(conf_init() != 0) {
        printf("configure init error\n");
        exit(-1);
    }
    conf_val mysql_host;
    mysql_host = conf_get_option_val("service", "host");
    printf("%s\n", mysql_host);
    nest_list *mysql_c;
    mysql_c = conf_get_options("mysql");
    printf("%s\n", ((conf_data *)mysql_c->header->data)->value);
    conf_free();
    return 0;
}
