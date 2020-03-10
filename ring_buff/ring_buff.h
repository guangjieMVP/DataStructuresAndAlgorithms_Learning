/***********************************************************************
 * @file:        xxx.c
 * @author:      guangjieMVP
 * @version:     v1.00.00
 * @date:        2020-xx-xx
 * @github:      https://github.com/guangjieMVP
 * @brief: 
***********************************************************************/
/***********************************************************************
 * @file:        xxx.c
 * @author:      guangjieMVP
 * @version:     v1.00.00
 * @date:        2019-11-xx
 * @github:     
 * @brief: 
***********************************************************************/

#ifndef _RING_BUFF_H_
#define _RING_BUFF_H_

#define RING_BUFF_SIZE     20

typedef enum{
    FALSE = 0,
    TRUE  = !FALSE,
}bool,BOOL;

typedef struct ring_buf
{
    unsigned int in;
    unsigned int out;
    unsigned char buffer[RING_BUFF_SIZE];
}ringbuf_t;

char write_byte_to_ringBuf(ringbuf_t *ringbuf, char data);
char read_byte_from_ringbuf(ringbuf_t *ringbuf, char *data);

void write_ringbuf(ringbuf_t *ringbuf,char *write_buf,unsigned int len);
void read_ringbuf(ringbuf_t *ringbuf,char *read_buf,unsigned int len);

unsigned int get_ringbuf_length(ringbuf_t *ringbuf);


#endif