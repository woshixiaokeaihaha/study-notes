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
//int ListDelete(SqList *,int,int *);
//int ListLength(SqList,int *);

int main(void)
{
	LinkList pHead;
	int val;

	initList(&pHead);

    CreateList(&pHead);

	GetElem(pHead,2,&val);
	printf("��%d��Ԫ����%d\n",2,val);

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
