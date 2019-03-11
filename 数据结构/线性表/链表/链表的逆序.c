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
int CreateList(LinkList *);
void Reaverse(LinkList *);
void Traverse(LinkList);

int main(void)
{
	LinkList pHead;
	int val;

	initList(&pHead);

    CreateList(&pHead);
    
    Reaverse(&pHead);
    
    Traverse(pHead);

	return 0;
}

void initList(LinkList * pHead)
{
	* pHead = (LinkList)malloc(sizeof(Node));

	(*pHead)->pNext = NULL;

	printf("链表初始化完成!\n");

	return;
}

int CreateList(LinkList * pHead)
{
    int val;
    int len;
    int i;
    LinkList pL,pNew;

    pL = *pHead;

    printf("请输入需要创建链表的长度:len = ");
    scanf("%d",&len);

    for (i = 0;i < len;i++)
    {
        pNew = (LinkList)malloc(sizeof(Node));

        printf("请输入第%d个节点的数值,val = ",i + 1);
        scanf("%d",&val);

        pNew->data = val;
        pL->pNext = pNew;
        pL = pNew;
        pNew->pNext = NULL;
    }

    printf("链表创建完成!\n");

    return true;
}

void Reaverse(LinkList * pHead)
{
	LinkList p1,p2;
	
	p1 = (*pHead)->pNext;
	(*pHead)->pNext = NULL;
	
	while (p1)
	{
		p2 = p1;
		p1 = p1->pNext;
		
		p2->pNext = (*pHead)->pNext;
		(*pHead)->pNext = p2;
		
	}
	
	printf("就地逆置成功!\n");
	
	return;
}

void Traverse(LinkList pHead)
{
	printf("链表中内容是:\n");
	
	LinkList pNew;
	
	pNew = pHead->pNext;
	
	while (pNew)
	{
		printf("%d  ",pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
	
	return;
}
