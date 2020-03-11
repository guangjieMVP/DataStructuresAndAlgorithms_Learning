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
#include "stdio.h"

#define QUEUE_SIZE    4

int queue_arr[QUEUE_SIZE];

int main(int argc, char **argv)
{
    int i = 0;
    arr_queue_t q;    
    int data;

    arr_queue_init(&q, queue_arr, QUEUE_SIZE);

    for(i = 0; i < (QUEUE_SIZE+1); i++)
    {
        if(arr_queue_en(&q, i) == -1)
        {
            printf("queue is full\r\n");
        }
        else
        {
            printf("en  = %d\r\n", i);
        }
    }

    for(i = 0; i < (QUEUE_SIZE+1); i++)
    {
        if(arr_queue_out(&q, &data) == -1)
        {
            printf("queue is empty\r\n");
        }
        else
        {
            printf("out = %d\r\n",data);
        }
    }
    printf("\r\n");
    for(i = 0; i < (QUEUE_SIZE+1); i++)
    {
        int val = i+1;
        if(arr_queue_en(&q, val) == -1)
        {
            printf("queue is full\r\n");
        }
        else
        {
             printf("en  = %d\r\n", val);
        }
    }

    for(i = 0; i < (QUEUE_SIZE+1); i++)
    {
        if(arr_queue_out(&q, &data) == -1)
        {
            printf("queue is empty\r\n");
        }
        else
        {
            printf("out = %d\r\n",data);
        }
    }
    printf("\r\n");
  
    


    return 0;
}