
/***********************************************************************
 * @file:     xxx.c
 * @author:   guangjieMVP
 * @github:   https://github.com/guangjieMVP
 * @version:  v1.0.0
 * @date:     2020-xx-xx
 * @brief:               
*************************************************************************/

#ifndef _LINK_QUEUE_H_
#define _LINK_QUEUE_H_

typedef struct _data_node
{
    int data;
    struct _data_node *next;
}data_node_t;

typedef struct _link_queue
{
    data_node_t *front;      
    data_node_t *rear;          
    int queue_size;
    int queue_count;
}link_queue_t;

int link_queue_init(link_queue_t *s, int queue_size);
int link_queue_deinit(link_queue_t *s);
int link_queue_en(link_queue_t *s, int val);
int link_queue_out(link_queue_t *s, int *val);

#endif