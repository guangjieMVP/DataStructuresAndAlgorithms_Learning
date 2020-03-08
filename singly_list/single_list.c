#include "stdio.h"
#include <stdlib.h>

//单向非循环链表
typedef struct node
{
    int data;
    struct node *next;
}list_node,*single_list;

//init a list
single_list init_list(void)
{
    single_list mylist = malloc(sizeof(list_node));
    if(mylist == NULL)
    {
        printf("init failed\n");
        return;
    }
    mylist->next = NULL;
    return mylist;
}

char is_empty(single_list mylist)
{
	if(mylist->next == NULL)
	{
		return 1;
	}

	return 0;
}

//插入节点
char insert_node(single_list p,single_list new)
{
    if(p == NULL || new == NULL)
    {
        return 0;
    }
    
    new->next = p->next;
    p->next = new;

	return 1;
}

//删除节点
char  delete_node(single_list mylist,single_list delete)
{
	if(is_empty(mylist))
	{
		printf("list is empty\n\r");
		return 0;
	}

	if(delete == NULL)
	{
		return 0;
	}

	single_list p = mylist->next;
	single_list pprev = NULL;
	while(NULL != p)
	{
		if(p->data == delete->data)
		{
			break;
		}
		pprev = p;//存放删除节点的上一个节点
		p = p->next;
	}

	if(p == NULL)
	{
		return 0;
	}

	p->next = NULL;
	pprev->next = NULL;
	
	free(delete);

	return 1;
}

//根据制定的数据找到相应的节点
single_list find_node(single_list mylist,int data)
{
	if(is_empty(mylist))
	{
		printf("mylist is empty\n\r");
		return;
	}

	single_list p = mylist->next;
	while(NULL != p)
	{
		if(p->data == data)
		{
			printf("have found: data: %d p->data: %d\n\r",data,p->data);//打印找的数据和找到的数据
			break;
		}

		p = p->next;
	}

	if(p == NULL)
	{
		return NULL;
	}
	
	return p;  //返回找到的节点的地址
}

//遍历链表
void bianli(single_list mylist)
{
	single_list p = mylist->next;
	while(p != NULL)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

int main(int argc,char **argv)
{
	single_list mylist = init_list();

	single_list new1 = malloc(sizeof(list_node));
	new1->data = 2;
	new1->next = NULL;
	insert_node(mylist,new1);

	single_list new2 = malloc(sizeof(list_node));
	new2->data = 3;
	new2->next = NULL;
	insert_node(new1,new2);

	single_list new3 = malloc(sizeof(list_node));
	new3->data = 4;
	new3->next = NULL;
	insert_node(new2,new3);
	
	bianli(mylist);

	printf("\n\r");

	delete_node(mylist,new3);
	bianli(mylist);
	printf("\n\r");

	find_node(mylist,3);

	return 0;
}




