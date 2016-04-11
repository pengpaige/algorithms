/*
选择排序
与（没有优化过的）冒泡排序相比，比较次数是一样的，但是交换次数更少
*/
#include <stdio.h>

void selectSort1(int num[], int length)
{
	int outerLoop, innerLoop, temp;
	int minIndex;
	int compareCount = 0, exchangeCount = 0;
	for(outerLoop = 0; outerLoop < length - 1; outerLoop++)
	{
		minIndex = outerLoop;
		for(innerLoop = outerLoop + 1; innerLoop < length; innerLoop++)
		{
			compareCount++;
			if(num[minIndex] > num[innerLoop])
				minIndex = innerLoop;
		}
		if(outerLoop != minIndex)
		{
			exchangeCount++;
			temp = num[outerLoop];
			num[outerLoop] = num[minIndex];
			num[minIndex] = temp;
		}
	}
	printf("campare time: %d, excahnge time: %d\n",
			compareCount, exchangeCount );
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
	int num1[] = {5,2,6,0,3,9,1,7,4,8};
	int length1 = sizeof(num1)/sizeof(int);

	selectSort1(num1,length1);
	printf("after selectSort1 the nums are:");
	printNums(num1,length1);

	// int num2[] = {5,2,6,0,3,9,1,7,4,8};
	// int length2 = sizeof(num2)/sizeof(int);
	// bubbleSort2(num2,length2);
	// printf("after bubbleSort2 the nums are:");
	// printNums(num2,length2);	

	return 0;
}