
/***********************************************************************
 * @file:     xxx.c
 * @author:   guangjieMVP
 * @github:   https://github.com/guangjieMVP
 * @version:  v1.0.0
 * @date:     2020-xx-xx
 * @brief:               
*************************************************************************/
#ifndef _ARRAY_QUEUE_H_
#define _ARRAY_QUEUE_H_

typedef struct _array_queue
{
    int *queue_buf;
    int queue_size;
    int queue_count;
}arr_queue_t;


int arr_queue_init(arr_queue_t *q, int *queue_buf, int queue_size);
int arr_queue_deinit(arr_queue_t *q);
int arr_queue_en(arr_queue_t *q, int val);
int arr_queue_out(arr_queue_t *q, int *val);

#endif
