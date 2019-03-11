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
	
	printf("�����ʼ�����!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	int len,val,i;
	pNode pHead;
	
	pHead = *pPhead;
	
	printf("����������ĳ���:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i ++)
	{
		printf("�������%d���ڵ����ֵ:",i + 1);
		scanf("%d",&val);
		
		pNode pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pNew->pNext = NULL;
		pHead = pNew;
	}
	printf("���������!\n");
	
	return;
}

void TraverseList(pNode pHead)
{
	pNode pNew = pHead->pNext;
	
	printf("�����е�Ԫ����:\n");
	
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
	pNode pHead2 = InitList();
	pNode p,p1,pNew;
	
	p1 = pHead2;
	p = pHead->pNext;
	
	while (p)
	{
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = p->data;
		p1->pNext = pNew;
		p1 = pNew;
		p = p->pNext;
	}
	p1->pNext = NULL;
	
	return pHead2; 
	
}

/*

2018��10��10��16:11:24

�ܽ�:
	�ǵݹ�ʵ������Ŀ����� 

*/
