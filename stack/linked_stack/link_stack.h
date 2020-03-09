/***********************************************************************
 * @file:     xxx.c
 * @author:   guangjieSuper
 * @github:   https://github.com/guangjieSuper
 * @version:  v1.0.0
 * @date:     2020-xx-xx
 * @brief:               
*************************************************************************/
#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_

typedef struct _data_node
{
    int data;
    struct _data_node *prev;
}data_node_t;

typedef struct _link_stack
{      
    data_node_t *top;          
    int stack_size;
    int stack_count;
}link_stack_t;

int link_stack_init(link_stack_t *s, int stack_size);
int link_stack_deinit(link_stack_t *s);
int link_stack_push(link_stack_t *s, int val);
int link_stack_pop(link_stack_t *s, int *val);

#endif