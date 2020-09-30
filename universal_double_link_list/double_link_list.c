#include "double_link_list.h"

#ifndef NULL
#define NULL  ((void *)0)
#endif // NULL


int init_elem(d_elem_t *elem, void *data)
{
    DLIST_IS_VALID(elem == NULL, 0);

    elem->data = data;
    elem->next = NULL;
    elem->prev = NULL;

    return 1;
}

dlist_t *create_dlist(void)
{
    dlist_t *list = (dlist_t *)malloc(sizeof(dlist_t));
    if (list != NULL)
    {
        list->next = NULL;
        list->prev = list;
    }
    return list;
}

int delete_dlist(dlist_t *list)
{
    DLIST_IS_VALID(!list, 0);

    free(list);

    return 0;
}

int init_dlist(dlist_t *list)
{
    DLIST_IS_VALID(!list, 0);

    list->next = NULL;
    list->prev = NULL;

    return 1;
}

char is_dlist_empty(dlist_t *list)
{
    if (list->next == NULL)
        return 1;

    return 0;
}

int dlist_push_back(dlist_t *list, d_elem_t *elem)
{
    DLIST_IS_VALID(!list, 0);
    DLIST_IS_VALID(!elem, 0);

    dlist_t *tmp;

    for (tmp = list; tmp->next!=NULL && tmp->next!=elem; tmp = tmp->next);

    if (tmp->next == elem)
        return 0;

    tmp->next = elem;
    elem->prev = tmp;

    return 1;
}

d_elem_t *dlist_remove(dlist_t *list, d_elem_t *del_elem)
{
    DLIST_IS_VALID(!list, 0);
    DLIST_IS_VALID(!del_elem, 0);

    dlist_t *tmp;

    for (tmp = list->next; tmp != NULL && tmp != del_elem; tmp = tmp->next);

    if (tmp == NULL)
    {
        printf("无此节点\r\n");
        return NULL;
    }

    if (tmp->next == NULL)  //删除的是最后一个节点
    {
        tmp->prev->next = NULL;
        tmp->prev = NULL;
        return tmp;
    }

    tmp->prev->next = tmp->next;   //删除节点的上一个节点的next指向删除节点的下一个节点
    tmp->next->prev = tmp->prev;   //删除节点的下一个节点的prev指针指向删除节点的上一个节点

    return tmp;
}


//通过编号索引删除链表元素
d_elem_t *dlist_remove_by_index(dlist_t *list, int index)
{
    DLIST_IS_VALID(!list, NULL);

    int num;
    dlist_t *tmp;

    for (tmp = list->next, num = 0; tmp != NULL && num != index; tmp = tmp->next, num++);

    if (tmp == NULL)
    {
        return NULL;
    }

    if (tmp->next == NULL)   //最后一个元素，特殊处理
    {
        tmp->prev->next = NULL;
        tmp->prev = NULL;
        return tmp;
    }

    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;

    tmp->prev = NULL;
    tmp->next = NULL;

    return tmp;
}


//删除最后一个元素
d_elem_t *dlist_pop_back(dlist_t *list)
{
    dlist_t *tmp;

    for (tmp = list; tmp->next != NULL; tmp = tmp->next);

    tmp->prev->next = NULL;
    tmp->prev = NULL;

    return tmp;
}

void *dlist_get_by_index(dlist_t *list, int index)
{
    DLIST_IS_VALID(!list, NULL);

    int num;
    dlist_t *tmp;
    void *val;

    for (tmp = list->next, num = 0; tmp != NULL && num != index; tmp = tmp->next, num++);

    if (tmp == NULL)
    {
        return NULL;
    }

    val = tmp->data;
    return val;
}


//遍历链表
int dlist_traver(dlist_t *list, void (*to_do_cb)(void *elem, void *res), void *result)
{
    DLIST_IS_VALID(!list, 0);
    DLIST_IS_VALID(!to_do_cb, 0);
    DLIST_IS_VALID(!result, 0);

    dlist_t *tmp;

    for (tmp = list->next; tmp != NULL; tmp = tmp->next)
    {
        to_do_cb(tmp, result);
    }
    printf("\r\n");

    return 1;
}

