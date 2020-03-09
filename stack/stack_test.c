/**
  * @file:     xxx.c
  * @author:   guangjieSuper
  * @github:   https://github.com/guangjieSuper
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:               
*/
#include "stdio.h"
#include "stack.h"

#define STACK_SIZE    1024

int stack_buffer[STACK_SIZE];

stack_t stack;

int main(int argc, char **argv)
{
    int data;

    stack_init(&stack, stack_buffer, STACK_SIZE);

    stack_push(&stack, 1);
    stack_push(&stack, 2);
    stack_push(&stack, 3);

    stack_pop(&stack, &data);
    printf("%d\r\n",data);

    stack_pop(&stack, &data);
    printf("%d\r\n",data);

    stack_pop(&stack, &data);
    printf("%d\r\n",data);

    if( stack_pop(&stack, &data) == (-1) )
    {
        printf("stack is empty\r\n");
    }
    else
    {
        printf("%d\r\n",data);    
    }
    
    

    return 0;
}