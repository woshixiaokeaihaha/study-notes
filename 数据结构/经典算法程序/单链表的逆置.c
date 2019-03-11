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

void ReverseList(pNode * pPhead)
{
	pNode p1,p2;
	
	printf("��ʼ���������е�Ԫ��!\n");
	
	p1 = (*pPhead)->pNext;
	(*pPhead)->pNext = NULL;
	
	while (p1)
	{
		p2 = p1;
		p1 = p1->pNext;
		
		p2->pNext = (*pPhead)->pNext;
		(*pPhead)->pNext = p2;
	}
	printf("�������!\n");
	
	return;
}

/*

2018��10��10��15:26:38

�ܽ�:
	���������е�Ԫ��(����ͷ���) 
*/
