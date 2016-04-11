// Á½ÖÖCÊµÏÖµÄÃ°ÅÝÅÅÐòËã·¨£¬µÚÒ»ÖÖ±È½Ï³£¼ûµ«ÊÇÐ§ÂÊ±È½ÏµØÏÂ¡£
// µÚ¶þÖÖÕæÕýÊ¹ÓÃÏàÁÚÎ»ÖÃµÄ±È½ÏÊµÏÖÃ°ÅÝ£¬¶øÇÒ¿ÉÒÔÉèÖÃ±êÖ¾Î»À´
// ¼õÉÙ²»±ØÒªµÄ±È½Ï´ÎÊý¡£
#include <stdio.h>

void bubbleSort1(int num[],int length)
{
	int outerLoop, innerLoop,temp;
	int compareCount = 0, exchangeCount = 0;
	for(outerLoop = 0;outerLoop < length - 1;outerLoop++)
		for(innerLoop = outerLoop + 1;innerLoop < length;innerLoop++)
		{
			compareCount++;
			if(num[outerLoop] > num[innerLoop])
			{
				exchangeCount++;
				temp = num[outerLoop];
				num[outerLoop] = num[innerLoop];
				num[innerLoop] = temp;
			}
		}
	printf("campare time: %d, excahnge time: %d\n",
			compareCount, exchangeCount );
}

void bubbleSort2(int num[],int length)
{
	int flag = 1;
	int outerLoop, innerLoop,temp;
	int compareCount = 0, exchangeCount = 0;
	for(outerLoop = 0;outerLoop < length - 1 && flag;outerLoop++)
		for(innerLoop = length -1;innerLoop > outerLoop;innerLoop--)
		{
			compareCount++;
			flag = 0;
			//如果内循环上一轮没有比较的话说明剩余的数字是排好序的
			//这时就可以停止排序了，所以在外层循环结束条件那里加了flag判断
			if(num[innerLoop - 1] > num[innerLoop])
			{
				exchangeCount++;
				flag = 1;
				temp = num[innerLoop];
				num[innerLoop] = num[innerLoop - 1];
				num[innerLoop - 1] = temp;
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

	bubbleSort1(num1,length1);
	printf("after bubbleSort1 the nums are:");
	printNums(num1,length1);

	int num2[] = {5,2,6,0,3,9,1,7,4,8};
	int length2 = sizeof(num2)/sizeof(int);
	bubbleSort2(num2,length2);
	printf("after bubbleSort2 the nums are:");
	printNums(num2,length2);	

	return 0;
}