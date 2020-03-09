
/************************************************************************
  * @file:     xxx.c
  * @author:   guangjieMVP
  * @github:   https://github.com/guangjieMVP
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
**************************************************************************/


#include "stdio.h"
#include "link_queue.h"
#include "string.h"

#define LINK_QUEUE_SIZE     4

#define EN_QUEUE_FAILED      printf("enter queue failed\r\n")
#define EN_QUEUE_SUCCESS     printf("enter queue success\r\n")

link_queue_t link_queue;

int main(int argc, char **argv)
{
    int data;

    link_queue_init(&link_queue, LINK_QUEUE_SIZE);

    if(link_queue_en(&link_queue, 1) == -1)
    {
        EN_QUEUE_FAILED;
    }
    else
    {
        EN_QUEUE_SUCCESS;
    }
    
    if(link_queue_en(&link_queue, 2) == -1)
    {
        EN_QUEUE_FAILED;
    }
    else
    {
        EN_QUEUE_SUCCESS;
    }
    
    if(link_queue_en(&link_queue, 3) == -1)
    {
        EN_QUEUE_FAILED;
    }
    else
    {
        EN_QUEUE_SUCCESS;
    }

    if(link_queue_en(&link_queue, 4) == -1)
    {
        EN_QUEUE_FAILED;
    }
    else
    {
        EN_QUEUE_SUCCESS;
    }
    
    if(link_queue_en(&link_queue, 5) == -1)
    {
        EN_QUEUE_FAILED;
    }
    else
    {
        EN_QUEUE_SUCCESS;
    }

    link_queue_out(&link_queue, &data);
    printf("%d\r\n",data);

    link_queue_out(&link_queue, &data);
    printf("%d\r\n",data);

    link_queue_out(&link_queue, &data);
    printf("%d\r\n",data);

    link_queue_out(&link_queue, &data);
    printf("%d\r\n",data);

    if( link_queue_out(&link_queue, &data) == (-1) )
    {
        printf("stack is empty\r\n");
    }
    else
    {
        printf("%d\r\n",data);    
    }

    return 0;
}