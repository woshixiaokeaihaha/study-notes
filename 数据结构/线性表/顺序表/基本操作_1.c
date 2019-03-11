# include <stdio.h>

# define MAXSIZE 20
# define true 1
# define false 0


typedef struct List
{
	int data[MAXSIZE];
	int length;
}SqList;

void initList(SqList *);
int ListEmpty(SqList *);
int GetElem(SqList,int,int *);
int ListInsert(SqList *,int,int);
int ListDelete(SqList *,int,int *);
int ListLength(SqList,int *);

int main(void)
{
	SqList L;
	int val;
	int List_length;
	
	initList(&L);
	
	ListInsert(&L,1,2);
	ListInsert(&L,2,4);
	ListInsert(&L,3,7);
	ListInsert(&L,4,6);
	ListInsert(&L,5,8);
	
	ListLength(L,&List_length);
	
	GetElem(L,2,&val);
	
	printf("顺序表中第2个元素是%d\n",val);
	
	ListDelete(&L,2,&val);
	
	return 0;	
}

void initList(SqList * pL)
{
	pL->length = 0;
	
	printf("顺序表初始化完成!\n");
	
	return;
}

int ListEmpty(SqList * pL)
{
	if (pL->length == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int ListInsert(SqList * pL,int pos,int val)
{
	int i;
	
	if (pL->length == MAXSIZE)
		return false;
		
	if (pos < 1 || pos > pL->length + 1)
		return false;
		
	if (pos <= pL->length + 1)
	{
		for (i = pL->length - 1;i >= pos - 1;i--)
		{
			pL->data[i + 1] = pL->data[i];
		}
		pL->data[pos - 1] = val;
		pL->length += 1;
				
	}
	
	printf("%d元素成功插入顺序表!\n",val);
	
	return true;
}

int GetElem(SqList L,int pos,int * pVal)
{
	if (L.length == 0 || pos < 1 || pos > L.length)
		return false;
	
	*pVal = L.data[pos - 1];
		
	return true;
}

int ListDelete(SqList * pL,int pos,int * pVal)
{
	int i;
	
	if (ListEmpty(pL))
		return false;
		
	if (pos < 1 || pos > pL->length)
		return false;
		
	*pVal = pL->data[pos - 1];
	
	if (pos < pL->length)
	{
		for (i = pos;i < pL->length;i++)
		{
			pL->data[i - 1] = pL->data[i];
		}
		
		pL->length -= 1;
	}
	
	printf("第%d个位置的元素%d删除成功!\n",pos,*pVal);
}

int ListLength(SqList L,int *pLength)
{
	if (ListEmpty(&L))
		return 0;
	
	*pLength = L.length;
	
	printf("该顺序表的长度是%d\n",L.length);
	
	return L.length;
}

