#include "stdio.h"
#include "stdlib.h"

typedef struct node
{
    int data; 
    struct node *prev; //指向上一个节点
    struct node *next; //指向下一个节点
}doublelinklist,*double_linklist;

double_linklist head;//头节点

typedef struct find_strute
{
    double_linklist find;
    char is_find;  //1：在链表中找到该节点，0：在链表中找不到该节点
}find_strute;

//创建一个空链表
double_linklist create_list(void)
{
    double_linklist mylist = malloc(sizeof(doublelinklist));
    
    if(mylist == NULL)
    {
        printf("create linked list is faied\n\r");
        return;
    }
    
    mylist->prev = mylist;
    mylist->next = mylist;
}

//从pos节点指向上一个节点后面插入节点
char insert_node_prev(double_linklist pos,double_linklist insert)
{
    if(pos == NULL || insert == NULL)
    {
        printf("linklist is not exist or insert_node is NULL");
        return 0;
    }
 
    double_linklist prev = NULL;
    
    prev = pos->prev;  //保存pos上一个节点的指针
      
    prev->next = insert; //pos节点的上一个节点指向插入节点
    insert->prev = prev; //插入节点指向pos上一个节点
    
    insert->next = pos;  //插入节点指向pos节点
    pos->prev = insert;  //pos节点指向插入节点
    
    return 1;
}

//从pos节点指向下一个节点前面插入节点
char insert_node_next(double_linklist pos,double_linklist insert)
{
    if(pos == NULL || insert == NULL)
    {
        printf("linklist is not exist or insert_node is NULL");
        return 0;
    }
 
    double_linklist next = NULL;
    
    next = pos->next;  //保存pos指向的下一个节点的指针
      
    pos->next = insert; //pos节点指向插入节点
    insert->prev = pos; //插入节点指向pos节点
    
    next->prev = insert;  //pos节点下一个节点指向插入节点
    insert->next = next;  //插入节点指向pos节点的下一节点
    
    return 1;
}

//遍历节点
void traverse_list(double_linklist head)
{
    int i = 1;
    
    if(head == NULL)
    {
        return;
    }
   
   double_linklist list = head->next;
    while(list != head)
    {
        printf("第%d个节点data： %d\n\r",i,list->data);
        list = list->next;
        i++;
    }
}

//根据找到数据data所在的节点
find_strute find_node(double_linklist pos,int data)
{
    find_strute find_str;
    find_str.find = NULL;
    find_str.is_find = 0;
    
    if(pos == NULL)
    {
        return;
    }
    double_linklist p = pos->next;
    while(p != pos)
    {
        if(p->data == data)
        {
           // printf("have found data,data :%d p->data: %d\n\r",data,p->data);
            break;
        }
        p = p->next;
    }
    
    if(p == pos)
    {
        find_str.find = NULL;
        find_str.is_find = 0;
        printf("can't not find the node it's data is %d\n\r",data);
        return find_str;
    }
    
    find_str.find = p;
    find_str.is_find = 1;
    return find_str;
}

void delete_node(double_linklist pos)
{
    if(pos == NULL || pos == head)
    {
        if(pos == head)
        {
            printf("can't not to delete head node\n\r");
        }        
        return;
    }
    
    find_strute find_str = find_node(head,pos->data);
    if(find_str.is_find == 0)//删除前先判断该节点是否在链表中
    {
        printf("this node is not in the linked list\n\r");
        return;
    }
    pos->prev->next = pos->next; //pos的上一个节点指向pos的下一个节点
    pos->next->prev = pos->prev;
    
    pos->prev = NULL;//断开与上一个节点的链接
    pos->next = NULL;//断开与下一个节点的链接
    
    free(pos);//释放内存
}

//向pos指向的上一个节点方向移动
double_linklist move_node_prev(double_linklist pos,double_linklist move)
{   
    double_linklist move_clone = malloc(sizeof(doublelinklist));
    move_clone->data = move->data; //保存要移动的节点的数据，因为下面删除会释放掉move节点
    move_clone->prev = NULL;
    move_clone->next = NULL;
    
    delete_node(move);
    insert_node_prev(pos,move_clone);
    
    return move_clone;
}

//向pos指向的下一个节点方向移动
double_linklist move_node_next(double_linklist pos,double_linklist move)
{ 
    if(move == NULL || pos == NULL)
    {
        return;
    }
    
    double_linklist move_clone = malloc(sizeof(doublelinklist));
    move_clone->data = move->data;//保存要移动的节点的数据，因为下面删除会释放掉move节点
    move_clone->prev = NULL;
    move_clone->next = NULL;
    
    delete_node(move);
    insert_node_next(pos,move_clone);
    
    return move_clone;
}



int main(int argc,char **argv)
{
    find_strute find_str;
    int data = 3;
    
    head =  create_list();  
    
    double_linklist insert1 = malloc(sizeof(doublelinklist));
    insert1->data = 1;
    insert1->prev = NULL;
    insert1->next = NULL; 
    insert_node_prev(head,insert1); //插入节点
    
    double_linklist insert2 = malloc(sizeof(doublelinklist));
    insert2->data = 2;
    insert2->prev = NULL;
    insert2->next = NULL; 
    insert_node_prev(insert1,insert2);
    
    double_linklist insert3 = malloc(sizeof(doublelinklist));
    insert3->data = 3;
    insert3->prev = NULL;
    insert3->next = NULL;
    insert_node_prev(insert2,insert3);
    
    //测试遍历链表函数
    traverse_list(head);
    printf("\n\r");
    
    double_linklist insert4 = malloc(sizeof(doublelinklist));
    insert4->data = 4;
    insert4->prev = NULL;
    insert4->next = NULL;
    insert_node_next(head,insert4);
    traverse_list(head);
    printf("\n\r");
    
    //测试删除节点函数
    delete_node(insert4);
    traverse_list(head); //遍历链表
    printf("\n\r");
    
    //测试find_node函数
    find_str = find_node(head,data);
    printf("find data is %d\n\r",find_str.find->data);
    printf("\n\r");
    
    //测试move_node_next函数
    double_linklist insert3_clone = move_node_next(insert1,insert3);
    traverse_list(head);
    printf("\n\r");
    
    //测试move_node_prev函数
    move_node_prev(insert1,insert3_clone);
    traverse_list(head);
    printf("\n\r");
    
     //测试函数不在链表中的节点情况处理
    double_linklist insert5 = malloc(sizeof(doublelinklist));
    insert5->data = 5;
    insert5->prev = NULL;
    insert5->next = NULL;
    delete_node(insert5);
    traverse_list(head);
    printf("\n\r");
    return 1;
}
