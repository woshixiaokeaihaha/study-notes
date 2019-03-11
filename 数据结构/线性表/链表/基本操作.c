# include <stdio.h>
# include <stdlib.h>

# define true 1
# define false 0

typedef struct Node
{
	int data;
	struct Node * pNext;
}Node,* LinkList;

void initList(LinkList *);
int ListEmpty(LinkList);
int GetElem(LinkList,int,int *);
int CreateList(LinkList *);
void ListTraverse(LinkList);
void ListInsert(LinkList *,int,int);
int ListDelete(LinkList *,int,int *);
//int ListLength(SqList,int *);

int main(void)
{
	LinkList pHead;
	int val;

	initList(&pHead);

    CreateList(&pHead);

	GetElem(pHead,2,&val);
	printf("��%d��Ԫ����%d\n",2,val);
	
	ListTraverse(pHead);
	
	ListInsert(&pHead,2,90);
	
	GetElem(pHead,2,&val);
	printf("��%d��Ԫ����%d\n",2,val);
	
	ListTraverse(pHead);
	
	ListDelete(&pHead,2,&val);
	
	ListTraverse(pHead);

	return 0;
}

void initList(LinkList * pHead)
{
	* pHead = (LinkList)malloc(sizeof(Node));

	(*pHead)->pNext = NULL;

	printf("�����ʼ�����!\n");

	return;
}

int CreateList(LinkList * pHead)
{
    int val;
    int len;
    int i;
    LinkList pL,pNew;

    pL = *pHead;

    printf("��������Ҫ��������ĳ���:len = ");
    scanf("%d",&len);

    for (i = 0;i < len;i++)
    {
        pNew = (LinkList)malloc(sizeof(Node));

        printf("�������%d���ڵ����ֵ,val = ",i + 1);
        scanf("%d",&val);

        pNew->data = val;
        pL->pNext = pNew;
        pL = pNew;
        pNew->pNext = NULL;
    }

    printf("���������!\n");

    return true;
}

int ListEmpty(LinkList pHead)
{
	if (pHead->pNext == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int GetElem(LinkList pHead,int pos,int * pVal)
{
	int cnt = 1;

	if (ListEmpty(pHead))
	{
		return false;
	}
	else
	{
		LinkList pNew;

		pNew = pHead->pNext;

		while (cnt < pos && pNew)
		{
			pNew = pNew->pNext;
			cnt++;
		}

		if (pNew)
		{
			*pVal = pNew->data;

			return true;
		}
		else
		{
			return false;
		}
	}
}

void ListTraverse(LinkList pHead)
{
	LinkList pNew;
	
	printf("�����е�������:\n");
	
	pNew = pHead->pNext;
	
	while (pNew)
	{
		printf("%d  ",pNew->data);
		
		pNew = pNew->pNext;
	}
	printf("\n");
	
	return;
}

void ListInsert(LinkList * pHead,int pos,int val)
{
	LinkList pNew = (*pHead)->pNext;
	int cnt = 1;
	
	while (pNew && cnt < pos - 1)
	{
		cnt++;
		
		pNew = pNew->pNext;
	}
	
	if (!pNew)
	{
		return;
	}
	else
	{
		LinkList pNew2 = (LinkList)malloc(sizeof(Node));
		
		pNew2->data = val;
		pNew2->pNext = pNew->pNext;
		pNew->pNext = pNew2;
		
		return;
	}
	
	return;
}

int ListDelete(LinkList * pHead,int pos,int *pVal)
{
	if (ListEmpty(*pHead))
	{
		return false;
	}
	else
	{
		LinkList pL1,pL2;
		int cnt = 1;
		
		pL1 = (*pHead)->pNext;
		
		while (pL1 && cnt < pos - 1)
		{
			pL1 = pL1->pNext;
			cnt++;
		}
		
		pL2 = pL1->pNext;
		pL1->pNext = pL2->pNext;
		*pVal = pL1->data;
		
		printf("�����е�%d��Ԫ��%dɾ���ɹ�",pos,*pVal);
		
		free(pL2);
	}
}

