/***********************************************************************
 * @file:     xxx.c
 * @author:   guangjieSuper
 * @github:   https://github.com/guangjieSuper
 * @version:  v1.0.0
 * @date:     2020-xx-xx
 * @brief:               
*************************************************************************/

#ifndef _STACK_H_
#define _STACK_H_

#define STACK_IS_EMPTY   -1

typedef struct _stack{
    int *stack_buf;
    int size;
    int top;
}stack_t;

int stack_init( stack_t *stack, int *stack_buffer, int size);
int stack_pop(stack_t *stack, int *data);
int stack_push(stack_t *stack,int data);

#endif