#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node
{
	//Êý¾ÝÓò
	int date;
	//Ö¸ÕëÓò
	struct Node *next;
};


int main(void)
{
	struct Node node1={10,NULL};
	struct Node node2={20,NULL};
	struct Node node3={30,NULL};
	struct Node node4={40,NULL};
	struct Node node5={50,NULL};

	node1.next=&node2;
	node2.next=&node3;
	node3.next=&node4;
	node4.next=&node5;

	struct Node* pcurrent= &node1;
	while(pcurrent != NULL)
	{
		
		pcurrent= pcurrent->next;
	};
	system("pause");
	return 0;
	
};
