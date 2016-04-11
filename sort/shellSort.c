/*
希尔排序（分组插入排序）
*/
#include <stdio.h>
/*
直接修改直接插入排序的代码，将全部涉及到间隔和起始位置的地方
都改为每一趟希尔排序的步长
*/

void shellSort(int num[], int length)
{
	int temp, outerLoop, innerLoop, step;
	do{
		//这里如果将步长每次减半再加1，如果出现步长step等于2的情况 
		// step = step / 2 + 1 将会一直等于2，while将会死循环
		// if(step == 2) step = 1;
		// else step = step / 2 + 1;
		step = length / 2;
		printf("%d\n", step);
		for(outerLoop = step; outerLoop < length; outerLoop++)
		{
			if(num[outerLoop - step] > num[outerLoop])
			{
				temp = num[outerLoop];
				for(innerLoop = outerLoop; 
					temp < num[innerLoop - step]&&innerLoop >= step; 
					innerLoop-=step)
				{
					num[innerLoop] = num[innerLoop - step];
				}
				num[innerLoop] = temp;
			}
		}
	}while(step > 1);
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

	shellSort(num,length);
	printf("after shellSort the nums are:");
	printNums(num,length);
	return 0;
}