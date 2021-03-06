# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node,* pNode;

pNode InitList(void);
void CreateList(pNode *);
void TraverseList(pNode);
pNode CopyList(pNode);

int main(void)
{
	pNode pHead;
	pNode pHead2;

	pHead = InitList();

	CreateList(&pHead);
	TraverseList(pHead);

	pHead2 = CopyList(pHead);
	TraverseList(pHead2);

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

pNode CopyList(pNode pHead)
{
	pNode pHead2 = (pNode)malloc(sizeof(Node));

	pHead = pHead->pNext;

	if (pHead == NULL)
	{
		return NULL;
	}
	else
	{
		pHead2->data = pHead->data;
		pHead2->pNext = CopyList(pHead->pNext);
		return pHead2;
	}


}



/*
*/
