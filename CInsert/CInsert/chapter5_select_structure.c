#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter5_select_structure.h"


/*chapter5 ѡ��ṹ ���Ժ���*/
void chapter5SelectStructureTest()
{
	//calcLeapYear(2016);
	//calcRootOfEquation1();
	//calcMaximum3();
	//calcDigit5();
}

/*�ж�ĳһ���Ƿ�����*/
void calcLeapYear(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d��������!\n", year);
	}
	else
	{
		printf("%d�겻������!\n", year);
	}
}


/*��һԪ���η��̵ĸ�*/
void calcRootOfEquation1()
{
	float a, b, c, disc, x1, x2, p, q, realPart, imagPart;	//ϵ���������Գ���,ʵ�����鲿

	printf("������һԪ���η��̵�3��ϵ������ʽ��a��b��c��\n");
	scanf("%f,%f,%f", &a, &b, &c);

	disc = b*b - 4 * a*c;									//�б�ʽ
	p = -b / (2 * a);										//�Գ���
	q = sqrt(disc) / (2 * a);

	if (disc > 1e-6)										//����������ȵĸ�
	{
		x1 = (p + q);
		x2 = p - q;

		printf("���̣�%fx^2+%fx+%f �Ľ�Ϊ\n", a, b, c);
		printf("x1= %f\nx2= %f", x1, x2);
	}
	else if (fabs(disc) <= 1e-6)							//��������ȵĸ������ڴ洢����Ҫ��disc�ľ���ֵ�Ƿ�С��һ����С�������ж�
	{
		printf("�÷�����һ����ȵĸ���\n");
		printf("x1=x2=%f\n", (-b) / (2 * a));
	}
	else
	{
		realPart = -b / (2 * a);
		imagPart = sqrt(-disc) / (2 * a);
		printf("�÷�����һ�Թ������\n");
		printf("x1= %8.4f+%8.4fi\n", realPart, imagPart);
		printf("x2= %8.4f-%8.4fi\n", realPart, imagPart);
	}
}



/*��������������ֵ*/
void calcMaximum3()
{
	int num1, num2, num3;

	printf("������3����������ʽ��num1 num2 num3��\n");
	scanf("%d %d %d", &num1, &num2, &num3);

	printf("�����������������ǣ�%d\n", (num1 > num2 ? num1 : num2) > num3 ? (num1 > num2 ? num1 : num2) : num3);
}


/*����һ��������5λ������������
  1.������Ǽ�λ��
  2.�ֱ����ÿһλ����
  3.�����������λ����
  */
void calcDigit5()
{
	int num, indiv, ten, hundred, thousand, tenThousand, digit;//����������ʮ���٣�ǧ����λ��

	printf("������һ��������5λ������������0-99999��\n");
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

	printf("��������λ���ǣ� %dλ\n", digit);
	printf("ÿλ����Ϊ��\n");

	tenThousand = num / 10000;
	thousand = (int)(num - tenThousand * 10000) / 1000;
	hundred = (int)(num - tenThousand * 10000 - thousand * 1000) / 100;
	ten = (int)(num - tenThousand * 10000 - thousand * 1000 - hundred * 100) / 10;
	indiv = (int)(num - tenThousand * 10000 - thousand * 1000 - hundred * 100 - ten * 10);

	switch (digit)
	{
	case 5:
		printf("%d,%d,%d,%d,%d\n", tenThousand, thousand, hundred, ten, indiv);
		printf("��������Ϊ��\n");
		printf("%d,%d,%d,%d,%d\n", indiv, ten, hundred, thousand, tenThousand);
		break;

	case 4: 
		printf("%d,%d,%d,%d\n", thousand, hundred, ten, indiv);
		printf("��������Ϊ��\n");
		printf("%d,%d,%d,%d\n", indiv, ten, hundred, thousand);
		break;

	case 3: 
		printf("%d,%d,%d\n", hundred, ten, indiv);
		printf("��������Ϊ��\n");
		printf("%d,%d,%d\n", indiv, ten, hundred);
		break;

	case 2: 
		printf("%d,%d\n", ten, indiv);
		printf("��������Ϊ��\n");
		printf("%d,%d\n", indiv, ten);
		break;

	case 1: 
		printf("%d\n", indiv);
		printf("��������Ϊ��\n");
		printf("%d\n", indiv);
		break;

	default:
		break;
	}
}