# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node,* pNode;

pNode initList(void);
void CreateList(pNode *);
void TraverseList(pNode);
void ReverseList(pNode *);

int main(void)
{
	pNode pHead;
	
	pHead = initList();
	
	CreateList(&pHead);
	TraverseList(pHead);
	
	ReverseList(&pHead);
	TraverseList(pHead);
	
	return 0;	
} 

pNode initList(void)
{
	pNode pHead;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	
	printf("链表初始化完成!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	int len,val,i;
	pNode pHead;
	
	pHead = *pPhead;
	
	printf("请输入链表的长度:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i ++)
	{
		printf("请输入第%d个节点的数值:",i + 1);
		scanf("%d",&val);
		
		pNode pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pNew->pNext = NULL;
		pHead = pNew;
	}
	printf("链表创建完成!\n");
	
	return;
}

void TraverseList(pNode pHead)
{
	pNode pNew = pHead->pNext;
	
	printf("链表中的元素是:\n");
	
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
	pNode p1,p2;
	
	printf("开始倒置链表中的元素!\n");
	
	p1 = (*pPhead)->pNext;
	(*pPhead)->pNext = NULL;
	
	while (p1)
	{
		p2 = p1;
		p1 = p1->pNext;
		
		p2->pNext = (*pPhead)->pNext;
		(*pPhead)->pNext = p2;
	}
	printf("倒置完成!\n");
	
	return;
}

/*

2018年10月10日15:26:38

总结:
	倒置链表中的元素(带有头结点) 
*/
