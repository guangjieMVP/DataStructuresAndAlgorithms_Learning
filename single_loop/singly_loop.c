#include "stdio.h"
#include <stdlib.h>



typedef struct node
{
    int data;
    struct node *next; //指向下一个节点
}linklistloop,*linklist_loop;

//创建一个单向循环空链表
linklist_loop create_list(void)
{
    linklist_loop loop_list = malloc(sizeof(linklistloop));
    
    if(loop_list == NULL)
    {
        printf("create list is failed\n\r");
        return NULL;
    }
    loop_list->next = loop_list;//头节点的下一个节点指向自己
    
    return loop_list;
}

//插入节点
char insert_node(linklist_loop list,linklist_loop insert)
{
    if(list == NULL || insert == NULL)
    {
        printf("node is NULL");
        return 0;    
    }
    insert->next = list->next;
    list->next = insert;
    return 1;
}

int list_len(linklist_loop mylist)
{
    int len = 0;
    
    if(mylist == NULL)
    {
        return 0;
    }
    
    linklist_loop p = mylist->next;
    while(p != mylist)
    {
        len++;
        p = p->next;
    }
    
    return len;
}

//遍历链表
char treverse_list(linklist_loop mylist)
{
    char i = 1;
    if(NULL == mylist)
    {
        printf("link list is NULL\n\r");
        return 0;
    }
    
    linklist_loop p = mylist->next;
    while(p != mylist)
    {
        printf("第%d个节点 : %d\n\r",i,p->data);
        i++;
        p = p->next;
    }
    
    return 1;
}

char is_empty(linklist_loop mylist)
{
	if(mylist == NULL)
	{
		printf("link list is not exist\n\r");
		return;
	}

	if(mylist->next == mylist)
	{
		return 1;
	}

	return 0;
}

 /* 
  *@brief delete node of link list
  *@params mylist: head node of link list
  *        delete: delete node of link list
  *@retval 0:faied to delete  1: delete is succeed
  *@author Ares Xu
 */
char delete_node(linklist_loop delete)
{
	if(delete == NULL)
	{
		printf("delete is not exist\n\r");
		return 0;
	}
	
	linklist_loop p = delete->next;
	linklist_loop prev = NULL;
	while(p != delete) //循环一圈，找到要删除节点的前一个节点
	{
		prev = p;
		p = p->next;
	}

	prev->next = p->next;
	p->next = NULL;
	free(p);

	return 1;
}

/* 
  *@brief move node of link list
  *@params move:  node of link list to move 
  *        pnode: move hehind pnode
  *@retval 0:faied to delete  1: delete is succeed
  *@author Ares Xu
  *@version 0.0.0
 */
char move_node(linklist_loop move,linklist_loop pnode)
{
    if(move == NULL || pnode == NULL)
    {
        return 0;
    }
    
    int  move_data = move->data;
    linklist_loop move_clone =  malloc(sizeof(linklistloop));
    move_clone->data = move_data;
    move_clone->next = NULL;
    delete_node(move);
    insert_node(pnode,move_clone);
    
    return 1;
}

//寻找存放data的节点，并返回其地址
linklist_loop find_node(linklist_loop find,int data)
{
    if(find == NULL)
    {
        printf("node is not exist\n\r");
        return;
    }
    
    linklist_loop p = find->next;
    while(p != find)
    {
        if(p->data == data)
        {
            printf("have found this node,data: %d p->data: %d\n\r",data,p->data);
        }
        p = p->next;
    }
    if(p == find)
    {
        printf("can't find the node it's data is %d\n\r",data);
        return;
    }
    
    return p;
    
}



int main(int argc,char **argv)
{
    int len;
    
    linklist_loop mylist =  create_list();
    
    linklist_loop new1 = malloc(sizeof(linklistloop));
    new1->data = 1;
    new1->next = NULL;
    insert_node(mylist,new1);
    
    linklist_loop new2 = malloc(sizeof(linklistloop));
    new2->data = 2;
    new2->next = NULL;
    insert_node(new1,new2);
    
    linklist_loop new3 = malloc(sizeof(linklistloop));
    new3->data = 3;
    new3->next = NULL;
    insert_node(new2,new3);
  
    treverse_list(mylist);
    len = list_len(mylist);
    printf("链表长度： %d\n\r",len);
    
    printf("\n\r");
    
    delete_node(new1);
    treverse_list(mylist);
    len = list_len(mylist);
    printf("链表长度： %d\n\r",len);
    
    printf("\n\r");
    
    linklist_loop new4 = malloc(sizeof(linklistloop));
    new4->data = 4;
    new4->next = NULL;
    insert_node(new2,new4);
    treverse_list(mylist);
    len = list_len(mylist);
    printf("链表长度： %d\n\r",len);
    
     printf("\n\r");
     
    move_node(new2,new4);
    treverse_list(mylist);
    len = list_len(mylist);
    printf("链表长度： %d\n\r",len);
    
    printf("\n\r");
    
    find_node(mylist,4);
    
    return 0;    
}






