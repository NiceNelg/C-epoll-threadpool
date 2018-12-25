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
    mysql_host = conf_get_option_val("mysql", "port");
    printf("%s\n", mysql_host);
    //conf_free();
    return 0;
}
