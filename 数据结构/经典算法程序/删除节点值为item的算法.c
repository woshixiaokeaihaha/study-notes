# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node,* pNode;

pNode initList(void);
void CreateList(pNode *);
void Traverse(pNode);
void PurgeItem(pNode *,int);

int main(void) 
{
	pNode pHead;
	
	pHead = initList();
	
	CreateList(&pHead);
	
	Traverse(pHead);
	
	printf("删除链表中值为2的节点!\n");
	PurgeItem(&pHead,2);
	Traverse(pHead);
	
	return 0;
}

pNode initList(void)
{
	pNode pHead;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	
	printf("链表初始化成功!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	pNode pHead;
	int len;
	int val,i;
	
	pHead = *pPhead;
	
	printf("请输入链表的长度:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("请输入第%d个节点的数值:",i + 1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pHead = pNew;
		pNew->pNext = NULL;
	}
	printf("链表创建成功!\n");
	
	return;
}

void Traverse(pNode pHead)
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

void PurgeItem(pNode * pPhead,int item)
{
	pNode pHead = (*pPhead)->pNext;
	pNode pNew = *pPhead;
	
	while (pHead)
	{
		if (pHead->data == item)
		{
			pNew->pNext = pHead->pNext;
			free(pHead);
			pHead = pNew->pNext;
		}
		else
		{
			pNew = pHead;
			pHead = pHead->pNext;
		}
	}
	printf("链表中节点为%d的值全部删除!\n",item);
	
	return;
}

/*

2018年10月10日15:13:15

总结：
	删除节点中值为item的元素。 

*/
