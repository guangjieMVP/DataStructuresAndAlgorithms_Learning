/***********************************************************************
 * @file:        xxx.c
 * @author:      guangjieMVP
 * @version:     v1.00.00
 * @date:        2020-xx-xx
 * @github:      https://github.com/guangjieMVP
 * @brief: 
***********************************************************************/


#ifndef _STACK_H_
#define _STACK_H_

#define STACK_IS_EMPTY   -1

typedef struct _stack{
    int *stack_buf;
    int size;
    int top;
}stack_t;

int stack_init( stack_t *s, int *stack_buffer, int size);
int stack_pop(stack_t *s, int *data);
int stack_push(stack_t *s, int data);

#endif