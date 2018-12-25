#include "config_list.h"

/*所有配置信息*/
static nest_list *_CONFIG;

int 
conf_init(/*void*/)
{
    uint8_t    result = 1;
    char      *conf_file_buff = NULL;
    char      *file_end = NULL;
    char      *reset = NULL;
    char      *row = NULL;
    char      *r_end = NULL;
    char      *sign = NULL;
    char      *s_start = NULL;
    char      *s_end = NULL;
    uint8_t    go_on = 0;
    nest_node *cursor = NULL;
    conf_data *data = NULL;
    nest_node *option = NULL;
    conf_val   option_val = NULL;

    /*初始化配置信息全局变量*/
    result = nest_create_list(&_CONFIG);
    if(result) {
        return result;
    }

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
    
    if(result) {
        /*读取文件错误*/
        goto CONF_INIT_EXIT;
    }
    reset = conf_file_buff;
    /*获取文本结束地址*/
    file_end = conf_file_buff + (strlen(conf_file_buff)- 1);
    /*单行读取*/
    while(conf_file_buff != file_end) {
        go_on = 0;
        r_end = strstr(conf_file_buff, "\n");
        if(r_end == NULL) {
            break;
        }
        /*复制当前行*/
        stropt_memcpy(&row, conf_file_buff, (r_end-1));
        /*指针偏移*/
        conf_file_buff = conf_point_offset(r_end, file_end);
        /*判断标志位*/
        if(row[0] == ';') {
            go_on = 1;
        }else if(!((s_start = strstr(row, "[")) && (s_end = strstr(row, "]")))){
            go_on = 1;
        }
        if(conf_file_buff == file_end) {
            conf_point_free(row);
            break;
        }
        if(go_on) {
            conf_point_free(row);
            continue;
        }

        /*获取标志位*/
        stropt_memcpy(&sign, (s_start+1), (s_end-1));        
        conf_point_free(row);
        /*记录标志位*/
        nest_reset_cursor(_CONFIG);
        while(cursor = nest_foreach_list(_CONFIG)) {
            if(strcmp(((conf_data *)cursor->data)->key, sign) == 0) {
                break;
            }
        }
        if(cursor == NULL) {
            result = conf_create_data(&data, sign, NULL);
            if(result) {
                nest_destroy_list(_CONFIG);
                conf_point_free(sign);
                goto CONF_INIT_EXIT;
            }
            result = nest_add_node(_CONFIG, (void *)data, NULL, 1, NULL);
            if(result) {
                nest_destroy_list(_CONFIG);
                conf_point_free(sign);
                goto CONF_INIT_EXIT;
            }
            /*查找节点*/
            cursor = nest_find_node(_CONFIG, (void *)data);
            data = NULL;
            sign = NULL;
        } else {
            conf_point_free(sign);
        }

        /*读取配置*/
        while(conf_file_buff != file_end) {
            go_on = 0;
            r_end = strstr(conf_file_buff, "\n");
            if(r_end == NULL) {
                r_end = file_end;        
            }
            if(r_end == NULL) {
                break;
            }
            if(*conf_file_buff == ';') {
                conf_file_buff = conf_point_offset(r_end, file_end);
                continue;
            }
            stropt_memcpy(&row, conf_file_buff, (r_end-1));
            if(strstr(row, "=")) {
                /*去除空格*/
                stropt_del_chr(row, (char)' ');
            }else if(strstr(row, "[") && strstr(row, "]")) {
                go_on = 1;
            }else {
                go_on = 2;
            }
            if(go_on) {
                conf_point_free(row);
                if(go_on == 2) {
                    conf_file_buff = conf_point_offset(r_end, file_end);
                    continue;
                } else {
                    break;
                }
            }
            conf_file_buff = conf_point_offset(r_end, file_end);
            s_end = strstr(row, "=");
            stropt_memcpy(&sign, row, (s_end-1));
            stropt_memcpy(&option_val, (s_end+1), (row + strlen(row) -1));
            conf_point_free(row);
            /*查找配置项key*/
            if(cursor->list == NULL) {
                nest_create_list(&(cursor->list));
            }
            nest_reset_cursor(cursor->list);
            while(option = nest_foreach_list(cursor->list)) {
                if(strcmp(((conf_data *)option->data)->key, sign) == 0) {
                    break;
                }
            }
            if(option == NULL) {
                result = conf_create_data(&data, sign, option_val);
                if(result) {
                    nest_destroy_list(_CONFIG);
                    conf_point_free(sign);
                    conf_point_free(option_val);
                    goto CONF_INIT_EXIT;
                }
                result = nest_add_node(cursor->list, (void *)data, NULL, 1, 
                            NULL);
                if(result) {
                    nest_destroy_list(_CONFIG);
                    conf_point_free(sign);
                    conf_point_free(option_val);
                    goto CONF_INIT_EXIT;
                }
                /*查找节点*/
                option = nest_find_node(cursor->list, (void *)data);
                data = NULL;
            } else {
                if(((conf_data *)option->data)->value != NULL) {
                    conf_point_free(((conf_data *)option->data)->value);
                }
                ((conf_data *)option->data)->value = option_val;
            }
            option_val = NULL;
            sign = NULL;
        }
    }
    result = 0;
CONF_INIT_EXIT:
    conf_point_free(reset);
    conf_file_buff = NULL;
    return result;
}

uint8_t
conf_create_data(conf_data **data, conf_key key, conf_val value)
{
    *data = (conf_data *)malloc(sizeof(conf_data));
    if(*data == NULL) {
        return 1;
    }
    if(key != NULL) {
        (*data)->key = (conf_key)malloc(sizeof(char) * strlen(key));
        if((*data)->key == NULL) {
            return 1;
        }
    }
    
    if(value != NULL) {
        (*data)->value = (conf_val)malloc(sizeof(char) * strlen(value));
        if((*data)->value == NULL) {
            return 1;
        }
    }
    
    (*data)->key = key;
    (*data)->value = value;
    return 0;
}

conf_val
conf_get_option_val(conf_key config, conf_key options)
{
    nest_node *conf;
    nest_node *conf_option;
    nest_reset_cursor(_CONFIG);
    while(conf = nest_foreach_list(_CONFIG)) {
        if(strcmp(((conf_data *)conf->data)->key, config) != 0) {
            continue;
        }
        nest_reset_cursor(conf->list);
        while(conf_option = nest_foreach_list(conf->list)) {
            if(strcmp(((conf_data *)conf_option->data)->key, options) == 0) {
                return ((conf_data *)conf_option->data)->value;
            }
        }
    }
    return NULL;
}

nest_list*
conf_get_options(conf_key config)
{
    nest_node *conf;
    nest_reset_cursor(_CONFIG);
    while(conf = nest_foreach_list(_CONFIG)) {
        if(strcmp(((conf_data *)conf->data)->key, config) != 0) {
            continue;
        }
        return conf->list; 
    }
    return NULL;
}

void
conf_free(/*void*/)
{
    nest_destroy_list(_CONFIG);
}
