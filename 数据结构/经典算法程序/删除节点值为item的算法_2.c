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
	
	printf("������ֵΪ%d�Ľڵ��Ѿ��ɹ�ɾ��!\n",val);
	
	return;
}
