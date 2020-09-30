#include <stdio.h>
#include <stdlib.h>

#include "double_link_list.h"



/*d_node_t *find_node(d_link_list_t *list, void *data)
{
    d_link_list_t *tmp;

    for (tmp = list->next; tmp != NULL && (*(tmp->data) != data; tmp = tmp->next);

    if (tmp == NULL)
    {
        printf("链表无此数据\r\n");
        return NULL;
    }

    printf("找到该数据所在节点\r\n");

    return tmp;
}*/

void print_int_node_cb(void *node, void *res)
{
    d_elem_t *tmp = (d_elem_t *)node;
    int dat = *(int *)(tmp->data);
    printf("int node : %d\r\n", dat);
}

void print_str_node_cb(void *node, void *res)
{
    d_elem_t *tmp = (d_elem_t *)node;
    char *str = tmp->data;
    printf("string node : %s\r\n", str);
}

void calc_list_data_sum(void *node, void *res)
{
    d_elem_t *tmp = (d_elem_t *)node;
    int *sum = res;

    *sum += *(int *)tmp->data;
}

void calc_list_max_data(void *node, void *res)
{
    d_elem_t *tmp = (d_elem_t *)node;
    int *max = (int *)res;
    int prev_dat;
    int next_dat;

    if (tmp->next != NULL)
    {
        prev_dat = *(int *)tmp->data;
        next_dat = *(int *)tmp->next->data;

        *max = prev_dat  > next_dat ? prev_dat : next_dat;
    }
}

struct aaa
{
    void *a;
};

void *dlist_get(int a)
{
    void *ret = &a;
    printf("形参地址 ：%p", &a);
    return ret;
}

void *ptr;

void set_val(void *p)
{
    ptr = p;
}

void *get_val()
{
    return ptr;
}


int main()
{

    int val = 30;

    set_val(&val);

    int *tmp = (int *)get_val();

    printf("%d", *tmp);

#if 0

    dlist_t *list = create_dlist();   //存放整数的链表

    int arr[10];
    for (int j = 0; j < 10; j++)
    {
        arr[j] = j;
    }

    d_elem_t node[10];
    int i = 0;


    for (i = 0; i < 10; i++)
    {
        init_elem(&node[i], &arr[i]);
    }

    for (i = 0; i < 10; i++)
    {
        dlist_push_back(list, &node[i]);
    }
    dlist_traver(list, print_int_node_cb, NULL);

    int sum = 0;
    dlist_traver(list, calc_list_data_sum, &sum);
    printf("链表和为 ： %d\r\n", sum);

    int max = 0;
    dlist_traver(list, calc_list_max_data, &max);
    printf("链表数据最大值为 ： %d\r\n", max);

    printf("获取节点：\r\n");

#if 1
    int index = 0;
    int *data;
 //   dlist_traver(list, print_int_node_cb, NULL);
    data = (int *)dlist_get_by_index(list, index);
    printf("list[%d] = %d\r\n", index, *data);

    index += 1;

    data = (int *)dlist_get_by_index(list, index);
    printf("list[%d] = %d\r\n", index, *data);

    index += 1;

    data = (int *)dlist_get_by_index(list, index);
    printf("list[%d] = %d\r\n", index, *data);

    data = (int *)dlist_get_by_index(list, 7);
    printf("list[%d] = %d\r\n", index, *data);
#endif //

#endif // 0


 //   printf("删除节点 : \r\n\r\n");
#if 0
    dlist_remove_by_index(list, 9);
    dlist_traver(list, print_int_node_cb, NULL);

    dlist_remove_by_index(list, 1);
    dlist_traver(list, print_int_node_cb, NULL);

    dlist_remove_by_index(list, 9);
    dlist_traver(list, print_int_node_cb, NULL);

#endif



#if 0
    //删除测试
//    dlist_remove(list, &node[0]);
//    dlist_traver(list, print_int_node_cb, NULL);

//    dlist_remove(list, &node[9]);
//    dlist_traver(list, print_int_node_cb, NULL);

//    dlist_remove(list, &node[5]);
//    dlist_traver(list, print_int_node_cb, NULL);
#endif // 0

#if 0
//删除最后一个元素测试
//    dlist_pop_back(list);
//    dlist_traver(list, print_int_node_cb, NULL);

 //   dlist_pop_back(list);
//    dlist_traver(list, print_int_node_cb, NULL);

//    dlist_pop_back(list);
//    dlist_traver(list, print_int_node_cb, NULL);
#endif // 0

# if 0
    dlist_t *str_list = create_dlist();    //存放字符串的链表

    d_elem_t str_node1;
    init_elem(&str_node1, "笨蛋");
    dlist_push_back(str_list, &str_node1);

    d_elem_t str_node2;
    init_elem(&str_node2, "傻瓜");
    dlist_push_back(str_list, &str_node2);

    d_elem_t str_node3;
    init_elem(&str_node3, "I love u");
    dlist_push_back(str_list, &str_node3);

    dlist_traver(str_list, print_str_node_cb, &sum);

    int a = 1000;

    void *p = &a;
    printf("%d\r\n", *(int *)p);


    struct aaa *aa = (struct aaa *)malloc(sizeof(struct aaa));
    aa->a = &a;
    printf("%d\r\n", *(int *)aa->a);
#endif // 0

    return 0;
}

/*

enum ENUM_A
{
    x1,
    y1,
    z1 = 5,
    a1,
    b1
};


int max(int a, int b)
{
    return (a > b ? a : b);
}

void test()
{
    int a[9];
    int *p = a;

    for (int i = 0; i < 9; i++)
    {
        a[i] = i+1;
    }

    printf("%d\r\n", *(++p));
}

void test2(void)
{
    unsigned long pulArray[] = {6,7,8,9,10};
    unsigned long *pulPtr;

    pulPtr = pulArray;
    *(pulPtr + 2) += 2;
    printf("%d, %d\r\n", *pulPtr, *(pulPtr + 2));
}

void test3()
{
    char *szStr = "abcde";
    szStr += 2;
    printf("%1u\r\n", szStr);
}

void test4()
{
       union
    {
        int k;
        char i[2];
    } *s, a;
    s = &a;
    s->i[0] = 0x39;
    s->i[1] = 0x38;
    printf("%x\r\n", a.k);

}  */
