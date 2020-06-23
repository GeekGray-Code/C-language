#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter5_select_structure.h"


/*chapter5 选择结构 测试函数*/
void chapter5SelectStructureTest()
{
	//calcLeapYear(2016);
	//calcRootOfEquation1();
	//calcMaximum3();
	//calcDigit5();
}

/*判断某一年是否闰年*/
void calcLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d年是闰年!\n", year);
	}
	else
	{
		printf("%d年不是闰年!\n", year);
	}
}


/*求一元二次方程的根*/
void calcRootOfEquation1()
{
	float a, b, c, disc, x1, x2, p, q, realPart, imagPart;	//系数，根，对称轴,实部，虚部

	printf("请输入一元二次方程的3个系数：格式（a，b，c）\n");
	scanf("%f,%f,%f", &a, &b, &c);

	disc = b*b - 4 * a*c;									//判别式
	p = -b / (2 * a);										//对称轴
	q = sqrt(disc) / (2 * a);

	if (disc > 1e-6)										//有两个不相等的根
	{
		x1 = (p + q);
		x2 = p - q;

		printf("方程：%fx^2+%fx+%f 的解为\n", a, b, c);
		printf("x1= %f\nx2= %f", x1, x2);
	}
	else if (fabs(disc) <= 1e-6)							//有两个相等的根，由于存储误差，需要用disc的绝对值是否小于一个很小的数来判断
	{
		printf("该方程有一对相等的根！\n");
		printf("x1=x2=%f\n", (-b) / (2 * a));
	}
	else
	{
		realPart = -b / (2 * a);
		imagPart = sqrt(-disc) / (2 * a);
		printf("该方程有一对共轭复根！\n");
		printf("x1= %8.4f+%8.4fi\n", realPart, imagPart);
		printf("x2= %8.4f-%8.4fi\n", realPart, imagPart);
	}
}



/*三个整数中最大的值*/
void calcMaximum3()
{
	int num1, num2, num3;

	printf("请输入3个整数：格式（num1 num2 num3）\n");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("三个整数中最大的数是：%d\n", (num1 > num2 ? num1 : num2) > num3 ? (num1 > num2 ? num1 : num2) : num3);
}


/*输入一个不多于5位的正整数，求
  1.求出它是几位数
  2.分别输出每一位数字
  3.按逆序输出各位数字
  */
void calcDigit5()
{
	int num, indiv, ten, hundred, thousand, tenThousand, digit;//整数，个，十，百，千，万，位数

	printf("请输入一个不多于5位的正整数：（0-99999）\n");
	scanf("%d", &num);

	if (num > 9999)
	{
		digit = 5;
	}
	else if (num > 999)
	{
		digit = 4;
	}
	else if (num > 99)
	{
		digit = 3;
	}
	else if (num > 9)
	{
		digit = 2;
	}
	else
	{
		digit = 1;
	}

	printf("该整数的位数是： %d位\n", digit);
	printf("每位数字为：\n");

	tenThousand = num / 10000;
	thousand = (int)(num - tenThousand * 10000) / 1000;
	hundred = (int)(num - tenThousand * 10000 - thousand * 1000) / 100;
	ten = (int)(num - tenThousand * 10000 - thousand * 1000 - hundred * 100) / 10;
	indiv = (int)(num - tenThousand * 10000 - thousand * 1000 - hundred * 100 - ten * 10);

	switch (digit)
	{
	case 5:
		printf("%d,%d,%d,%d,%d\n", tenThousand, thousand, hundred, ten, indiv);
		printf("逆序数字为：\n");
		printf("%d,%d,%d,%d,%d\n", indiv, ten, hundred, thousand, tenThousand);
		break;

	case 4: 
		printf("%d,%d,%d,%d\n", thousand, hundred, ten, indiv);
		printf("逆序数字为：\n");
		printf("%d,%d,%d,%d\n", indiv, ten, hundred, thousand);
		break;

	case 3: 
		printf("%d,%d,%d\n", hundred, ten, indiv);
		printf("逆序数字为：\n");
		printf("%d,%d,%d\n", indiv, ten, hundred);
		break;

	case 2: 
		printf("%d,%d\n", ten, indiv);
		printf("逆序数字为：\n");
		printf("%d,%d\n", indiv, ten);
		break;

	case 1: 
		printf("%d\n", indiv);
		printf("逆序数字为：\n");
		printf("%d\n", indiv);
		break;

	default:
		break;
	}
}