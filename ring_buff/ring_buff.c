/**
  * @file:     ringBuff.c
  * @author:   AresXu
  * @version:  v1.0.0
  * @date:     2019-11-xx
  * @brief:    环形队列
*/
#include "ringBuff.h"


/**
  * @brief:        判斷環形隊列是否空
  * @param[in]:     None
  * @retval[out]:   None
  * @author:       AresXu
  * @version:      v1.0.0
*/
bool is_ringbuf_empty(ringbuf_t *ringbuf)
{
    if(ringbuf->in == ringbuf->out)
    {
//		printf("Ring buffer is Empty\r\n");
        return TRUE;
    }
    return FALSE;
}

/**
  * @brief:         判斷環形隊列是否满
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:       AresXu
  * @version:      v1.0.0
*/
bool is_ringbuf_full(ringbuf_t *ringbuf)
{
    if(((ringbuf->in+1) % RING_BUFF_SIZE) == ringbuf->out)
    {
//		printf("Ring buffer is Full\r\n");
        return TRUE;
    }
    return FALSE;
}

/**
  * @brief:         寫一字節的數據到環形隊列
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:       AresXu
  * @version:      v1.0.0
*/
char write_byte_to_ringBuf(ringbuf_t *ringbuf, char data)
{
    if(is_ringbuf_full(ringbuf))
    {
        return FALSE;
    }

    ringbuf->buffer[ringbuf->in] = data;
    ringbuf->in = (++ringbuf->in) % RING_BUFF_SIZE;    //防止越界
	return TRUE;
}

char read_byte_from_ringbuf(ringbuf_t *ringbuf, char *data)
{
    if(is_ringbuf_empty(ringbuf))
    {
        return FALSE;
    }

    *data = ringbuf->buffer[ringbuf->out];
    ringbuf->out = (++ringbuf->out) % RING_BUFF_SIZE;    //防止越界

    return TRUE;
} 

/**
  * @brief:         寫len個字節數據到環形隊列
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:       AresXu
  * @version:      v1.0.0
*/
void write_ringbuf(ringbuf_t *ringbuf,char *write_buf, unsigned int len)
{
    unsigned int i;

     if(ringbuf == NULL || write_buf == NULL || len <= 0)
        return;

    for(i = 0; i < len; i++)
    {
        write_byte_to_ringBuf(ringbuf,write_buf[i]);
    }
}

/**
  * @brief:         從環形隊列讀出len個字節的數據
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:       AresXu
  * @version:      v1.0.0
*/
void read_ringbuf(ringbuf_t *ringbuf, char *read_buf, unsigned int len)
{
    unsigned int i;
    if(ringbuf == NULL || read_buf == NULL || len <= 0)
        return;

    for(i = 0; i < len; i++)
    {
        read_byte_from_ringbuf(ringbuf,&read_buf[i]);
    }
}


/**
  * @brief:         獲取已經寫入的長度
  * @param[in]:     None
  * @retval[out]:   None
  * @note:            
  * @author:       AresXu
  * @version:      v1.0.0
*/
unsigned int get_ringbuf_length(ringbuf_t *ringbuf)
{
    return (ringbuf->in - ringbuf->out + RING_BUFF_SIZE) % RING_BUFF_SIZE;
}