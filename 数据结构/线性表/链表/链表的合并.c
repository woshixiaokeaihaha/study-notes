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
	printf("链表合并完成!\n");
	printf("合并之后的结果是:\n");
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
	
	printf("请输入创建链表的长度:len = ");
	scanf("%d",&len);
	
	for (i = 0;i < len;i++)
	{
		printf("请输入第%d个节点的数值:",i + 1);
		scanf("%d",&val);
		
		pNode pNew;
		
		pNew = (pNode)malloc(sizeof(Node));
		pNew->data = val;
		
		p1->pNext = pNew;
		p1 = pNew;
		pNew->pNext = NULL;
	}
	printf("链表创建成功!\n");
	
	return pHead;
}

void Traverse(pNode pHead)
{
	pNode pNew;
	
	printf("链表中的内容是:\n");
	
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
