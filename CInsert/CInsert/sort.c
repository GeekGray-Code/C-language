#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"sort.h"


/*�����㷨 ���Ժ���*/
void sortTest()
{
	
	//sortBubbleTest();
	//sortSelectTest();
}




/*********************************************ð������***************************************************************/

/*
ð�����򣨴�С����
ʱ�临�Ӷȣ�O(n^2)
�ռ临�Ӷȣ�O(1)

�������У�1��
�Ƚϴ���Ϊ��n-1 ��
�ƶ�Ԫ�ش�����0

�������У�n-1������
�Ƚϴ���Ϊ����n^2-n��/2
�ƶ�Ԫ�ش�����3��n^2-n��/2
*/
void sortBubble(int arr[], int len)
{
	int temp;

	for (int i = 0; i < len-1; i++)		//ִ��n-1������
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j]>arr[j+1])		//���ݽ�������С����
			{
				temp = arr[j+1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}


/*
ð�����򣨸Ľ���
���㷨������һ����־����flag���涨��flagΪ1ʱ��˵����������Ȼ��Ԫ�ؽ����Ķ���������Ҫ������һ�˵ıȽ�
��flagΪ0ʱ��˵���������Ѿ�û��Ԫ�صĽ�����ֻ��Ԫ�صıȽϣ�
*/
void sortBubblePlus(int arr[], int len)
{
	int temp;
	int flag = 1;

	for (int i = 0; i < len - 1 && flag==1; i++)		//ִ��n-1������
	{
		flag = 0;

		for (int j = 0; j < len - 1-i; j++)
		{
			if (arr[j]>arr[j + 1])		//���ݽ�������С����
			{
				temp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = temp;
				flag = 1;				//�������ݽ���ʱ��flag��1
			}
		}
	}
}


void sortBubbleTest()
{
	int arr[10];
	
	printf("������10������\n");
	for (int i = 0; i < 10; i++)		//forѭ���Ӽ��̶���10����
	{
		scanf("%d", &arr[i]);
	}

	printf("����ǰ��ԭ���У�\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}
	printf("\n��ʼ����......");

	//sortBubble(arr,10);
	sortBubblePlus(arr, 10);

	printf("���������У�\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	printf("\n");
}



/*********************************************ѡ������***************************************************************/
/*
ѡ�����򣨴�С����
��i����������еĺ� n-i+1 ��Ԫ����ѡ��һ����С��Ԫ�أ�
��� n-i+1 ��Ԫ�ص���ǰ����Ǹ�Ԫ�ؽ���λ�ý�����Ҳ������� i ��λ���ϵ�Ԫ�ؽ��н�����ֱ�� i=n-1
ÿһ�˵�ѡ��������Ǵ�������δ�ź�˳���Ԫ����ѡ��һ����С��Ԫ�أ�
����Ԫ������Щδ�ź�˳���Ԫ�صĵ�һ��Ԫ�ؽ���λ��

*/
void sortSelect(int arr[], int len)
{
	int minIndex,temp;

	for (int i = 0; i < len-1; i++)
	{
		minIndex = i;

		for (int j = i+1; j < len; j++)	//�ں� n-i+1 ��Ԫ�����ҵ���С��Ԫ��λ��
		{
			if (arr[minIndex]>arr[j])
			{
				minIndex = j;			//��minIndex��¼��СԪ�ص�λ��
			}
		}

		//����Сֵ�滻Ϊ������˵����ֲ��������򣬼�����arr[i+1]~a[10]����Сֵ��arr[i]�Ի�
		if (minIndex!=i)				//�����С��Ԫ�ز�λ�� n-i+1 ��Ԫ�صĵ�һ��
		{
			temp = arr[minIndex];
			arr[minIndex] = arr[i];		//Ԫ�ؽ���
			arr[i] = temp;
		}
	}
}


/*��ѡ�������10����������*/
void sortSelectTest()
{
	int i, j;
	int minIndex, temp;
	int arr[10];

	printf("������10��������\n");
	for (i = 0; i < 10; i++)//����10����
	{
		printf("arr[%d]=", i);
		scanf("%d", &arr[i]);
	}

	printf("\n");
	printf("ԭ���У� \n");

	for (i = 0; i < 10; i++)			//���δ�����10����
	{
		printf("%5d", arr[i]);
	}

	printf("\n��ԭ���н�������...\n");

	//for (i = 1; i <= 9; i++)
	//{
	//	minIndex = i;					//��ʼ����Сֵ����minIndex
	//	for (j = i + 1; j <= 10; j++)	//�����������в��ҵ���Сֵ
	//	{
	//		if (arr[minIndex]>arr[j])
	//		{
	//			minIndex = j;			//�ҵ���Сֵ����
	//		}
	//	}

	//	//����Сֵ�滻Ϊ������˵����ֲ��������򣬼�����arr[i+1]~a[10]����Сֵ��arr[i]�Ի�
	//	temp = arr[i];
	//	arr[i] = arr[minIndex];
	//	arr[minIndex] = temp;
	//}

	sortSelect(arr,10);

	printf("\n���ź�������У�\n");
	for (i = 0; i < 10; i++)
	{
		printf("%5d", arr[i]);
	}

	printf("\n");
}