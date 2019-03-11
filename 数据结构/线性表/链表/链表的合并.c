# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node,* pNode;

pNode CreateList();
void Traverse(pNode);
pNode MergeList(pNode,pNode);

int main(void)
{
	pNode pHead1,pHead2,pHead;
	
	pHead1 = CreateList();
	pHead2 = CreateList();
	
	Traverse(pHead1);
	Traverse(pHead2);
	
	pHead = MergeList(pHead1->pNext,pHead2->pNext);
	printf("����ϲ����!\n");
	printf("�ϲ�֮��Ľ����:\n");
	Traverse(pHead);
	
	return 0;
}

pNode CreateList()
{
	pNode pHead,p1;
	int len,val;
	int i;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	p1 = pHead;
	
	printf("�����봴������ĳ���:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("�������%d���ڵ����ֵ:",i + 1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		
		p1->pNext = pNew;
		p1 = pNew;
		pNew->pNext = NULL;
	}
	printf("�������ɹ�!\n");
	
	return pHead;
}

void Traverse(pNode pHead)
{
	pNode pNew;
	
	printf("�����е�������:\n");
	
	pNew = pHead;
	
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
	pNode pHead;
	
	pHead = NULL;
	
	if (!pHead1)
		return pHead2;
	
	if (!pHead2)
		return pHead1;
		
	if (pHead1->data < pHead2->data)
	{
		pHead = pHead1;
		pHead->pNext= MergeList(pHead1->pNext,pHead2);
	}
	else
	{
		pHead = pHead2;
		pHead->pNext = MergeList(pHead1,pHead2->pNext);
	}
	
	
	return pHead;
}
