/**
  * @file:     xxx.c
  * @author:   guangjieMVP
  * @github:   https://github.com/guangjieMVP
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
*/

#include "link_stack.h"
#include "string.h"
#include "stdlib.h"

static int is_stack_empty(link_stack_t *s)
{
    if(!s)
        return 0;

    return (s->stack_count == 0);
}

static int is_stack_full(link_stack_t *s)
{
    if(!s)
        return 0;

    return ( s->stack_count >= s->stack_size );
}

static data_node_t *data_node_init(int data)
{
    data_node_t *d = (data_node_t *)malloc(sizeof(data_node_t));
    if(!d)
        return NULL;

    d->data        = data;
    d->prev        = NULL;
    return d;
}

static int data_node_deinit(data_node_t *data_node)
{
    if(!data_node)
        return -1;
    
    data_node->data = 0;
    data_node->prev = NULL;
    free(data_node);
    return 0;
}

int link_stack_init(link_stack_t *s, int stack_size)
{
    if(!s || stack_size <= 0)
        return -1;

    s->top         = NULL;
    s->stack_count = 0;
    s->stack_size  = stack_size;
}

int link_stack_deinit(link_stack_t *s)
{
    if(!s)
        return -1;
    
    if(is_stack_empty(s))
    {
        s->top         = NULL;
        s->stack_count = 0;
        s->stack_size  = 0;
    }
    else
    {
        data_node_t *node = s->top;
        for(int i = 0; ( (i < s->stack_count) && !node); i++, node = node->prev)
        {
            data_node_deinit(node);
        }
    }
    return 0;
}

int link_stack_push(link_stack_t *s, int val)
{
    if(!s || is_stack_full(s))
        return -1;

    data_node_t *d = data_node_init(val);
    if(!d)
        return -1;

    if(is_stack_empty(s))
    {
        s->top = d;
        s->stack_count++;
        return 0;
    }
    else
    {
        d->prev = s->top;
        s->top  = d;
        s->stack_count++;
        return 0;
    }
    
}

int link_stack_pop(link_stack_t *s, int *val)
{
    data_node_t *node;

    if(!s || is_stack_empty(s) || !val)
        return -1;

    node   = s->top;
    *val   = s->top->data;
    s->top = node->prev;
    s->stack_count--;
    data_node_deinit(node);
    return 0;
}
