# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node, *pNode;

pNode InitList(void);
void CreateList(pNode *);
void TraverseList(pNode);
void ReverseList(pNode *);

int main(void)
{
	pNode pHead;
	
	pHead = InitList();
	
	CreateList(&pHead);
	
	TraverseList(pHead);
	
	ReverseList(&pHead);
	TraverseList(pHead);

	return 0;
}

pNode InitList(void)
{
	pNode pHead;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	
	printf("链表初始化完成!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	pNode pHead;
	int i,len,val;
	
	pHead = *pPhead;
	
	printf("请输入链表的长度:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("请输入第%d个节点的数值:",i+1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pHead = pNew;
		pNew->pNext = NULL;
	}
	printf("链表创建完成!\n");
	
	return;
}

void TraverseList(pNode pHead)
{
	pNode pNew = pHead->pNext;
	
	printf("链表中的内容是:\n");
	
	while (pNew) 
	{
		printf("%d  ",pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
	
	return;
}

void ReverseList(pNode * pPhead)
{
	pNode p = (*pPhead)->pNext;
	pNode q;
	
	(*pPhead)->pNext = NULL;
	
	while (p)
	{
		q = p;
		p = p->pNext;
		
		q->pNext = (*pPhead)->pNext;
		(*pPhead)->pNext = q;
	}
	printf("链表逆置完成!\n");
	
	return;
}

/*

2018年10月14日19:52:06

总结：
	带有头结点的链表的就地逆置。 

*/


