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
	
	printf("�����ʼ�����!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	pNode pHead;
	int i,len,val;
	
	pHead = *pPhead;
	
	printf("����������ĳ���:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("�������%d���ڵ����ֵ:",i+1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pHead = pNew;
		pNew->pNext = NULL;
	}
	printf("���������!\n");
	
	return;
}

void TraverseList(pNode pHead)
{
	pNode pNew = pHead->pNext;
	
	printf("�����е�������:\n");
	
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
	printf("�����������!\n");
	
	return;
}

//����ʵ�� 
pNode CopyList(pNode pHead)
{
	pNode pHead2,p2;
	pNode pNew2,pNew;
	
	pNew = pHead->pNext;
	p2 = pHead2 = InitList();
	
	while (pNew) 
	{
		pNew2 = (pNode)malloc(sizeof(Node));
		pNew2->data = pNew->data;
		p2->pNext = pNew2;
		p2 = pNew2;
		pNew2->pNext = NULL;
		pNew = pNew->pNext;
	}
	printf("�������ɹ�!\n");
	
	return pHead2;
}



