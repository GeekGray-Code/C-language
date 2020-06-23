#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

#include"prac_classic_algorithm_100.h"



/*pracClassicAlgorithm100 ���Ժ���*/
void pracClassicAlgorithm100Test()
{
	//prac01();
	//prac02();
	//prac03();
	//prac04();
	//prac08();
	//prac09();
	//prac11();
	//prac12();
	//prac13();
	//prac14();
	//prac21();
	//prac26();
	//prac27();
	//prac28();
	//prac30();
	//prac32();
	//prac35();
	//prac67();


}

/*
C ��ϰʵ��67
��Ŀ�� �������飬�������һ��Ԫ�ؽ�������С�������һ��Ԫ�ؽ�����������顣��

��������� ̷��ǿ�����д�������

*/
void prac67()
{
	void printArr(int arr[], int arrLen);
	void moveArr(int arr[], int arrLen, int offset);


	int arr[20];
	int arrLen, offset;

	printf("����������Ĵ�С��\n");
	scanf("%d",&arrLen);

	printf("��������������ݣ�\n");
	for (int i = 0; i < arrLen; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("����������Ĺ���ƫ������\n");
	scanf("%d", &offset);

	printf("��ӡ����ǰ�����飺\n");
	printArr(arr,arrLen);

	printf("��ӡ����������飺\n");
	moveArr(arr, arrLen, offset);//��������
	printArr(arr,arrLen);
	
}

/*��ӡ����*/
void printArr(int arr[],int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		printf("%4d",arr[i]);
	}

	printf("\n");
}

/*��������*/
void moveArr(int arr[], int arrLen, int offset)
{
	int *p, *arrEnd;
	int last;

	arrEnd = arr + arrLen;//�������һ��Ԫ�ص���һ��λ��


	while (offset)//������ֱ��ƫ����Ϊ0
	{
		last = *(arrEnd - 1);

		for (p = arrEnd - 1; p != arr; --p)//���ҹ���һλ
		{
			*p = *(p - 1);
		}

		*arr = last;
		--offset;
	}
}




/*
C ��ϰʵ��35
��Ŀ�� �ַ�����ת���罫�ַ��� "www.itsayer.com" ��תΪ "moc.boonur.www"��

*/
void prac35()
{
	void reverseStr(char* str);

	char s[] = "www.itsayer.com";
	reverseStr(s);
	printf("��ת����ַ�����%s\n",s);
}

void reverseStr(char* str)
{
	int strLen = 0;
	char* p = str;

	while (*p)//��ȡ�ַ�������
	{
		strLen++;
		p++;
	}

	//����
	int i = 0;
	char c;

	while (i<=strLen/2-1)
	{
		c = *(str + i);
		*(str + i) = *(str + strLen - 1 - i);
		*(str + strLen - 1 - i) = c;
		i++;
	}
}




/*
C ��ϰʵ��32
��Ŀ�� ɾ��һ���ַ����е�ָ����ĸ���磺�ַ��� "aca"��ɾ�����е� a ��ĸ��

*/
void prac32()
{
	char* deleteCharacters(char* str, char* charSet);

	char s1[2] = "a";
	char s2[5] = "aca";

	printf("ɾ��ָ����ĸ����ַ�����\n");
	printf("%s\n",deleteCharacters(s2,s1));
}

char* deleteCharacters(char* str, char* charSet)
{
	int hash[256];

	if (NULL==charSet)
	{
		return str;
	}

	for (int i = 0; i < 256; i++)
	{
		hash[i]=0;
	}

	for (int i = 0; i < strlen(charSet); i++)
	{
		hash[charSet[i]] = 1;//��ָ���ַ�λ��Ϊ1
	}

	int currentIndex = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (!hash[str[i]])//����ָ���ַ�
		{
			str[currentIndex++] = str[i];
		}

	}

	str[currentIndex] = '\0';

	return str;
}





/*
C ��ϰʵ��30 - ������
��Ŀ�� һ��5λ�����ж����ǲ��ǻ���������12321�ǻ���������λ����λ��ͬ��ʮλ��ǧλ��ͬ��

��������� ѧ��ֽ��ÿһλ����

*/
void prac30()
{
	long dig, ten, hundred, thousand, tenThousand,num;

	printf("������һ����λ����\n");
	scanf("%d",&num);

	tenThousand = num / 10000;
	thousand = num % 10000 / 1000;
	ten = num % 100 / 10;
	dig = num % 10;

	if (dig==tenThousand && ten==thousand)
	{
		printf("���ǻ�����!\n");
	}
	else
	{
		printf("�ⲻ�ǻ�����!\n");
	}
}






/*
��ϰʵ��28
��Ŀ�� ��5��������һ���ʵ�����˶����ꣿ��˵�ȵ�4���˴�2�ꡣ�ʵ�4������������˵�ȵ�3���˴�2�ꡣ�ʵ������ˣ���˵�ȵ�2�˴����ꡣ�ʵ�2���ˣ�˵�ȵ�һ���˴����ꡣ����ʵ�һ���ˣ���˵��10�ꡣ���ʵ�����˶��

��������� ���õݹ�ķ������ݹ��Ϊ���ƺ͵��������׶Ρ�Ҫ��֪�����������������֪�������˵��������������ƣ��Ƶ���һ�ˣ�10�꣩���������ơ�
*/
void prac28()
{
	int age(int);
	printf("%d\n",age(5));
}


int age(int n)
{
	int c;
	
	if (n==1)
	{
		c = 10;
	}
	else
	{
		c=age(n - 1) + 2;
	}


	return c;
}




/*
C ��ϰʵ��27
��Ŀ�� ���õݹ麯�����÷�ʽ�����������5���ַ������෴˳���ӡ������

��������� �ޡ�

*/
void prac27()
{
	int i = 5;
	void palin(int n);

	printf("������5���ַ�\40:\40");
	palin(i);
	printf("\n");
}


void palin(int n)
{
	char next;

	if (n<=1)
	{
		next = getchar();
		printf("�෴˳��������\40:\40");
		putchar(next);
	}
	else
	{
		next = getchar();
		palin(n-1);
		putchar(next);
	}
}



/*
C ��ϰʵ��26
��Ŀ�� ���õݹ鷽����5!��

��������� �ݹ鹫ʽ��fn=fn_1*4!

*/
void prac26()
{
	int fact(int);

	for (int i = 0; i < 6; i++)
	{
		printf("%d!=%d\n",i,fact(i));
	}

}

static int fact(int num)
{
	int sum;

	if (num==0)
	{
		sum = 1;
	}
	else
	{
		sum = num*fact(num - 1);
	}

	return sum;
}





/*
C ��ϰʵ��21
��Ŀ�� ���ӳ������⣺���ӵ�һ��ժ�����ɸ����ӣ���������һ�룬����񫣬�ֶ����һ�� �ڶ��������ֽ�ʣ�µ����ӳԵ�һ�룬�ֶ����һ�����Ժ�ÿ�����϶�����ǰһ��ʣ�� ��һ����һ��������10���������ٳ�ʱ����ֻʣ��һ�������ˡ����һ�칲ժ�˶��١�

��������� ��ȡ����˼ά�ķ������Ӻ���ǰ�ƶϡ�

1) ��x1Ϊǰһ������������x2Ϊ�ڶ����������� ��

x2=x1/2-1, x1=(x2+1)*2

x3=x2/2-1, x2=(x3+1)*2

�Դ����ƣ� xǰ=(x��+1)*2

2) �ӵ�10��������Ƶ���1�죬��һ��ѭ�����̡�

*/
void prac21()
{
	int day = 9;
	int x1 = 0, x2 = 1;

	while (day>0)
	{
		x1 = (x2 + 1) * 2;
		x2 = x1;
		day--;
	}

	printf("����Ϊ %d\n",x1);
}





/*
C ��ϰʵ��14 - ��һ���������ֽ�������
��Ŀ�� ��һ���������ֽ������������磺����90,��ӡ��90=233*5��

��������� ��n���зֽ���������Ӧ���ҵ�һ����С������k��Ȼ������������ɣ�

(1)����������ǡ���ڣ�С�ڵ�ʱ�򣬼���ִ��ѭ����n����˵���ֽ��������Ĺ����Ѿ����������� ��ӡ�����ɡ�
(2)��n�ܱ�k��������Ӧ��ӡ��k��ֵ������n����k����,��Ϊ�µ�������n.�ظ�ִ�еڶ�����
(3)���n���ܱ�k����������k+1��Ϊk��ֵ,�ظ�ִ�е�һ����
*/
void prac14()
{
	int num;

	printf("������һ������:\n");
	scanf("%d",&num);
	printf("%d=",num);

	for (int i = 2; i <= num; i++)
	{
		while (num%i==0)
		{
			printf("%d",i);
			num /= i;

			if (num!=1)
			{
				printf("*");
			}
		}

	}

	printf("\n");
}







/*
C ��ϰʵ��13 - ˮ�ɻ���
��Ŀ�� ��ӡ�����е�"ˮ�ɻ���"����ν"ˮ�ɻ���"��ָһ����λ�������λ���������͵��ڸ��� �������磺153��һ��"ˮ�ɻ���"����Ϊ153=1�����η���5�����η���3�����η���

��������� ����forѭ������100-999������ÿ�����ֽ����λ��ʮλ����λ
*/
void prac13()
{
	int dig, ten, hundred;

	for (int i = 100; i < 1000; i++)
	{
		dig = i % 10;
		ten = i / 10 % 10;
		hundred = i / 100;

		if (i==(pow(dig,3)+pow(ten,3)+pow(hundred,3)))
		{
			printf("%d\n",i);
		}
	}
}







/*
C ��ϰʵ��12
��Ŀ�� �ж�101��200֮���������

��������� �ж������ķ�������һ�����ֱ�ȥ��2��sqrt(�����)������ܱ������� ���������������������֮��������
*/
void prac12()
{
	int k,leap=1;
	int count = 0;//����

	for (int i = 101; i <=200; i++)
	{
		k = sqrt(i+1);
		for (int j = 2; j <= k; j++)
		{
			if (i%j==0)
			{
				leap = 0;
				break;
			}

		}

		if (leap)
		{
			count++;
			printf("%d ",i);

			if (count%5==0)
			{
				printf("\n");
			}
		}

		leap = 1;

	}
}







/*
C ��ϰʵ��11
��Ŀ�� �ŵ����⣨�������̣�����һ�����ӣ��ӳ������3������ÿ���¶���һ�����ӣ�С���ӳ����������º�ÿ��������һ�����ӣ��������Ӷ���������ÿ���µ���������Ϊ���٣������ǰ40���¼��ɣ�

��������� ���ӵĹ���Ϊ����1,1,2,3,5,8,13,21....�����¸�������������֮�ͣ��ӵ������¿�ʼ����
*/
void prac11()
{
	long f1, f2;

	f1 = f2=1;

	for (int i = 0; i <= 20; i++)
	{
		printf("%12ld%12ld",f1,f2);
		if (i%2==0)
		{
			printf("\n");//���������ÿ��4��
		}

		f1 = f1 + f2;//ǰ�����¼�������ֵ����������
		f2 = f1 + f2;
	}
}








/*
C ��ϰʵ��9
��Ŀ�� Ҫ����������������̡�

��������� ��������������64���ڰ����ĸ�����ɣ���Ϊ8��*8�С���i�����У�j�������У�����i+j�ĺ͵ı仯����������ڷ��񣬻��ǰ׷���
*/
void prac09()
{
	int i, j;

	for ( i = 0; i < 8; i++)
	{
		for ( j = 0; j < 8; j++)
		{
			if ((i+j)%2==0)
			{
				printf("%c%c",219,219);
			}
			else
			{
				printf(" ");
			}
		}

		printf("\n");
	}
}




/*
C ��ϰʵ��8
��Ŀ�� ���9*9�ھ���

��������� �������п��ǣ��� 9 �� 9 �У�i �����У�j �����С�
*/
void prac08()
{
	int row;//��
	int column;//��
	int result;

	for ( row = 1; row < 10; row++)
	{
		for (column = 1; column <= row; column++)
		{
			result = row*column;
			printf("%d*%d=%-3d",row,column,result);
		}

		printf("\n");//ÿ��ӡһ�к���
	}
}



/*
C ��ϰʵ��4
��Ŀ�� ����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

��������� ��3��5��Ϊ����Ӧ���Ȱ�ǰ�����µļ�������Ȼ���ټ���5�켴����ĵڼ��죬��������������������·ݴ���3ʱ�迼�Ƕ��һ��
*/
void prac04()
{
	int day, month, year, sum, leap;

	printf("�����������գ���ʽ����.��.�գ�2015.10.10��\n");
	scanf("%d.%d.%d",&year,&month,&day);

	switch (month)
	{
		case 1:sum = 0; break;
		case 2:sum = 31; break;
		case 3:sum = 59; break;
		case 4:sum = 90; break;
		case 5:sum = 120; break;
		case 6:sum = 151; break;
		case 7:sum = 181; break;
		case 8:sum = 212; break;
		case 9:sum = 243; break;
		case 10:sum = 273; break;
		case 11:sum = 304; break;
		case 12:sum = 334; break;

		default:printf("data error!\n");
			break;
	}

	sum += day;//�ټ���ĳ�������

	if (year%400==0 || (year%4==0 && year%100!=0))//�ж�����
	{
		leap = 1;
	}
	else
	{
		leap = 0;
	}

	if (leap==1 && month>2)
	{
		sum++;//������������·ݴ���2��������Ӧ�ü�һ��
	}

	printf("����%d���еĵ�%d��\n",year,sum);
}




/*
C ��ϰʵ��3
��Ŀ�� һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�

���������

�������Ϊ x��

1����x + 100 = n2, x + 100 + 168 = m2

2�������ʽ��m2 - n2 = (m + n)(m - n) = 168

3�����ã� m + n = i��m - n = j��i * j =168��i �� j ����һ����ż��

4���ɵã� m = (i + j) / 2�� n = (i - j) / 2��i �� j Ҫô����ż����Ҫô����������

5���� 3 �� 4 �Ƶ���֪����i �� j ���Ǵ��ڵ��� 2 ��ż����

6������ i * j = 168�� j>=2���� 1 < i < 168 / 2 + 1��

7���������� i ����������ѭ�����㼴�ɡ�

*/
void prac03()
{
	long int x, y;

	for (long int i = 0; i < 100000; i++)
	{
		x = sqrt(i+100);//Ϊ��������100�󿪷���Ľ��
		y = sqrt(i+100+168);//Ϊ��������100,�ټ���168�󿪷���Ľ��

		if (x*x==i+100 && y*y==i+268)//���һ������ƽ������ƽ�����ڸ�����˵������ȫƽ����
		{
			printf("\n%ld",i);
		}
	}

}




/*
C ��ϰʵ��2
��Ŀ����ҵ���ŵĽ������������ɡ�

����(I)���ڻ����10��Ԫʱ���������10%��
�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%��
40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%��
60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%��
����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%��ɡ�
�Ӽ������뵱������I����Ӧ���Ž���������

����������������������ֽ磬��λ��ע�ⶨ��ʱ��ѽ�����ɳ����͡�


*/
void prac02()
{
	double I;	//�������󣬼�������
	double bonus1, bonus2, bonus4, bonus6, bonus10, finalBonus;

	printf("�����뵱�¾�����I��\n");
	scanf("%lf",&I);

	bonus1 = 100000 * 0.1;	            
	bonus2 = bonus1 + 100000 * 0.075;   
	bonus4 = bonus2 + 200000 * 0.05;    
	bonus6 = bonus4 + 200000 * 0.03;   
	bonus10 = bonus6 + 400000 * 0.015;	

	if (I<=100000)
	{
		finalBonus = I*0.1;//���ڻ����10��Ԫʱ���������10%
	}
	else if (I<=200000)
	{
		finalBonus = bonus1+ (I-100000)*0.075;//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10%��ɣ�����10��Ԫ�Ĳ��֣������7.5%��
	}
	else if (I<=400000)
	{
		finalBonus = bonus2 + (I - 200000)*0.05;//20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5%
	}
	else if (I <= 600000)
	{
		finalBonus = bonus4 + (I - 400000)*0.03;//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3%
	}
	else if (I <= 1000000)
	{
		finalBonus = bonus6 + (I - 600000)*0.015;//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5%
	}
	else if (I > 1000000)
	{
		finalBonus = bonus10 + (I - 1000000)*0.01;//����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1%���
	}

	printf("���Ϊ��%lf\n",finalBonus);

}




/*
��Ŀ����1��2��3��4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�

��������������ڰ�λ��ʮλ����λ�����ֶ���1��2��3��4��������е����к���ȥ�����������������С�
*/
void prac01()
{
	int digits, ten, hundre;	//��ʮ��λ

	for (digits = 1; digits < 5; digits++)//����forѭ��
	{
		for (ten = 1; ten < 5; ten++)
		{
			for (hundre = 1; hundre < 5; hundre++)
			{
				if (digits!=ten && digits!=hundre && ten!=hundre)//ȷ����ʮ��λ������ͬ
				{
					printf("%d%d%d\n",hundre,ten,digits);
				}
			}
		}
	}
}
