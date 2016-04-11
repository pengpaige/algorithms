/*
堆排序
维护一个大根堆，每次排序将大根堆根节点放到数组末尾，
之后再筛选出新的大根堆，继续移动树根到末尾，直到排序完
*/
#include <stdio.h>
void printNums(int num[], int length);

void heapAdjust(int num[], int start, int end)
{
	int temp = num[start];
	int loop;
	for(loop = start * 2; loop <= end; loop *= 2)
	{
		if(loop < end && num[loop] < num[loop + 1])
			loop = loop + 1;
		if(temp >= num[loop])
		//这里是用temp和loop号元素交换，而不是start号元素和loop号元素交换
			break;
		num[start] = num[loop];
		start = loop;
	}
	num[start] = temp;
}

void swap(int num[], int indexA, int indexB)
{
	int temp = num[indexA];
	num[indexA] = num[indexB];
	num[indexB] = temp;
}

void heapSort(int num[], int length) 
{
	int loop;
	for(loop = length / 2; loop >= 1; loop--)
		heapAdjust(num, loop, length);
	for(loop = length; loop > 1; loop--)
	//这里loop大于1，不需要将1号元素和自己调换
	{
		swap(num, 1, loop);
		// printNums(num, length);
		heapAdjust(num, 1, loop - 1);
		printNums(num, length);
	}
}

void printNums(int num[], int length)
{
	int loop;
	for(loop = 1; loop <= length; loop++)
		printf("%d ",num[loop]);
	printf("\n");
}

int main()
{
	int num[] = {0,5,2,6,3,9,1,7,4,8};
	// 只对下标从1到9的元素排序
	int length = sizeof(num)/sizeof(int) - 1;

	heapSort(num,length);
	printf("after heapSort the nums are:");
	printNums(num,length);
	return 0;
}