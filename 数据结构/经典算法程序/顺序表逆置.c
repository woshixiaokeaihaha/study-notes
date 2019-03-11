# include <stdio.h>

void Reverse(int [],int);

int main(void)
{
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	int i;
	
	printf("顺序表倒置之前的顺序是:\n");
	
	for (i = 0;i < 10;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	
	Reverse(a,10);
	
	printf("倒置之后的顺序是:\n");
	
	for (i = 0;i < 10;i++)
	{
		printf("%d  ",a[i]);
	}
	printf("\n");
	
	return 0;
}

void Reverse(int a[],int len)
{
	int i;
	int t;
	
	for (i = 0;i < len/2;i++)
	{
		t = a[i];
		a[i] = a[len - 1 - i];
		a[len - 1 - i] = t;
	}
	
	return;
}

/*

2018年10月10日14:51:23

总结：
	顺序表的倒置。 

*/
