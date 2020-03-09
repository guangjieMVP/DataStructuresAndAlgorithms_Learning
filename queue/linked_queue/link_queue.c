/************************************************************************
  * @file:     xxx.c
  * @author:   guangjieMVP
  * @github:   https://github.com/guangjieMVP
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
**************************************************************************/


#include "link_queue.h"
#include "string.h"
#include "stdlib.h"

static int is_queue_empty(link_queue_t *q)
{
    return (q->queue_count == 0);
}

static int is_queue_full(link_queue_t *q)
{
    return ( q->queue_count >= q->queue_size );
}

static data_node_t *data_node_init(int data)
{
    data_node_t *d = (data_node_t *)malloc(sizeof(data_node_t));
    if(!d)
        return NULL;

    d->data        = data;
    d->next        = NULL;
    return d;
}

static int data_node_deinit(data_node_t *data_node)
{
    if(!data_node)
        return -1;
    
    data_node->data = 0;
    data_node->next = NULL;
    free(data_node);
    return 0;
}

int link_queue_init(link_queue_t *q, int queue_size)
{
    if(!q)
        return -1;

    q->front       = NULL;
    q->rear        = NULL;
    q->queue_count = 0;
    q->queue_size  = queue_size;
}

int link_queue_deinit(link_queue_t *q)
{
    if(!q)
        return -1;
    
    if(is_queue_empty(q))
    {
        q->front       = NULL;
        q->rear        = NULL;
        q->queue_count = 0;
        q->queue_size  = 0;
    }
    else
    {
        data_node_t *node = q->front;
        for(int i = 0; ( (i < q->queue_count) && !node); i++, node = node->next)
        {
            data_node_deinit(node);
        }
    }
    return 0;
}

/************************************************************************
  * @brief:         enter queue
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:        guangjieMVP
**************************************************************************/
int link_queue_en(link_queue_t *q, int val)
{
    if(!q)
        return -1;

    data_node_t *d = data_node_init(val);
    if(!d)
        return -1;

    if(is_queue_full(q))
        return -1;

    if(is_queue_empty(q))
    {
        q->rear  = d;
        q->front = d;
        q->queue_count++;
    }
    else
    {
        q->rear->next = d;
        q->rear       = d;
        q->queue_count++;
    }
    return 0;
}

/************************************************************************
  * @brief:         out queue
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:        guangjieMVP
**************************************************************************/
int link_queue_out(link_queue_t *q, int *val)
{
    data_node_t *node;

    if(!q)
        return -1;

    if(is_queue_empty(q))
        return -1;

    node     = q->front;
    q->front = node->next;
    *val     = node->data;
    q->queue_count--;
    data_node_deinit(node);
    return 0;
}
