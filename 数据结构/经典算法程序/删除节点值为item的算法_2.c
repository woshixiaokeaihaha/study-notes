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
void Delete_Item(pNode *,int);

int main(void)
{
	pNode pHead;
	
	pHead = InitList();
	
	CreateList(&pHead);
	
	TraverseList(pHead);
	
	Delete_Item(&pHead,2);
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

void Delete_Item(pNode * pPhead,int val)
{
	pNode pHead = *pPhead;
	pNode pNew = pHead->pNext; 
	
	while (pNew)
	{
		if (pNew->data == val)
		{
			pHead->pNext = pNew->pNext;
			
			free(pNew);
			
			pNew = pHead->pNext;
		}
		else
		{
			pHead = pNew;
			pNew = pNew->pNext;
		}
	}
	
	printf("链表中值为%d的节点已经成功删除!\n",val);
	
	return;
}
