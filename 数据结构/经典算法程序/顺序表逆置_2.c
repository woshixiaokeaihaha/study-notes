# include <stdio.h>
# include <stdlib.h>

int main(void)
{
	int len,i,t;
	int * pArr;
	
	printf("请输入数组的长度:len = ");
	scanf("%d",&len);
	
	pArr = (int *)malloc(sizeof(int) * len);
	
	for (i = 0;i < len;i++)
	{
		printf("请输入第%d个元素:",i + 1);
		scanf("%d",pArr + i);
	}
	
	for (i = 0;i < len/2;i++)
	{
		t = pArr[i];
		pArr[i] = pArr[len-1-i];
		pArr[len-1-i] = t;
	}
	
	printf("顺序表逆序之后的顺序是:\n");
	for (i = 0;i < len;i++)
	{
		printf("%d  ",pArr[i]);
	}
	printf("\n");
	
	return 0;
}
