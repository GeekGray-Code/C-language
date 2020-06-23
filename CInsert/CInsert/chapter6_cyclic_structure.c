#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter6_cyclic_structure.h"



/*chapter6 ѭ���ṹ ���Ժ���*/
void chapter6CyclicStructureTest()
{
	//calcApproximateValueOfPI();
	//calcFibonicci40();
	//calcPrimeNum();
	//calcPrimeNum100_200();
	//calcGcdAndLcm();
	//calcCharacterQuantity();
	//calcSn();
	//calcSumOfFactorials1To20();
	//calcSumOfPolynomials();
	//calcDaffodilNum();
	//calcCompleteNumWithin1000();
	//calcSequenceSumTop20Items();
	//calcApplicationQuestions1();
	//calcSumOfProofDiagonal();
	//calcInsertNum();
}

/*�ù�ʾ��pi�Ľ���ֵ p124*/
void calcApproximateValueOfPI()
{
	int s;
	float n, t, pi;			//piһ��ʼ�������ʽ��ֵ��������pi��ֵ

	t = 1;					//��ǰ���ֵ
	pi = 0;
	n = 1.0;				//ͨ���������ĸ
	s = 1;					//������ʾ��ֵ�ķ���

	while (fabs(t)>1e-6)	//fabs()�������ֵ���������Ϊ�����ͣ�t�Ǹ��������Բ����� abs()
	{
		pi = pi + t;		//�ѵ�ǰ��term�ۼӵ�pi��
		n = n + 2;			//n+2����һ��ķ�ĸ
		s = -s;				//sign������ֵ���ţ���һ���������һ������෴
		t = s / n;			//�����һ���ֵterm
	}

	pi = pi * 4;			//����ʽ�ĺ�*4������pi�Ľ���ֵ

	printf("PI= %10.6f\n",pi);
}


/*��Fibonacci����ǰ40����
  ��1��2������Ϊ1��1
  �ӵ�3������ʼ����������ǰ��������֮��
*/
void calcFibonicci40()
{
	long int f1, f2;			//��23����֮������ֵ�ѳ���32767
	int i;
	f1 = 1;
	f2 = 1;

	for ( i = 0; i < 20; i++)	//iÿ��ֵ1����������2����,��ѭ��20�μ���
	{
		printf("%12ld %12ld",f1,f2);

		if (i%2==0)				//���10��
		{
			printf("\n");
		}

		f1 = f1 + f2;			//�������һ�������������f1��
		f2 = f2 + f1;			//�������2�������������f2��
	}
}


/*�ж� num �Ƿ�Ϊ����*/
void calcPrimeNum()
{
	int num, i, k;

	printf("������һ��������\n");
	scanf("%d",&num);

	k = sqrt(num);

	for (i = 2; i <= k; i++)//�� num �� 2~sqrt(num) ֮���������������е��κ�һ��������������ǰ����ѭ��
	{
		if (num%i == 0)
		{
			break;			//��ʱi��ֵ��ȻС�ڻ����sqrt(num)
		}
	}

	if (i > k)				//��i��ֵ���ڻ����sqrt(num)+1��������sqrt(num)�������δ����2~sqrt(num)֮�����һ����������
	{
		printf("%d is a prime number\n",num);
	}
	else
	{
		printf("%d is not a prime number\n",num);
	}
}



/*��100~200֮���ȫ������*/
void calcPrimeNum100_200()
{
	int num, i, k,n=0;

	for ( num = 101; num <= 200; num=num+2)
	{
		k = sqrt(num);

		for (i = 2; i <= k; i++)//�� num ��2��sqrt(num)֮���������������е��κ�һ��������������ǰ����ѭ��
		{						//���ݳ�ʶ��ż���������������Բ��ؽ����ж��������ѭ����101��ʼ��ÿ����ֵ2
			if (num%i == 0)
			{
				break;			//����ֹ��ѭ������ʱi��ֵ��ȻС�ڻ����sqrt(num)
			}
		}

		if (i >=k+1)			//��i��ֵ���ڻ����sqrt(num)+1��������sqrt(num)�������δ����2~sqrt(num)֮�����һ����������
		{
			printf("%d ", num);
			n = n + 1;			//�ۼ���������ĸ���
		}

		if (n%10==0)			//����ÿ�����10��
		{
			printf("\n");
		}
	}

	printf("\n");
}


/*���Լ������С������
  Greatest common divisor and least common multiple

*/
void calcGcdAndLcm()
{
	int num1, num2;				//����������
	int remainder;				//����
	int lcm;					//Least common multiple:��С������
	int gcd;					//Greatest common divisor:��Լ��
	int temp;					//��ʱ����

	printf("��������������������ʽ��num1��num2��\n");
	scanf("%d,%d",&num1,&num2);

	if (num1<num2)				//��num1<num2������2����ȷ�� num1 Ϊ�ϴ����һ����
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	lcm = num1*num2;			//��num1 ��С�� num2������������˸�ֵ��lcm

	while (num2!=0)				//��շת��������� mod ������ֱ������Ϊ0
	{
		remainder = num1%num2;	//�ҵ��ý�С�����ֳ�ȥ�ϴ����ֵ����������仰˵���ýϴ�����ֺͽ�С�����ֽ��� mod ����
		num1 = num2;			//num2Ϊ��С���Ǹ������������Ƹ�num1
		num2 = remainder;		//��������ֵ��num2����һ��ѭ��������ʵ�����ǣ��ó���num1��num2��������remainder����mod������ֱ������Ϊ0��������
	}

	gcd = num1;					//��������Ϊ0ʱ�����һ�������ĳ�����Ϊ2�������Լ��
	lcm = lcm / gcd;			//2������ٳ������Լ����Ϊ��С������

	printf("���ǵ����Լ��Ϊ�� %d\n",gcd);
	printf("���ǵ���С������Ϊ�� %d\n", lcm);
}



/*����һ���ַ����ֱ�ͳ�Ƴ�����Ӣ����ĸ���ո����ֺ������ַ��ĸ���*/
void calcCharacterQuantity()
{
	int characCnt=0;		//Ӣ����ĸ����
	int spaceCnt=0;			//�ո�����
	int digitCnt=0;			//���ֵ�����
	int otherCharacCnt=0;	//�����ַ�������
	char charac;			//����������ַ�

	printf("������һ���ַ���\n");

	while ((charac=getchar())!='\n')
	{
		if (charac >= 'a' && charac <= 'z' || charac >= 'A' && charac<='Z')
		{
			characCnt++;
		}
		else if (charac==' ')
		{
			spaceCnt++;
		}
		else if (charac>='0' && charac<='9')
		{
			digitCnt++;
		}
		else
		{
			otherCharacCnt++;
		}
	}

	printf("Ӣ����ĸ�ĸ���Ϊ�� %d\n�ո�ĸ���Ϊ�� %d\n���ֵĸ���Ϊ�� %d\n�����ַ��ĸ���Ϊ�� %d\n",characCnt,spaceCnt,digitCnt,otherCharacCnt);
}


/*��Sn=a+aa+aaa+...+aaa..a��ֵ������a��һ�����֣�n��ʾa��λ��
  ���磺2+22+222+2222+22222����ʱn=5����n�ɼ�������
*/
void calcSn()
{
	int a, n;		//a������ n��λ��
	int i = 1;
	int sn = 0;		//����ʽǰi��ĺ�
	int tn = 0;		//i��a����ɵ�����ֵ

	printf("������a��n��ֵ������ʽ��a��n��\n");
	scanf("%d,%d",&a,&n);

	int temp = a;

	while (i<=n)
	{
		tn = tn + a;
		sn = sn + tn;
		a = a * 10;
		++i;
	}

	printf("%d+%d%d+%d%d%d+...+%d%d...%d= %d\n", temp,temp,temp,temp,temp,temp,temp,temp,temp,sn);
}



/*��1��+2��+3��+...+20��*/
void calcSumOfFactorials1To20()
{
	double sn=0;								//��Ž׳˵ĺ�
	double t = 1;								//����׳�
	int n;

	for ( n = 1; n <=20; n++)
	{
		t = t*n;
		sn = sn + t;
	}

	printf("1��+2��+3��+...+20��= %22.15e\n",sn);//��22.15e��ʽ��������ݿ��Ϊ22��С��Ϊ��Ϊ15λ
}


/*��1+2+3+...+100��+(1^2+2^2+...+50^2)+(1+1/2+1/3+...+1/10)�ĺ�*/
void calcSumOfPolynomials()
{
	int n1 = 100;				//����ʽ1������
	int n2 = 50;				//����ʽ2������
	int n3 = 10;				//����ʽ3������
	double s1 = 0;				//����ʽ1�ĺ�:��1+2+3+...+100��
	double s2 = 0;				//����ʽ2�ĺ�:(1^2+2^2+...+50^2)
	double s3 = 0;				//����ʽ3�ĺ�:(1+1/2+1/3+...+1/10)
	double k;
	double sum;					//����ʽ1�ĺ�+����ʽ2�ĺ�+����ʽ3�ĺ�

	for ( k = 1; k <= n1; k++)	//����1~100�ĺ�
	{
		s1 = s1 + k;
	}

	for (k = 1; k <= n2; k++)	//����1~50������ƽ����
	{
		s2 = s2 + k*k;
	}

	for (k = 1; k <= n3; k++)	//����1~10�ĸ�������
	{
		s3 = s3 + 1/k;
	}

	printf("sum=%15.6f\n",s1+s2+s3);
}


/*�������ˮ�ɻ�����ָһ��3λ�������λ���������͵��ڸ�������
  ���磺153=1+125+27
*/
void calcDaffodilNum()
{
	int indiv;						//��λ
	int ten;						//ʮλ
	int hundred;					//��λ
	int n;

	printf("ˮ�ɻ����У�\n");

	for ( n = 100; n < 1000; n++)
	{
		hundred = n / 100;			//��λ
		ten = n / 10 - hundred * 10;//ʮλ
		indiv = n % 10;				//��λ

		//if (n==hundred*hundred*hundred+ten*ten*ten+indiv*indiv*indiv)
		if (n==pow(hundred,3)+pow(ten,3)+pow(indiv,3))
		{
			printf("%d ",n);
		}
	}

	printf("\n");
}



/*�ҳ�1000֮�ڵ���������
  ������һ�������ǡ�õ�����������֮��
  ���磺6=1+2+3
*/
void calcCompleteNumWithin1000()
{
	int num;								//����
	int factorSum;							//��������֮��
	int i;

	for ( num = 2; num < 1000; num++)
	{
		factorSum = 0;

		for ( i = 1; i < num; i++)
		{
			if ((num%i) == 0)				//���num�ܱ�i������˵��i��num������
			{
				factorSum = factorSum + i;	//�ۼ����ӵĺ�
			}
		}

		if (factorSum==num)					//������ӵĺ͵��ڸ�������Ϊ����
		{
			printf("%d,������,�����У�",num);

			for (i = 1; i < num; i++)
			{
				if (num%i == 0)
				{
					printf("%d��", i);		//�������������
				}
			}

			printf("\n");//����������һ�����������
		}
	}
}



/*�����е�ǰ20��֮��
  ���У�2/1 + 3/2 + 5/3 + 8/5 + 13/8 + 21/13+...
  ���ɣ���һ��ķ�ĸ����ǰһ��ķ��ӣ�
	   ǰһ��ķ��ӷ�ĸ��ӵ��ں�һ��ķ���
*/
void calcSequenceSumTop20Items()
{
	int i;
	int count = 20;											//����
	double molecule = 2;									//����
	double denominator = 1;									//��ĸ
	double sequenceSum = 0;									//����ǰn��ĺ�
	double temp;

	for ( i = 0; i <= count; i++)
	{
		sequenceSum = sequenceSum + molecule / denominator;	//�ۼ����к�
		temp = molecule;									//��ǰһ��ķ��ӱ��浽��ʱ����
		molecule = molecule + denominator;					//�����һ��ķ���=ǰһ��ķ���+��ĸ
		denominator = temp;									//�����һ��ķ�ĸ=ǰһ��ķ���
	}

	printf("sequenceSum=%16.10f\n",sequenceSum);
}


/*Ӧ����1��һ�����100m�߶��������£�ÿ����غ�����ԭ�߶ȵ�һ�룬�����£��ٷ���
      �����ڵ�10�����ʱ�������������ף���10�η������
*/
void calcApplicationQuestions1()
{
	double metersPassed = 100;							//n�����ʱ��������������һ��ʼ��ʾ��һ�����ʱ����������
	double bounceHeight = metersPassed / 2;				//n�η����߶ȣ�һ��ʼΪԭ�߶ȵ�һ��
	int count;

	for ( count = 2; count <= 10; count++)
	{
		metersPassed = metersPassed + 2 * bounceHeight;	//��n�����ʱ������������
		bounceHeight = bounceHeight / 2;				//��n�η����߶�
	}

	printf("��10�����ʱ������:%f��\n",metersPassed);
	printf("��10�η���:%f��\n",bounceHeight);

}


/*��һ��3*3�����;���Խ���Ԫ��֮��*/
void calcSumOfProofDiagonal()
{
	int arr[3][3];
	int sum=0;

	printf("����һ��3*3�ľ���:����ʽ��num1��num2,.....�ö��Ÿ�����\n");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			scanf("%d,",&arr[i][j]);
		}
	}

	for (int i = 0; i < 3; i++)
	{
		sum += arr[i][i];
	}

	printf("sum=%d\n",sum);
}


/*��һ�����ź�������飬Ҫ������һ�����󣬰�ԭ������Ĺ��ɽ�������������*/
void calcInsertNum()
{
	int arr[11] = {1,4,6,9,13,16,19,28,40,100};
	int temp1, temp2, num, end;

	printf("ԭ������������飺\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,",arr[i]);
	}

	end = arr[9];								//ԭ�������һ��Ԫ��

	printf("\n��������Ҫ�����һ������\n");
	scanf("%d",&num);

	if (num>end)								//�����������ԭ�������һ��Ԫ�أ��������嵽����β
	{
		arr[10] = num;
	}
	else                                       //����Ӧ���뵽arr[0]~arr[i-1]֮��
	{
		for (int i = 0; i < 10; i++)
		{
			if (arr[i]>num)						//��Ӧ�嵽arr[i-1]֮��arr[i]֮ǰ
			{
				temp1 = arr[i];
				arr[i] = num;					//��num����arr[i]��

				for (int j = i+1; j < 11; j++)	//��ԭ����i��Ԫ��֮�������Ԫ���±����ε���1
				{
					temp2 = arr[j];
					arr[j] = temp1;
					temp1 = temp2;
				}
				break;
			}
		}
	}

	printf("now array:\n");
	for (int i = 0; i < 11; i++)
	{
		printf("%d,",arr[i]);
	}

	printf("\n");
}