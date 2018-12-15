/******************************************************************************
 *Copyright(C),2010-2011,nicenelg@gmail.com
 *FileName: config_array.h
 *Author:nelg
 *Version:v1.0
 *Date:2018-12-11
 *Description: get config info
 *Others:
 *Function List:
******************************************************************************/

#include "config_array.h"

/*所有配置信息*/
static char ***CONFIG;

int 
conf_init(void)
{
    int   result = -1;
    char *conf_file_buff = NULL;
    int   file_length = 0;
    char *p = NULL;
    char *row = NULL;
    char *r_end = NULL;
    int   rl = 0;
    char *sign = NULL;
    char *s_start = NULL;
    char *s_end = NULL;
    int   i = 0;

    /*初始化配置信息全局变量*/
    CONFIG = (char ***)malloc(CONF_TOP_OPTIONS_MAX * sizeof(char **));

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
    }
    p = conf_file_buff;
    file_length = strlen(conf_file_buff);

    while(*conf_file_buff != EOF) {
        r_end = strstr(conf_file_buff, "\n");
        if(r_end == NULL) {
            r_end = p+file_length;        
        }
        if(r_end == NULL) {
            break;
        }
        rl = r_end - conf_file_buff;
        row = (char *)malloc((r_end - conf_file_buff ) * sizeof(char));
        memcpy(row, conf_file_buff, rl);
        s_end = strstr(row, "\n");
        if(!((s_start = strstr(row, "[")) && (s_end = strstr(row, "]")))) {
            free(row);
            row = NULL;
            continue;
        }
        sign = (char *)malloc((s_end-s_start-1) * sizeof(char));
        memcpy(sign, s_start+1, s_end -s_start-1);
        for(i=0;i<CONF_TOP_OPTIONS_MAX;i++) {
           if(strcmp(_CONF_OPTIONS[i],sign) == 0) {
               if(strstr(_CONF_OPTIONS[i], "\0") != NULL) {
                   printf("%s\n", _CONF_OPTIONS[i]);
               }
                  
           }
        }
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
