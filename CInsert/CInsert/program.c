#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"program.h"


/*����� ���Ժ���*/
void programTest()
{
	/*��1��2��3��4�ĸ����֣�����ɶ��ٸ��������ظ����ֵ���λ��*/
	//codeNoDuplicationThreeDigitsBy1234();

	/*����y=(m!)/(n!)(m-n!)*/
	//codeFactorial();

	/*��ʦ2016-5-1 ����⣺��1+1/2+1/4+...+1/50��ֵ����������*/
	//codeSequenceSum();

	/*�Ӽ�������20��ѧ����ѧ�ź�һ�ſγ̳ɼ���ͳ�Ƽ���ȫ��ƽ���ɼ������������ƽ���ֵ�ѧ��ѧ�źͳɼ�*/
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
/****************************************************�����**************************************************************/

/*����1-1��2+1/3-1/4+...+1/99-1/100+...��ֱ�����һ��ľ���ֵС��1e-4Ϊֹ*/
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



/*�㼼ʦ2017-5-2�������������ַ��������ӣ���ʹ��strcat����������*/
void codeMyStrcat()
{
	char str1[80], str2[40];
	int i = 0, j = 0;

	printf("�������һ���ַ�����\n");
	gets(str1);
	printf("������ڶ����ַ�����\n");
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




/*�㼼ʦ2017-5-1����ָ����ɣ������������������ȴ��С��˳�����*/
void codeCompareIntegerByPointer()
{
	int num1, num2;
	int *pNum1, *pNum2;

	printf("������������������ʽ��num1��num2��������֮���ö��Ÿ�����\n");

	scanf("%d,%d",&num1,&num2);

	pNum1 = &num1;
	pNum2 = &num2;

	printf("Max=%d",*pNum1>*pNum2?*pNum1:*pNum2);
}




/*��ʦ2016-5-2 ����⣺�Ӽ�������20��ѧ����ѧ�ź�һ�ſγ̳ɼ���ͳ�Ƽ���ȫ��ƽ���ɼ���
���������ƽ���ֵ�ѧ��ѧ�źͳɼ�
*/

typedef struct Student
{
	int stuID;
	float stuScore;

}Student, *PStudent;

void codeStatisticalStudentGrade()
{
	Student stuArr[25];
	float avgScore;//ƽ���ɼ�
	float sum = 0;//�༶�ɼ��ܷ�

	printf("������%d��ѧ����ѧ�źͳɼ���ѧ�źͳɼ�֮���ö��Ÿ�������ʽ��ѧ�ţ��ɼ�����\n", STUCOUNT);

	for (int i = 0; i < STUCOUNT; i++)
	{
		scanf("%d,%f", &stuArr[i].stuID, &stuArr[i].stuScore);
	}

	printf("\n%d��ѧ����ѧ�źͳɼ����£�\n", STUCOUNT);
	printf("\nѧ��\t�ɼ�\t\n");
	for (int i = 0; i < STUCOUNT; i++)
	{
		sum += stuArr[i].stuScore;
		printf("%d\t%.2f\t\n", stuArr[i].stuID, stuArr[i].stuScore);
	}

	avgScore = sum / STUCOUNT;

	printf("\n\n");

	printf("�༶�ܷ֣�%.2f\n", sum);
	printf("�༶ƽ���֣�%.2f\n", avgScore);

	printf("���ڰ༶ƽ���ֵ�ѧ��ѧ�źͳɼ����£�\n");
	printf("\nѧ��\t�ɼ�\t\n");
	for (int i = 0; i < STUCOUNT; i++)
	{
		if (stuArr[i].stuScore<avgScore)
		{
			printf("%d\t%.2f\t\n", stuArr[i].stuID, stuArr[i].stuScore);
		}
	}
}





/*��ʦ2016-5-1 ����⣺��1+1/2+1/4+...+1/50��ֵ����������*/
void codeSequenceSum()
{
	int Denominator = 2;//��ĸ
	float sum = 1.0;//


	while (Denominator <= 50)
	{
		sum += 1 / ((float)Denominator);
		Denominator += 2;
	}

	printf("1+1/2+1/4+...+1/50= %d\n", sum);
}




/*��ʦ2017-5-1 ����⣺��1��2��3��4�ĸ����֣�����ɶ��ٸ��������ظ����ֵ���λ��*/
void codeNoDuplicationThreeDigitsBy1234()
{
	int count = 0;
	int num = 0;

	printf("��ɵ������£�\n\n");
	for (int i = 1; i < 5; i++)
	{
		for (int j = 1; j < 5; j++)
		{
			for (int k = 1; k < 5; k++)
			{
				if (i != j && j != k && i != k)//ÿ��λ��֮�以����Ȳŷ���Ҫ��
				{
					num = i * 100 + j * 10 + k;
					count++;
					printf("%d\t", num);
				}
			}
		}
	}

	printf("\n\nһ�������%d����\n", count);
}



/*����׳˵�����д�ɺ���fact(n)*/
float fact(int n)
{

	float factResult = 1.0;;
	for (int i = 1; i <= n; i++)
	{
		factResult = factResult*i;
	}

	return factResult;
}

/*��ʦ2017-5-2 ����⣺�Ӽ������������m��n(m>=n>=0)��
����y=(m!)/(n!)(m-n!)
Ҫ�󽫼���׳˵�����д�ɺ���fact(n),��������ֵ������Ϊfloat
*/
void codeFactorial()
{
	int m, n;
	float factoResult = 0;

	printf("������2������m��n������m��n���㣨m>=n>=0��,�����ʽ��m,n\n");
	scanf("%d,%d", &m, &n);
	printf("m=%d\nn=%d\n", m, n);

	factoResult = (fact(m)) / ((fact(n))*(fact(m - n)));

	printf("factoResult= %f,", factoResult);
	//printf("y=(m!)/((n!)(m-n!))= %f", (fact(m))/((fact(n))*(fact(m-n))));

}


/*2014-5-1���Ӽ�������10���������ҳ���һ���ܱ�7�������������ҵ�����ӡ�������˳�ѭ������δ�ҵ�����ӡnot exist*/
void codeDivisible7()
{
	int arr[10];

	printf("������10������:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d,", &arr[i]);
	}

	printf("\n¼����ϣ�10������Ϊ��\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	int count = 0;
	printf("\n��һ���ܱ�7��������Ϊ��\n");
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


/*2014-5-1���Ӽ�������10������������10�����е����ֵ����Сֵ�����*/
void codeMaximumAndMinimumOf10Numbers()
{
	int arr[10];
	int temp;

	printf("������10������:\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%d,", &arr[i]);
	}


	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9 - j; i++)
		{
			if (arr[i]>arr[i + 1])//�����������Ƚϣ�������λ�ã���С����
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}

	printf("\n¼����ϣ�����������Ϊ��\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", arr[i]);
	}

	printf("\n���ֵΪ��%d\n", arr[9]);
	printf("��СֵΪ��%d\n", arr[0]);


}


/*��ʦ-2013-5-1���ѴӼ�����������ְ����ж�Ӧ��ϵ��ʾ*/
void codeFormatPrint()
{
	int num;

	printf("���������֣������س�����ʾ������ϣ���\n");

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


/*��ʦ-2013-5-2����1+2+3+4+...+n ��ֵ����������������n���û�����*/
void codeSequenceSumForPrac()
{
	int n;
	long sum = 0;

	printf("������һ������n��\n");
	scanf("%d", &n);

	for (int i = 0; i <= n; i++)
	{
		sum += i;
	}

	printf("1+2+3+4+...+n=%ld\n", sum);
}

/*��ʦ-2010-5-2����һ���༶5λѧ������ѧ4�ſγ̣����ҳ���һ�����Ͽγ̲������ѧ������ӡ����ȫ���γ̵ĳɼ�*/
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
	printf("��һ�����Ͽγ̲������ѧ����ȫ���γ̳ɼ����£�\n");
	printf("�γ�1�ɼ�\t�γ�2�ɼ�\t�γ�3�ɼ�\t�γ�4�ɼ�\t\n");
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