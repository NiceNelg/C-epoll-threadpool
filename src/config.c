/******************************************************************************
 *Copyright(C),2010-2011,nicenelg@gmail.com
 *FileName: config.h
 *Author:nelg
 *Version:v1.0
 *Date:2018-12-11
 *Description: get config info
 *Others:
 *Function List:
******************************************************************************/

#include "config.h"

/*所有配置信息*/
static int *CONFIG;

int 
conf_init(void)
{
    int result = -1;
    char *conf_file_buff = NULL;

    /*获取内存空间放置配置文件信息*/
    conf_file_buff = (char *)malloc(CONF_FILE_MAX_SIZE);
    if(conf_file_buff == NULL) {
        /*内存分配错误*/
        return result;
    }
    bzero(conf_file_buff, CONF_FILE_MAX_SIZE);

    /*读取文件内容，放置到内存中*/
    result = fopt_get_file_content(conf_file_buff, CONF_FILE, 
                (uint64_t)CONF_FILE_MAX_SIZE);
    if(result != 0) {
        /*读取文件错误*/
        goto CONF_INIT_EXIT;
        return result;
    }
    printf("%s\n", conf_file_buff);
    while(*conf_file_buff != EOF) {
        strstr();
    }

CONF_INIT_EXIT:
    free(conf_file_buff);
    conf_file_buff = NULL;
    return result;
}

int
conf_get_option_val(conf_val val, conf_opt config, conf_opt options)
{
    //*val = CONFIG[config][options];
    return 0;
}
