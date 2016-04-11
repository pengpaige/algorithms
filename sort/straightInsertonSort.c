/*
直接插入排序

*/
#include <stdio.h>

void straightInsertSort(int num[], int length)
{
	int temp, outerLoop, innerLoop;
	int counter;
	for(outerLoop = 1; outerLoop < length; outerLoop++)
	{
		counter = 0;
		if(num[outerLoop - 1] > num[outerLoop])
		{
			temp = num[outerLoop];
			for(innerLoop = outerLoop; 
				temp < num[innerLoop - 1]&&innerLoop >= 1; innerLoop--)
			{	
				counter++;
				num[innerLoop] = num[innerLoop - 1];
				printf("innerLoop=%d ", innerLoop);
			}
			num[innerLoop] = temp;
		}
		printf(" %d\n", counter);
	}
}

void printNums(int num[], int length)
{
	int loop;
	for(loop = 0; loop < length; loop++)
		printf("%d ",num[loop]);
	printf("\n");
}

int main()
{
	int num[] = {5,2,6,0,3,9,1,7,4,8};
	int length = sizeof(num)/sizeof(int);

	straightInsertSort(num,length);
	printf("after selectSort1 the nums are:");
	printNums(num,length);
	printf("%d\n", 3/2);
	// printf(" %d\n", num[-1]);
	// printf(" %d\n", num[11]);

	// int num2[] = {5,2,6,0,3,9,1,7,4,8};
	// int length2 = sizeof(num2)/sizeof(int);
	// bubbleSort2(num2,length2);
	// printf("after bubbleSort2 the nums are:");
	// printNums(num2,length2);	

	return 0;
}