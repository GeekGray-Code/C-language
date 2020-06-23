#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"program.h"


/*编程题 测试函数*/
void programTest()
{
	/*有1、2、3、4四个数字，能组成多少个互相无重复数字的三位数*/
	//codeNoDuplicationThreeDigitsBy1234();

	/*计算y=(m!)/(n!)(m-n!)*/
	//codeFactorial();

	/*韩师2016-5-1 编程题：求1+1/2+1/4+...+1/50的值，并输出结果*/
	//codeSequenceSum();

	/*从键盘输入20个学生的学号和一门课程成绩，统计计算全班平均成绩，并输出低于平均分的学生学号和成绩*/
	//codeStatisticalStudentGrade();

	//codeDivisible7();

	//codeMaximumAndMinimumOf10Numbers();

	//codeFormatPrint();

	//codeSequenceSumForPrac();

	//codeCourseScore();

	//codeCompareIntegerByPointer();

	//codeMyStrcat();

	//codeCalcPolynomialValue();
}



/************************************************************************************************************************/
/****************************************************编程题**************************************************************/

/*计算1-1、2+1/3-1/4+...+1/99-1/100+...，直到最后一项的绝对值小于1e-4为止*/
void codeCalcPolynomialValue()
{
	int i=1;
	float sum=0, sign=1.0;

	while ((1.0/i)>=1e-4)
	{
		sum += sign / i;
		i++;
		sign = -sign;
	}

	printf("sum=%f\n",sum);
}



/*广技师2017-5-2：编程完成两个字符串的连接（不使用strcat（）函数）*/
void codeMyStrcat()
{
	char str1[80], str2[40];
	int i = 0, j = 0;

	printf("请输入第一个字符串：\n");
	gets(str1);
	printf("请输入第二个字符串：\n");
	gets(str2);

	while (str1[i] != '\0')
	{
	i++;
	}

	while (str2[j] != '\0')
	{
	str1[i++] = str2[j++];
	}

	str1[i] = '\0';

	printf("new string:%s\n", str1);
}




/*广技师2017-5-1：用指针完成，输入两个整数，按先大后小的顺序输出*/
void codeCompareIntegerByPointer()
{
	int num1, num2;
	int *pNum1, *pNum2;

	printf("请输入两个整数，格式：num1，num2（两个数之间用逗号隔开）\n");

	scanf("%d,%d",&num1,&num2);

	pNum1 = &num1;
	pNum2 = &num2;

	printf("Max=%d",*pNum1>*pNum2?*pNum1:*pNum2);
}




/*韩师2016-5-2 编程题：从键盘输入20个学生的学号和一门课程成绩，统计计算全班平均成绩，
并输出低于平均分的学生学号和成绩
*/

typedef struct Student
{
	int stuID;
	float stuScore;

}Student, *PStudent;

void codeStatisticalStudentGrade()
{
	Student stuArr[25];
	float avgScore;//平均成绩
	float sum = 0;//班级成绩总分

	printf("请输入%d个学生的学号和成绩，学号和成绩之间用逗号隔开，格式（学号，成绩）：\n", STUCOUNT);

	for (int i = 0; i < STUCOUNT; i++)
	{
		scanf("%d,%f", &stuArr[i].stuID, &stuArr[i].stuScore);
	}

	printf("\n%d个学生的学号和成绩如下：\n", STUCOUNT);
	printf("\n学号\t成绩\t\n");
	for (int i = 0; i < STUCOUNT; i++)
	{
		sum += stuArr[i].stuScore;
		printf("%d\t%.2f\t\n", stuArr[i].stuID, stuArr[i].stuScore);
	}

	avgScore = sum / STUCOUNT;

	printf("\n\n");

	printf("班级总分：%.2f\n", sum);
	printf("班级平均分：%.2f\n", avgScore);

	printf("低于班级平均分的学生学号和成绩如下：\n");
	printf("\n学号\t成绩\t\n");
	for (int i = 0; i < STUCOUNT; i++)
	{
		if (stuArr[i].stuScore<avgScore)
		{
			printf("%d\t%.2f\t\n", stuArr[i].stuID, stuArr[i].stuScore);
		}
	}
}





/*韩师2016-5-1 编程题：求1+1/2+1/4+...+1/50的值，并输出结果*/
void codeSequenceSum()
{
	int Denominator = 2;//分母
	float sum = 1.0;//


	while (Denominator <= 50)
	{
		sum += 1 / ((float)Denominator);
		Denominator += 2;
	}

	printf("1+1/2+1/4+...+1/50= %d\n", sum);
}




/*韩师2017-5-1 编程题：有1、2、3、4四个数字，能组成多少个互相无重复数字的三位数*/
void codeNoDuplicationThreeDigitsBy1234()
{
	int count = 0;
	int num = 0;

	printf("组成的数如下：\n\n");
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				if (i != j && j != k && i != k)//每个位数之间互不相等才符合要求
				{
					num = i * 100 + j * 10 + k;
					count++;
					printf("%d\t", num);
				}
			}
		}
	}

	printf("\n\n一共能组成%d个数\n", count);
}



/*计算阶乘的运算写成函数fact(n)*/
float fact(int n)
{

	float factResult = 1.0;;
	for (int i = 1; i <= n; i++)
	{
		factResult = factResult*i;
	}

	return factResult;
}

/*韩师2017-5-2 编程题：从键盘输入的整数m和n(m>=n>=0)后
计算y=(m!)/(n!)(m-n!)
要求将计算阶乘的运算写成函数fact(n),函数返回值的类型为float
*/
void codeFactorial()
{
	int m, n;
	float factoResult = 0;

	printf("请输入2个整数m和n，其中m、n满足（m>=n>=0）,输入格式：m,n\n");
	scanf("%d,%d", &m, &n);
	printf("m=%d\nn=%d\n", m, n);

	factoResult = (fact(m)) / ((fact(n))*(fact(m - n)));

	printf("factoResult= %f,", factoResult);
	//printf("y=(m!)/((n!)(m-n!))= %f", (fact(m))/((fact(n))*(fact(m-n))));

}


/*2014-5-1：从键盘输入10个整数，找出第一个能被7整除的数，若找到，打印此数后退出循环：若未找到，打印not exist*/
void codeDivisible7()
{
	int arr[10];

	printf("请输入10个整数:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d,", &arr[i]);
	}

	printf("\n录入完毕，10个整数为：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	int count = 0;
	printf("\n第一个能被7整除的数为：\n");
	for (int i = 0; i < 10; i++)
	{
		if (arr[i] % 7 == 0)
		{
			printf("%d\n", arr[i]);
			count++;
			break;
		}
	}

	if (count == 0)
	{
		printf("not exist");
	}
}


/*2014-5-1：从键盘输入10个整数，求这10个数中的最大值与最小值并输出*/
void codeMaximumAndMinimumOf10Numbers()
{
	int arr[10];
	int temp;

	printf("请输入10个整数:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d,", &arr[i]);
	}


	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9 - j; i++)
		{
			if (arr[i]>arr[i + 1])//相邻两个数比较，并交换位置，从小到大
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	printf("\n录入完毕，排序后的数列为：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	printf("\n最大值为：%d\n", arr[9]);
	printf("最小值为：%d\n", arr[0]);


}


/*韩师-2013-5-1：把从键盘输入的数字按下列对应关系显示*/
void codeFormatPrint()
{
	int num;

	printf("请输入数字：（按回车符表示输入完毕！）\n");

	while (1)
	{
		scanf("%d", &num);

		if (num == 1)
		{
			printf("%d\t", num);
			puts("One");
		}
		else if (num == 2)
		{
			printf("%d\t", num);
			puts("Two");
		}
		else if (num == 3)
		{
			printf("%d\t", num);
			puts("Three");
		}
		else
		{
			printf("%d\t", num);
			puts("Other");
		}
	}
}


/*韩师-2013-5-2：求1+2+3+4+...+n 的值，并输出结果，其中n由用户输入*/
void codeSequenceSumForPrac()
{
	int n;
	long sum = 0;

	printf("请输入一个整数n：\n");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	printf("1+2+3+4+...+n=%ld\n", sum);
}

/*韩师-2010-5-2：有一个班级5位学生，各学4门课程，查找出有一门以上课程不及格的学生，打印出其全部课程的成绩*/
void codeCourseScore()
{
	typedef struct Student
	{
		int stuId;
		float coursc[4];
	}Student, *PStudent;

	Student stuArr[5] = { 10101, 101, 102, 103, 104, 10102, 11, 12, 13, 14, 10103, 11, 12, 131, 4, 10104, 11, 12, 13, 14 };
	PStudent pStu = stuArr;

	int count = 0;
	printf("有一门以上课程不及格的学生的全部课程成绩如下：\n");
	printf("课程1成绩\t课程2成绩\t课程3成绩\t课程4成绩\t\n");
	for (int i = 0; i < 4; i++)
	{
		count = 0;

		for (int j = 0; j < 4; j++)
		{
			if (stuArr[i].coursc[j]<60)
			{
				count++;
			}
			if (count >= 1)
			{
				printf("%.2f\t\t", stuArr[i].coursc[j]);
			}
		}

		printf("\n");
	}

}