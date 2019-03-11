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
	
	printf("ɾ��������ֵΪ2�Ľڵ�!\n");
	PurgeItem(&pHead,2);
	Traverse(pHead);
	
	return 0;
}

pNode initList(void)
{
	pNode pHead;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	
	printf("�����ʼ���ɹ�!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	pNode pHead;
	int len;
	int val,i;
	
	pHead = *pPhead;
	
	printf("����������ĳ���:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("�������%d���ڵ����ֵ:",i + 1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pHead = pNew;
		pNew->pNext = NULL;
	}
	printf("�������ɹ�!\n");
	
	return;
}

void Traverse(pNode pHead)
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
	printf("�����нڵ�Ϊ%d��ֵȫ��ɾ��!\n",item);
	
	return;
}

/*

2018��10��10��15:13:15

�ܽ᣺
	ɾ���ڵ���ֵΪitem��Ԫ�ء� 

*/
