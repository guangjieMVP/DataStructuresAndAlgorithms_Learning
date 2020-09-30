#ifndef DOUBLE_LINK_LIST_H_INCLUDED
#define DOUBLE_LINK_LIST_H_INCLUDED


#define DLIST_IS_VALID(expression, retval) do{ \
    if (expression)                       \
        return retval;                 \
}while(0)

#define NULL_DLIST_IS_VALID(list)  do{ \
    if (!list)                         \
        return NULL;                   \
}while(0)

#define INT_DLIST_IS_VALID(list)  do{ \
    if (!list)                        \
        return 0;                     \
}while(0)

//通用的双向链表
typedef struct double_link_list
{
    void   *data;
    struct double_link_list *prev;
    struct double_link_list *next;
}dlist_t, d_elem_t;


#ifdef __cplusplus    //C++调用这些函数时编译器不能对函数名进行重新编码，让C++可以调用这些函数
extern "C"{
#endif

int init_elem(d_elem_t *node, void *data);

dlist_t *create_dlist(void);     //动态创建链表
int init_dlist(dlist_t *list); //初始化静态链表

char is_dlist_empty(dlist_t *list);

int dlist_push_back(dlist_t *list, d_elem_t *elem);
d_elem_t *dlist_pop_back(dlist_t *list);

d_elem_t *dlist_remove(dlist_t *list, d_elem_t *del_elem);

d_elem_t *dlist_remove_by_index(dlist_t *list, int index);
void *dlist_get_by_index(dlist_t *list, int index);

int dlist_traver(dlist_t *list, void (*to_do_cb)(void *elem, void *res), void *result);

#ifdef __cplusplus
}
#endif // __cplusplus


#endif // DOUBLE_LINK_LIST_H_INCLUDED
