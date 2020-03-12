

#include "stack.h"

static int is_stack_full(stack_t *s)
{
    if(!s)
        return 0;

    return (s->top >= (s->size - 1));
}

static int is_stack_empty(stack_t *s)
{
    if(!s)
        return 0;

    return (s->top == STACK_IS_EMPTY);
}
/**
  * @brief:         initilize a stack
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:        guangjieSuper
*/
int stack_init( stack_t *s, int *stack_buffer, int size )
{
    if(!s || !stack_buffer || size <= 0)
        return -1;

    s->stack_buf = stack_buffer;
    s->size      = size;
    s->top       = -1;
    return 0;
}

int stack_push(stack_t *s,int data)
{
    if(is_stack_full(s))
        return -1;

    s->top++;
    s->stack_buf[s->top] = data;
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
int stack_pop(stack_t *s, int *data)
{
    if(is_stack_empty(s) || !data)
        return -1;

    *data = s->stack_buf[s->top];
    s->top--;
    return 0;
}

