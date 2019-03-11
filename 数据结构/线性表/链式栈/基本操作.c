# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node *pNext;
}Node,* pNode;

typedef struct LinkStack
{
	pNode  pTop;
	pNode pBottom;
}Stack,* pStack;

void InitStack(pStack);
void Push(pStack,int);
void Pop(pStack,int *);
bool StackEmpty(pStack);
int StackLength(Stack);
void StackTraverse(Stack);


int main(void)
{
	Stack pHead;
	int val;
	int len;
	
	InitStack(&pHead);
	
	Push(&pHead,4);
	Push(&pHead,5);
	Push(&pHead,6);
	Push(&pHead,7);
	
	Pop(&pHead,&val);
	
	len = StackLength(pHead);
	printf("栈的长度是%d\n",len);
	
	StackTraverse(pHead);

	return 0;
}

void InitStack(pStack pHead)
{
	pHead->pTop = (pNode)malloc(sizeof(Node));
	pHead->pBottom = pHead->pTop;
	
	pHead->pTop->pNext = NULL;
	
	printf("栈初始化完成!\n");
	
	return;
}

void Push(pStack pHead,int val)
{
	pNode pNew;
	
	pNew = (pNode)malloc(sizeof(Node));
	
	pNew->data = val;
	pNew->pNext = pHead->pTop;
	pHead->pTop = pNew;
	
	printf("%d入栈成功!\n",val);
	
	return;
}

bool StackEmpty(pStack pHead)
{
	if (pHead->pTop == pHead->pBottom)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Pop(pStack pHead,int * pVal)
{
	if (StackEmpty(pHead))
	{
		return;
	}
	else
	{
		pNode pNew;
		
		pNew = pHead->pTop;
		*pVal = pNew->data;
		pHead->pTop = pNew->pNext;
		
		printf("栈顶元素%d成功出栈!\n",*pVal);
		
		free(pNew);
	}
}

int StackLength(Stack S)
{
	pNode pNew = (pNode)malloc(sizeof(Node));
	int len = 0;
	
	pNew = S.pTop;
	
	while (pNew != S.pBottom)
	{
		len++;
		pNew = pNew->pNext;
	}
	
	return len;
}

void StackTraverse(Stack S)
{
	pNode pNew;
	
	printf("链表中的元素是:\n");
	
	pNew = (pNode)malloc(sizeof(Node));
	pNew = S.pTop;
	
	while (pNew != S.pBottom)
	{
		printf("%d  ",pNew->data);
		pNew = pNew->pNext;
	}
	printf("\n");
	
	return;
}
