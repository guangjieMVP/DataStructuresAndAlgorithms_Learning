
/************************************************************************
  * @file:     xxx.c
  * @author:   guangjieMVP
  * @github:   https://github.com/guangjieMVP
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
**************************************************************************/
#include "array_queue.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

static int is_arr_queue_empty(arr_queue_t *q)
{
    if(!q)
        return 0;

    return (q->queue_count == 0);
}

static int is_arr_queue_full(arr_queue_t *q)
{
    if(!q)
        return 0;

    return (q->queue_count >= (q->queue_size));
}

int arr_queue_init(arr_queue_t *q, int *queue_buf, int queue_size)
{
    if(!q || !queue_buf || queue_size <= 0)
        return -1;

    q->queue_buf   = queue_buf;
    q->queue_size  = queue_size;
    q->queue_count = 0;
    return 0;
}

int arr_queue_deinit(arr_queue_t *q)
{
    if(!q)
        return -1;

    memset(q->queue_buf, 0, q->queue_size);
    q->queue_count = 0;
    q->queue_size  = 0;
    return 0;
}

int arr_queue_en(arr_queue_t *q, int val)
{
    if(!q)
        return -1;
    
    if(is_arr_queue_full(q))
        return -1;

    // printf("\r\n");
    // printf("q->queue_count = %d\r\n", q->queue_count);
    
    q->queue_buf[q->queue_count] = val;
    q->queue_count++;

    return 0;
}

int arr_queue_out(arr_queue_t *q, int *val)
{
    if(!q || is_arr_queue_empty(q))
        return -1;
    
    *val = q->queue_buf[0];
    q->queue_count--;
    for(int i = 0; i < q->queue_size; i++)
    {
        q->queue_buf[i] = q->queue_buf[i+1];
    }
    return 0;
}



