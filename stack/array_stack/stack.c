/**
  * @file:     stack.c
  * @author:   guangjieMVP
  * @github:              
  * @version:  v1.0.0
  * @date:     2020-xx-xx
  * @brief:    Array implementation of stacks           
*/

#include "stack.h"

static int is_stack_full(stack_t *stack)
{
    return (stack->top >= (stack->size - 1));
}

static int is_stack_empty(stack_t *stack)
{
    return (stack->top == STACK_IS_EMPTY);
}
/**
  * @brief:         initilize a stack
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:        guangjieSuper
*/
int stack_init( stack_t *stack, int *stack_buffer, int size )
{
    stack->stack_buf = stack_buffer;
    stack->size      = size;
    stack->top       = -1;
    return 0;
}

int stack_push(stack_t *stack,int data)
{
    if(is_stack_full(stack))
        return -1;
    stack->top++;
    stack->stack_buf[stack->top] = data;
    return 0;
}

/**
  * @brief:    
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:        guangjieSuper
  * @version:       v1.0.0
*/
int stack_pop(stack_t *stack, int *data)
{
    if(is_stack_empty(stack))
        return -1;
    *data = stack->stack_buf[stack->top];
    stack->top--;
    return 0;
}

