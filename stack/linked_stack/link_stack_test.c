/************************************************************************
  * @file:     xxx.c
  * @author:   guangjieMVP
  * @github:   https://github.com/guangjieMVP
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
**************************************************************************/


#include "stdio.h"
#include "link_stack.h"
#include "string.h"

#define LINK_STACK_SIZE     6

link_stack_t link_stack;

int main(int argc, char **argv)
{
    int data;

    link_stack_init(&link_stack, LINK_STACK_SIZE);

    if(link_stack_push(&link_stack, 1) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 2) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 3) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 4) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 5) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 6) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    
    if(link_stack_push(&link_stack, 7) == -1)
    {
        printf("push failed\r\n");
    }
    else
    {
        printf("push success\r\n");
    }
    

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    link_stack_pop(&link_stack, &data);
    printf("%d\r\n",data);

    if( link_stack_pop(&link_stack, &data) == (-1) )
    {
        printf("stack is empty\r\n");
    }
    else
    {
        printf("%d\r\n",data);    
    }
    
    

    return 0;
}