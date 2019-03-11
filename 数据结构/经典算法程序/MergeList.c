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
pNode MergeList(pNode,pNode);

int main(void)
{
	pNode pHead1;
	pNode pHead2;
	pNode pHead3; 
	
	pHead1 = InitList();
	pHead2 = InitList();
	
	CreateList(&pHead1);
	CreateList(&pHead2);
	
	TraverseList(pHead1); 
	TraverseList(pHead2);
	
	pHead3 = MergeList(pHead1,pHead2);
	TraverseList(pHead3);

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

pNode MergeList(pNode pHead1,pNode pHead2)
{
	pNode pHead3,p,q,r;
	
	p = pHead1->pNext;
	q = pHead2->pNext;
	pHead3 = (pNode)malloc(sizeof(Node));
	
	if (p->data <= q->data)
	{
		pHead3->pNext = p;
		r = p;
		p = p->pNext;
	}
	else
	{
		pHead3->pNext = q;
		r = q;
		q = q->pNext;
	}
	
	while (p && q)
	{
		if (p->data <= q->data)
		{
		r->pNext = p;
		r = p;
		p = p->pNext;
		}
		else
		{
		r->pNext = q;
		r = q;
		q = q->pNext;
		}
	}
	
	r->pNext = (p != NULL)? p:q;
	
	printf("����ϲ����!\n");
	
	return pHead3;
}

