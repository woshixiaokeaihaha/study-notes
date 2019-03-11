# include <stdio.h>
# include <stdlib.h>

typedef struct Node
{
	char data;
	struct Node *lchild,*rchild;
}Node,*pNode;

void CreateBiTree(pNode *);
void PreOrderTraverse(pNode,int);
int Depth(pNode);

int main(void)
{
	pNode pT;
	int level = 1,deepth;
	
	CreateBiTree(&pT);
	
	PreOrderTraverse(pT,level);
	
	deepth = Depth(pT);
	printf("�ö������������%d",deepth);
	
	return 0;
}

void CreateBiTree(pNode * pT)
{
	char c;
	
	scanf("%c",&c);
	
	if (' ' == c)
	{
		*pT = NULL;
	}
	else
	{
		*pT = (pNode)malloc(sizeof(Node));
		(*pT)->data = c;
		CreateBiTree(&((*pT)->lchild));
		CreateBiTree(&((*pT)->rchild));
	}
	
	return;
}

void visit(char,int);

void PreOrderTraverse(pNode pT,int level)
{
	if (pT)
	{
		visit(pT->data,level);
		PreOrderTraverse(pT->lchild,level+1);
		PreOrderTraverse(pT->rchild,level+1);
	}
	
	return;
}

void visit(char c,int level)
{
	printf(" %c λ�ڵ� %d ��\n",c,level);
	
	return;
}

int Depth(pNode pHead)
{
	int ldepth,rdepth;
	
	
	if (pHead)
	{
		return 0;
	}
	else
	{
		ldepth = Depth(pHead->lchild);
		rdepth = Depth(pHead->rchild);
		
		if (ldepth > rdepth)
		{
			return ldepth+1;
		}
		else
		{
			return rdepth+1;
		}
	}
}
