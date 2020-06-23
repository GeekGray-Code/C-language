#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"sort.h"


/*排序算法 测试函数*/
void sortTest()
{
	
	//sortBubbleTest();
	//sortSelectTest();
}




/*********************************************冒泡排序***************************************************************/

/*
冒泡排序（从小到大）
时间复杂度：O(n^2)
空间复杂度：O(1)

正序排列：1趟
比较次数为：n-1 次
移动元素次数：0

逆序排列：n-1趟排序
比较次数为：（n^2-n）/2
移动元素次数：3（n^2-n）/2
*/
void sortBubble(int arr[], int len)
{
	int temp;

	for (int i = 0; i < len-1; i++)		//执行n-1趟排序
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j]>arr[j+1])		//数据交换，从小到大
			{
				temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


/*
冒泡排序（改进）
在算法中设置一个标志变量flag，规定当flag为1时，说明本趟中仍然有元素交换的动作，还需要进行下一趟的比较
当flag为0时，说明本趟中已经没有元素的交换，只有元素的比较，
*/
void sortBubblePlus(int arr[], int len)
{
	int temp;
	int flag = 1;

	for (int i = 0; i < len - 1 && flag==1; i++)		//执行n-1趟排序
	{
		flag = 0;

		for (int j = 0; j < len - 1-i; j++)
		{
			if (arr[j]>arr[j + 1])		//数据交换，从小到大
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 1;				//发生数据交换时，flag置1
			}
		}
	}
}


void sortBubbleTest()
{
	int arr[10];
	
	printf("请输入10个数：\n");
	for (int i = 0; i < 10; i++)		//for循环从键盘读入10个数
	{
		scanf("%d", &arr[i]);
	}

	printf("排序前的原数列：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}
	printf("\n开始排序......");

	//sortBubble(arr,10);
	sortBubblePlus(arr, 10);

	printf("排序后的数列：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	printf("\n");
}



/*********************************************选择排序***************************************************************/
/*
选择排序（从小到大）
第i趟排序从序列的后 n-i+1 个元素中选择一个最小的元素，
与该 n-i+1 个元素的最前面的那个元素进行位置交换，也就是与第 i 个位置上的元素进行交换，直到 i=n-1
每一趟的选择排序就是从序列中未排好顺序的元素中选择一个最小的元素，
将该元素与这些未排好顺序的元素的第一个元素交换位置

*/
void sortSelect(int arr[], int len)
{
	int minIndex,temp;

	for (int i = 0; i < len-1; i++)
	{
		minIndex = i;

		for (int j = i+1; j < len; j++)	//在后 n-i+1 个元素中找到最小的元素位置
		{
			if (arr[minIndex]>arr[j])
			{
				minIndex = j;			//用minIndex记录最小元素的位置
			}
		}

		//将最小值替换为列中左端的数字并进行排序，即：将arr[i+1]~a[10]中最小值与arr[i]对换
		if (minIndex!=i)				//如果最小的元素不位于 n-i+1 个元素的第一个
		{
			temp = arr[minIndex];
			arr[minIndex] = arr[i];		//元素交换
			arr[i] = temp;
		}
	}
}


/*用选择排序对10个整数排序*/
void sortSelectTest()
{
	int i, j;
	int minIndex, temp;
	int arr[10];

	printf("请输入10个整数：\n");
	for (i = 0; i < 10; i++)//输入10个数
	{
		printf("arr[%d]=", i);
		scanf("%d", &arr[i]);
	}

	printf("\n");
	printf("原数列： \n");

	for (i = 0; i < 10; i++)			//输出未排序的10个数
	{
		printf("%5d", arr[i]);
	}

	printf("\n对原数列进行排序...\n");

	//for (i = 1; i <= 9; i++)
	//{
	//	minIndex = i;					//初始化最小值索引minIndex
	//	for (j = i + 1; j <= 10; j++)	//线性搜索数列并找到最小值
	//	{
	//		if (arr[minIndex]>arr[j])
	//		{
	//			minIndex = j;			//找到最小值索引
	//		}
	//	}

	//	//将最小值替换为列中左端的数字并进行排序，即：将arr[i+1]~a[10]中最小值与arr[i]对换
	//	temp = arr[i];
	//	arr[i] = arr[minIndex];
	//	arr[minIndex] = temp;
	//}

	sortSelect(arr,10);

	printf("\n已排好序的数列：\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5d", arr[i]);
	}

	printf("\n");
}