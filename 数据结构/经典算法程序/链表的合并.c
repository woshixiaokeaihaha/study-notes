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
	
	pHead3 = MergeList(pHead1->pNext,pHead2->pNext);
	TraverseList(pHead3);

			
} 

pNode InitList(void)
{
	pNode pHead;
	
	pHead = (pNode)malloc(sizeof(Node));
	pHead->pNext = NULL;
	
	printf("链表初始化完成!\n");
	
	return pHead;
}

void CreateList(pNode * pPhead)
{
	int len,val,i;
	pNode pHead;
	
	pHead = *pPhead;
	
	printf("请输入链表的长度:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i ++)
	{
		printf("请输入第%d个节点的数值:",i + 1);
		scanf("%d",&val);
		
		pNode pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		pHead->pNext = pNew;
		pNew->pNext = NULL;
		pHead = pNew;
	}
	printf("链表创建完成!\n");
	
	return;
}

void TraverseList(pNode pHead)
{
	pNode pNew = pHead->pNext;
	
	printf("链表中的元素是:\n");
	
	while (pNew)
	{
		printf("%d  ",pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
	
	return;
}

pNode MergeList(pNode pA,pNode pB)
{
	pNode pHead,p,q,r;
	
	p = pA;
	q = pB;
	pHead = (pNode)malloc(sizeof(Node));
	
	if (pA->data <= pB->data)
	{
		pHead->pNext = pA;	//不加pNext读不到第一个节点！ 
		r = pA;
		p = p->pNext;
	}
	else
	{
		pHead->pNext = pB;
		r = pB;
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
	
	r->pNext = (p != NULL) ? p:q;
	
	return pHead;
}

/*

2018年10月10日16:43:28

总结:
	该程序实现的是单链表的合并，只是存在一个小问题， 

*/
