#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"prac_examination.h"

struct tree
{
	int x;
	char *s;
};

void fun(int *n)
{
	while ((*n)--);
	
	printf("%d",++(*n));
}

void func1(struct tree t)
{
	t.x = 5;
	t.s = "car";

	return 0;
}

long func2(int x)
{
	long p;

	if (x==0 || x==1)
	{
		return 2;
	}
	
	p = x*func2(x - 1);

	return p;
}

int func3(int p)
{
	static int d = 5;
	d += p;
	printf("%d,",d);

	return d;
}

void func4(char s[], int c)
{
	for (int i = 0,j=0; s[i]!='\0'; i++)
	{
		if (s[i]!=c)
		{
			s[j++] = s[i];
		}

		s[j] = '\0';

	}
}

int func5(int a, int b)
{
	static int n = 0, i = 2;

	i += n + 1;
	n = i + a + b;

	printf("i=%d\n", i);
	printf("n=%d\n",n);
	

	return n;
}

char * scmp(char * s1, char * s2)
{
	if (strcmp(s1, s2)<0)
	{
		return s1;
	}
	else
	{
		return s2;
	}
}

int max1(int x, int y)
{
	int z;
	if (x>y)
	{
		z = x;
	}
	else
	{
		z = y;
	}

	return z;
}

int select1(int a[N], int *n)
{
	int i, k = 0;

	for ( i = 1; i < N; i++)
	{
		if (a[i]>a[k])
		{
			k = i;
		}
	}

	*n = k;
	return a[k];
}

void wr(char *st, int i)
{
	st[i] = '\0';
	puts(st);
	if (i>1)
	{
		wr(st, i - 1);
	}
}



/*习题 测试函数*/
void pracExaminationTest()
{
	/*求输出值、表达式值 题型*/
	categoryOutput();

	/*运行结果类*/
	categoryOperationResult();

	/*阅读程序段类型*/
	categoryReadProgram();

	/*日常习题测试Test*/
	pracTest();
}




/*************************************************日常习题测试 ***************************************************/
void pracTest()
{
	printf("it is pracTest()\n");

	int x[10] = {0,1,2,3,4,5,6,7};
	int* p1 = x;

	printf("(p1=x+3,*p1++):%d \n",(p1=x+3,*p1++));
	printf("(p1 = x + 2, *(p1++)):%d \n", (p1 = x + 2, *(p1++)));
	printf("(p1 = x + 2, *++p1):%d \n", (p1 = x + 2, *++p1));
}









/************************************************************************************************************************/
/*************************************************求输出值、表达式值 题型***************************************************/
void categoryOutput()
{
	/*输出类*/
	{
		//int s = 6, u = 6;
		//u = s++;
		//u++;
		//printf("%d",u);//7


		//int x = 2, y = 1;
		//printf("%f",x>y?1:1.5);//1.0


		//float a = 11.0 / 3;//3.66666
		//printf("%f\n",a);
		//printf("%d\n",(int)(11.0/3+0.5));


		//int a;
		//printf("%d\n",((a=3*5,a*4),a+5));	//20
		//printf("%d\n", (a = 3 * 5, a * 4), a + 5);	//60

		//int x = 5, y = 4;
		//printf("%d\n",y*=x+5);	//40


		/*char a[10];
		char * p = a;
		p = "Turbo C";*/

		//int a, b;
		//printf("%d\n",(a=2,b=5,b++,a+b));	//8


		//char ch[3][5] = {"AAAA","BBB","CC"};
		//printf("\"%s\"\n",ch[1]);	//"BBB"


		//int aa[4][4] = { {1,2,3,4}, {5,6,7,8}, {3,9,10,2}, {4,2,9,6} };
		//int s = 0;
		//for (int i = 0; i < 4; i++)
		//{
		//	s += aa[i][1];
		//}
		//printf("%d\n",s);//19


		//int a = 5, b = 4, c = 3, d = 2;
		//if (a>b>c)
		//{
		//	printf("%d\n",d);
		//}
		//else if ((c-1>=d)==1)
		//{
		//	printf("%d\n",d+1);
		//}
		//else
		//{
		//	printf("%d\n",d+2);
		//}//3


		//int x = 8,y,z;
		//y = z = x++;
		//x = y == z;
		//printf("x=%d\n",x);//1



		//struct 
		//{
		//	long num;
		//	char name[20];
		//	union 
		//	{
		//		float y;
		//		short z;
		//	}yz;
		//}xx;
		//printf("sizeof(double):%d\n", sizeof(double));//8
		//printf("sizeof(char):%d\n", sizeof(char));//1
		//printf("sizeof(short):%d\n", sizeof(short));//2
		//printf("sizeof(float):%d\n", sizeof(float));//4
		//printf("sizeof(int):%d\n", sizeof(int));//4
		//printf("sizeof(long):%d\n", sizeof(long));//4
		//printf("sizeof(xx):%d\n",sizeof(xx));//28


		/*int a = 5, b = 6,*p,*q,*r;
		p = &a;
		q = &b;
		r = p;
		p = q;
		q = r;
		printf("%d,%d,%d,%d",*p,*q,a,b);*/	//6,5,5,6


		//int count = 0;
		//for (int i = 0,y=0; (y=123)&&(i<3); i++)
		//{
		//	count++;
		//}
		//printf("%d", count);	//3

		//int i = 0;
		//switch (i)
		//{
		//case 0:printf("%d",i++);	//0
		//case 2:printf("%d", i++);	//1
		//default:printf("%d", i++);	//2
		//	break;
		//}


		//int a, b, c, d;
		//scanf("%4d+%3d+%2d+%1d",&a,&b,&c,&d);	//1234+123+12+1
		//printf("%4d+%3d+%2d+%1d",a,b,c,d);


		//char b1, b2, b3, b4, b5, b6;
		//scanf("%c%c%c%c", &b1, &b2, &b3, &b4);
		//b5 = getchar();	
		//b6 = getchar();	

		//putchar(b1);	//6
		//putchar(b2);	//7

		//printf("%c%c\n",b5,b6);	//1,2


		/*int a = 1234;
		printf("%2d",a);	*///1234


		//char a = 'a', b;
		//printf("%c",++a);	//b
		//printf("%c\n",b=a++);//b


		/*int x = 2, y = 3;
		printf("x|y<<2:%d", x | y << 2);*/	//14


		//int a = 8;
		//int *p = &a;
		//printf("*p:%d",*p);	//8


		//float y = 6 / 5;
		//printf("%f",y);	//1.000000


		//printf("3*(N+7):%d\n",3*(N+7));

		/*int b = 10;
		printf("%d\n",b<<1);*/	//20


		//char a[] = {9,8,7,6,5,4,3,2,1};
		//char *p = a+1;
		//printf("%d\n",*p);	//8


		//int y;
		//int x = y = 3;
		//int t = x + y++;
		//printf("y:%d\n",y);	//4



		//int n= 9;
		//printf("%d\n", n + 1);	//10
		//printf("%d\n", n++);	//9
		
		/*
		int x = 2, y = 12;
		printf("x&y<<2:%d\n",x&y<<2);*/	//0


		//printf("10/3:%d\n",10/3);	//3

		//int a = 4;
		//int b = a^a;
		//printf("b=%d\n",b);//0


		//int i;
		//i = f(2+1);
		//printf("%d\n",i);//5


		//int count=0;
		//for (int i = 2; i < 0; i--)//根本就没进循环体
		//{
		//	printf("%d\n",i);
		//	count++;
		//}
		//printf("count=%d\n",count--);//0


		//char c1 = 'A',c2='Y';
		//printf("%d,%d\n",c1,c2);//65,89

		//if (c1=c2)
		//{
		//	printf("%d,%d\n", c1, c2);//65,89
		//}


		//char str[15] = "hello!";
		//printf("strlen(str):%d\n", strlen(str));//6


		//int a = 1, b = '0';
		//printf("!a:%d\n",!a);//0
		//printf("!b:%d\n", !b);	//0
		//printf("!0:%d\n", !0);	//1
		//printf("!'0':%d\n", !'0');	//0
		//printf("!a==!b: %d\n", !a == !b);	//1
		//printf("!a||!b: %d\n", !a || !b);	//0
		//printf("!(a==b): %d\n", !(a == b));	//1
		//printf("a&&!b: %d\n", a&&!b);	//0

		//int a = 1, b = 2, c = 3;
		//printf("a==c||a+b>=c:%d", a == c || a + b >= c);	//1


		//int n = 1, m = 2;
		//printf("++n: %d,m++: %d\n",++n,m++);	//2,2


		/*int m = 1, n = 2;
		printf("m=n:%d\n",m=n);*/	//2


		/*求 strlen(s) sizeof(s)*/
		//char s[] = "\n123\\";
		//printf("strlen(s)= %d\n",strlen(s));	//5,字符个数，不包含杠铃
		//printf("sizeof(s)= %d\n", sizeof(s));	//6,尺寸大小，包含末尾的杠铃

		/*求 a<b<c*/
		//int a = 4, b = 3, c = 5;
		//printf("a<b<c= %d", a<b<c);//1

		/*a+=a-=a=9*/
		//int a;
		//a += a -= a = 9;
		//printf("a+=a-=a=9 的值是: %d\n", a += a -= a = 9);	//0


		/*#define s(m,n) m/n的值*/
		//printf("#define s(m,n) m/n 的值： %d\n",s(4+2,2+1));	//6

		

		//int x = 11;
		//int y = x++;
		//printf("y= %d\n",y);//y=11
		//printf("x= %d\n", x);//x=12
		//printf("%d,%d\n",(x++,y),y++);	//12,11,(x++,y)逗号表达式，表达式的最终值用最后一个表达式的结果，
	}
	


	/*表达式类*/
	{
		/*const int i;
		i = 100;*/	//error


		//int x = 0x12;
		//int x1 = 1 + 2 = 3;	//error


		//int a#3;	//error


		/*int a[3][4];
		a[1+1][2];*/


		//char ch = '123';
		//char ch1 = '\xff';
		//char ch2 = '\08';//字符常量
		//char ch3 = " ";//error，字符串常量
		//printf("ch=%c\n");
		//printf("ch1=%c\n");
		//printf("ch2=%c\n");
		//printf("ch3=%c\n");


		//char *str = 'abc';//运行时错误
		//char *str1 = "12'12";
		//char *str2 = "0";
		//char *str3 = " ";
		////printf("str=%s",str);
		//printf("str=%s\n", str1);
		//printf("str=%s\n", str2);
		//printf("str=%s\n", str3);


		/*int a, b;	*/	//a,b 为整型
		//b = a / 2;	//合法
		//b = a%2.5;	//不合法
		//a + b = 2;	//不合法

		//char c = '\';//error
		//char c1[] = "\007";//true
		//double d = 1.5E2.0;//error


		//int arr[2 + 3];//true
		//int i = 5, d[i];//error 必须含常量值

		//int c[][3] = { {3},{3},{4} };
		//int c[][3] = { { 3 }, {  }, { 4 } };//error

	}
}


/*************************************************************************************************************************/
/*************************************************运行结果类***************************************************************/
void categoryOperationResult()
{
	/*嘉应2018-3-2:*/
	//{
	//	int i, j, x = 0;

	//	for ( i = 0; i < 2; i++)
	//	{
	//		for ( j = 0; j < 3; j++)
	//		{
	//			if (j%2==0)
	//			{
	//				continue;
	//			}

	//			x = x + 1;
	//		}

	//	}

	//	printf("%d\n",x);	//2
	//}


	/*嘉应2018-3-1:*/
	//{
	//	int i, sum = 0;
	//	for ( i = 1; i <= 20; i++)
	//	{
	//		sum += i;
	//	}

	//	printf("%d\n",sum);	//210
	//}


	/*广技师2017-4-6:*/
	//{
	//	int k = 4, m = 1, p;

	//	p = func5(k,m);		//
	//	printf("%d\n",p);	//8

	//	p = func5(k, m);
	//	printf("%d\n", p);	//17
	//}


	/*广技师2017-4-5:*/
	//{
	//	int x[] = {0,1,2,3,4,5,6,7,8,9};
	//	int s, i, *p;

	//	s = 0;
	//	p = &x[0];

	//	for ( i = 1; i < 10; i+=2)
	//	{
	//		s += *(p + i);
	//	}

	//	printf("sum=%d",s);	//sum=25
	//}


	/*广技师2017-4-4:*/
	//{
	//	int a = 7, b = 2;
	//	float x = 2.5, y = 4.7, z;

	//	z = x + a % 3 * (int)(x + y) % 2 / 4;
	//	printf("%df\n",z);	//0f

	//	z = (a + b) / 2 + (int)x % (int)y;	//6.000000
	//	printf("%f\n",z);
	//}


	/*广技师2017-4-3:*/
	//{
	//	int x = 9;
	//	for (; x>0; x--)
	//	{
	//		if (x%3==0)
	//		{
	//			printf("%d",--x);	//852
	//			continue;
	//		}
	//	}
	//}


	/*广技师2017-4-2:*/
	//{
	//	int m = 37, n = 13;

	//	while (m!=n)
	//	{
	//		m = m - n;

	//		while (n>m)
	//		{
	//			n -= m;
	//		}
	//	}

	//	printf("m=%d\n",m);	//m=1;
	//}


	/*广技师2017-4-1:*/
	//{
	//	int x = 10, y = 10, i;
	//	for ( i = 0; i >8; y=++i)
	//	{
	//		printf("%d %d",x--,y);	//无输出
	//	}
	//}


	/*韩师2010-3-4:*/
	//{
	//	int b = 1;
	//	int a = 3;
	//	printf("%d\n",func3(a+func3(b)));//6,15,15
	//}


	/*韩师2010-3-3:*/
	/*{
		for (int i = 0; i < 6; i++)
		{
			if (i%2)
			{
				printf("#");
				continue;
			}
			printf("*");
		}
		printf("\n");
	}*/


	/*韩师2010-3-2:*/
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		switch (i)
	//		{
	//		case 0:printf("%d",i);
	//		case 2:printf("%d", i);
	//		default:printf("%d", i);
	//		}
	//	}//000122
	//}


	/*韩师2010-3-1:*/
	/*{
		char str[] = "1234567";
		int i;
		for ( i = 0; i < 7; i+=3)
		{
			printf("%s\n",str+i);
		}
	}*/


	/*韩师2013-4-1:求矩阵ab的乘积，结果存入矩阵c中*/
	/*{
		int a[2][3] = {3,2,-1,-4,5,6};
		int b[2][2] = { 7, 6 ,-5,3};
		int s, c[3][2];

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				for (int k = 0; k < 2; k++)
				{
					s+=a[i][k] * b[k][j];
				}
				c[i][j] = s;
			}

		}
	}*/


	/*韩师2013-3-5:*/
	/*{
		char s[]="Yes\nNo";
		char *ps = s;
		puts(ps+4);
		*(ps + 4) = 0;
		puts(s);
	}*/


	/*韩师2013-3-4:*/
	//{
	//	int i;
	//	i = f(4 + 4) / f(2 + 2);
	//	printf("%d\n",f(4+4));	//24
	//	printf("%d\n", f(2+2));	//8
	//	printf("%d\n",i);	//28
	//}


	/*韩师2013-3-3:*/
	/*{
		char st[] = {"abcdefg"};
		wr(st,5);
	}*/


	/*韩师2013-3-2:*/
	/*{
		int a[5] = { 1, 1 };
		int i, j;

		printf("%d%d\n",a[0],a[1]);

		for ( i = 1; i < 4; i++)
		{
			a[i] = a[i - 1] + a[i];
			a[i + 1] = 1;

			for ( j = 0; j <= i+1; j++)
			{
				printf("%d",a[j]);
			}

			printf("\n");
		}
	}*/


	/*韩师2013-3-1:*/
	//{
	//	int i = 0, a = 0;

	//	while (a<20)
	//	{
	//		for (;;)
	//		{
	//			if (i%10==0)
	//			{
	//				break;
	//			}
	//			else
	//			{
	//				i--;
	//			}
	//		}

	//		i = 11;
	//		a += i;
	//		printf("%d ",a);	//11 22
	//	}
	//}


	/*韩师2013-4-3:*/
	/*{
		int a[N] = {9,11,23,6,1,15,9,17,20};
		int max, n;

		max = select1(a, &n);

		printf("max=%d,n=%d\n",max,n);
	}*/


	/*韩师2013-4-1:打印99乘法表*/
	/*{
		int i, j;

		for ( i = 1; i < 10; i++)
		{
			for ( j = 1; j <= i; j++)
			{
				printf("%d*%d=%2d\t",i,j,i*j);
			}

			printf("\n");
		}
	}*/

	/*韩师2013-3-5*/
	/*{
		if (100)
		{
			printf("Great!\n");
		}
		else if (60)
		{
			printf("Pass!\n");
		}
		else
		{
			printf("Fail!\n");
		}
	}*/


	/*韩师2013-3-3*/
	//{
	//	printf("%d\n",func2(2));	//4
	//}


	/*韩师2013-3-2*/
	//{
	//	char p[] = {'a','b','c','\0'};
	//	char q[10] = { 'a', 'b', 'c'};
	//	printf("%d\n",strlen(q));	//3
	//	printf("%d\n", strlen(p));	//3
	//}



	/*韩师2014-4-3：矩阵主次对角线之和*/
	//{
	//	int a[3][3] = {9,7,5,1,2,4,6,8,0};
	//	int i, j, s1 = 0, s2 = 0;

	//	for ( i = 0; i < 3; i++)
	//	{
	//		for ( j = 0; j < 3; j++)
	//		{
	//			if (i==j)//主对角线
	//			{
	//				s1 = s1 + a[i][j];
	//			}
	//			if (i+j==2)//次对角线
	//			{
	//				s2 = s2 + a[i][j];
	//			}
	//		}
	//	}

	//	printf("%d\n%d\n",s1,s2);//11,12
	//}


	/*韩师2014-4-2：韩信点兵*/
	/*{
		int x = 1;
		int find = 0;
		
		for ( x = 0; x < 10000; x++)
		{
			if (x%5==1 && x%6==5 && x%7==4 && x%11==10)
			{
				printf("x=%d\n",x);
				find = x;
			}
		}
	}
*/

	/*韩师2014-4-1：闰年*/
	/*{
		int year, leap;

		printf("请输入年份：\n");
		scanf("%d",&year);

		if ((year%4==0) && !(year%100==0) || (year%400==0))
		{
			leap = 1;
		}
		else
		{
			leap = 0;
		}

		if (leap)
		{
			printf("是闰年\n");
		}
		else
		{
			printf("不是闰年\n");
		}
	}*/


	/*韩师2014-3-5*/
	//{
	//	enum type{a,b=-5,c,d=6,f,g=9};
	//	printf("%d,%d,%d",a,c,f);//0,-4,7
	//}


	/*韩师2014-3-4*/
	//{
	//	char s[] = "abcdef";
	//	s[3] = '\0';
	//	printf("%s\n",s);//abc
	//}



	/*韩师2014-3-3*/
	/*{
		int a[8] = {4,8,12,16,20,24,28,32};
		int * p=a;

		do
		{
			printf("%d\t",*p);
			p++;
		} while (p<a+8);
	}*/


	/*韩师2014-3-2*/
	//{
	//	int a = 10, b = 20;
	//	int c = max1(a, b);
	//	printf("max=%d\n",c);//20
	//}


	/*韩师2014-3-1*/
	//{
	//	int i = 1, sum = 0;
	//	do
	//	{
	//		sum = sum + i;
	//		i = i + 1;
	//	} while (i<=10);

	//	printf("sum=%d\n",sum);//55
	//	printf("i=%d\n",i);//11
	//}


	/*韩师2015-2-17*/
	//{
	//	int count = 0;
	//	for (int i = 0,x=876; i < 6&& x!=876; i++)
	//	{
	//		count++;
	//	}
	//	printf("count: %d", count);//0
	//}


	/*
		实际情况是，除 char 外，所有其他类型都有“对齐要求”
		公式1:每个变量（无论是数组还是联合体）必须以自己最大基本数据类型倍数开始的地址开始，如果不是，填充。
		公式2:整个Struct的地址必须是最大基本数据类型字节的整数倍，如果不是，填充。
	*/
	//struct stud
	//{
	//	char num[6];
	//	double ave;
	//}a;

	///*韩师2015-2-16*/
	//{
	//	printf("sizeof(a): %d\n",sizeof(a));//16,字节对齐
	//}


	/*韩师2015-2-13*/
	//{
	//	int x = -1;
	//	int count = 0;
	//	do
	//	{
	//		x = x*x;
	//		count++;
	//	} while (!x);

	//	printf("count:\n", count);//死循环
	//}


	/*韩师2015-2-11*/
	/*{
		int k = 1;
		
		switch (k)
		{
		case 1:printf("%d\n",k++);
		case 2:printf("%d\n", k++);
		case 3:printf("%d\n", k++);
		case 4:printf("%d\n", k++); break;
		default:printf("Full!\n");
			break;
		}
	}*/



	/*韩师2016-2-19*/
	/*{
		union data
		{
			int i;
			char ch;
			double f;
		}x;

		printf("sizeof(x)=%d\n",sizeof(x));//8
	}*/



	/*韩师2016-2-18*/
	/*{
		int count = 0;
		for (int i = 5; i > 0; i--)
		{
			for (int j = 0; j < 4; j++)
			{
				count++;
			}
		}

		printf("count=%d\n",count);//20

	}*/



	/*韩师2016-2-17*/
	/*{
		int i;
		char string[20],str[3][20];

		for (int i = 0; i < 3; i++)
		{
			gets(str[i]);//abc,abcd,abba
		}

		strcpy(string, scmp(str[0], str[1]));//string="abc",abc<abcd
		strcpy(string, scmp(string, str[2]));//string="abba",abc>abba
		printf("strcmp(abc,abba):%d\n", strcmp("abc", "abba")); //返回值为1，证明abc>abba
		printf("string:%s\n", string);//abba
	}*/



	/*韩师2016-2-16*/
	//{
	//	char a[30], b[30];
	//	int k;

	//	gets(a);//blue
	//	gets(b);//sky

	//	/*strcmp(char * s1,char * s2)该函数从第一个字符开始，依次比较每个字符的 ASCII 码大小，
	//	  首先将s1字符串的第一个字符值减去s2第一个字符，若差值为零则继续比较下去；若差值不为零，则返回差值。
	//	  直到出现不同的字符或遇'\0'为止。
	//		返回值	含义
	//		< 0	字符串 1 的字符小于字符串 2 对应位置的字符
	//		0		两个字符串的内容完全一致
	//		> 0	字符串 1 的字符大于字符串 2 对应位置的字符
	//	*/
	//	k = strcmp(a,b);//
	//	if (k>0)
	//	{
	//		puts(a);
	//	}
	//	else if (k<0)
	//	{
	//		puts(b);
	//	}
	//	//result:sky
	//}


	/*韩师2016-2-14*/
	/*{
		struct tree tree;
		tree.x = 3;
		tree.s = "minicar";
		func1(tree);

		printf("tree.x=%d,tree.x=%s\n", tree.x, tree.s);//tree.x=3,tree.s="minicar",传值不改变
	}*/



	/* j与k进行或运算，（若j不为0，则或运算的结果为1,或运算以后j自加1，
	   k不变，因为j不为0就可判断或运算结果为1，不需要对k判断；
	   若j为0，则或运算后，j和k的值都自加1。）

       j和k或运算的结果（0或者1）在与i进行与运算（若或运算的结果为0，则与运算的结果为0，i的值不进行自加1操作，
	   因为0和任何数与都是0，不需要再对i判断了；
	   若前面或运算的值为1，则再与i与运算后，i的值自加1）
	*/
	//{
	//	int i = 1, j = 1, k = 2;

	//	if ((j++ || k++) && i++)
	//	{
	//		printf("%d,%d,%d\n",i,j,k);//2,2,2
	//	}
	//}


	/*累加第2列*/
	/*{
		int a[][4] = 
		{
			{ 1, 2, 3, 4 },
			{ 5, 6, 7, 8 },
			{ 3, 9, 10, 2 },
			{ 4, 2, 9, 6 }
		};

		int i, s = 0;
		for ( i = 0; i < 4; i++)
		{
			s += a[i][1];
		}
		printf("%d\n", s);//19
	}*/
	


	/*韩师2017-19*/
	/*{
		int i, j, k = 0;

		for ( j = 0; j <= 60; j++)
		{ 
			if (!(k%10))
			{
				printf("\n");
			}

			for ( i = 2; i < j; i++)
			{
				if (!(j%i))//if(!(j%i))等同于if(j%i==0),如果j能够被i整除，则执行下面的命令
				{
					break;
				}
			}

			if (i>=j-1)
			{
				printf("%d ",j);
				k++;
			}
		}
	}*/

	/*韩师2016-2-3*/
	/*{
		int a[][3] = { {1,2,3}, {4,5,6} }, (*pa)[3], i;

		pa = a;
		for (int i = 0; i < 3; i++)
		{
			if (i<2)
			{
				pa[1][i] = pa[1][i]-1;
			}
			else
			{
				pa[1][i] = 1;
			}
		}

		printf("%d\n",a[0][1]+a[1][1]+a[1][2]);//7
	}*/


	/*韩师2016-2-9*/
	/*{
		int k = 10;
		
		switch (k)
		{
		case 9: k += 1;
		case 10: k += 1;
		case 11:k += 1; break;

		default:k += 1;
			break;
		}

		printf("k=%d\n",k);//12
	}*/


	/*韩师2016-2-11*/
	/*{
		int c[] = {1,2,3,4,5};
		int *p;

		p = c;

		printf("*p=%d\n",*p);//1
		printf("*++p=%d\n", *++p);//2
	}*/


	/*韩师2016-2-12*/
	/*{
		int a = 2, b = 3, c = 6, d = 4,x=0;

		if (a<b)
			if (c < d) x = 5;
			else if (a<c)
				if (b<d) x = 2;
				else x = 3;
			else x = 6;
		else x = 7;
		

		printf("x=%d",x);//2
	}*/


}




/*************************************************************************************************************************/
/***************************************************阅读程序段类型**********************************************************/
void categoryReadProgram()
{
	/*韩师2010-4.阅读程序或程序段-2：func3函数以删除字符串中指定的字符*/


	/*韩师2010-4.阅读程序或程序段-1：func3函数以删除字符串中指定的字符*/
	/*{
		char str[] = "abcdefgAbcd", ch;
		printf("请输入需要删除的字符：\n");
		scanf("%c",&ch);

		func4(str,ch);
		printf("%s\n",str);
	}*/


	/*韩师2015-4.阅读程序或程序段-3：sum=1+2+3+4+5+...+n*/
	/*{
		int n, i, s = 0;
		
		printf("输入一个整数（格式：n）：\n");
		scanf("%d",&n);

		for ( i = 1; i <= n; i++)
		{
			s += i;
		}

		printf("1+2+3+4+5+...+n= %d\n",s);
	}*/


	/*韩师2015-4.阅读程序或程序段-5：密码5位数，67**8，用39和14的倍数做密码(你这个和是几个意思？)*/
	/*{
		long m;

		for ( m = 67008; m <= 67998; m++)
		{
			if ((m%39==0)||(m%14==0))
			{
				printf("%ld\n",m);
			}
		}
	}*/



	/*韩师2015-4.阅读程序或程序段-1：在N行M列的二维数组中，找出最小值,以及最小值所在的行下标*/
	/*{
		int a[N1][M1] = 
						{
			
							21,11,23,
							6,1,15,
							9,0,20
						};
		int i, j, row = 0,min=a[0][0];

		for ( i = 0; i < N1; i++)
		{
			for ( j = 0; j < M1; j++)
			{
				if (a[i][j]<min)
				{
					min = a[i][j];
					row=i;
				}
			}
		}

		printf("min=%d,line=%d\n",min,row);

	}*/


	/*韩师2015-3.阅读程序-5*/
	//{
	//	char food[] = "Bread";
	//	char * p;
	//	p = food;
	//	puts(p);//Bread
	//}



	/*韩师2015-3.阅读程序-4*/
	//struct date
	//{
	//	int a;
	//	char s[5];
	//}arg = { 27, "abcd" };

	//{
	//	arg.a = 5;
	//	strcpy(arg.s,"ABCD");
	//	printf("%d,%s",arg.a,arg.s);//5,ABCD
	//}


	/*韩师2015-3.阅读程序-3*/
	//{
	//	char string1[64] = "abc";
	//	char * string2 = "def";
	//	char string3[] = "123";

	//	strcat(string1,string2);
	//	strcat(string1, string3);

	//	printf("%d\n",strlen(string1));//9
	//}


	/*韩师2015-3.阅读程序-2*/
	//{
	//	int a[3] = {1,2,3};
	//	int i, s = 0;

	//	for ( i = 1; i < 3; i++)
	//	{
	//		s += a[i];
	//	}

	//	printf("%d\n",s);//5
	//}



	/*韩师2015-3.阅读程序-1*/
	//{
	//	int a = 0;
	//	a += (a = 8);
	//	printf("%d\n",a);//16
	//}



	/*韩师2016-4.阅读程序或程序段-5：删除字符串中s中的所有数字字符*/
	/*{
		char s[] = "1234546abc";
		int n = 0;

		printf("源字符串：%s\n",s);

		for (int i = 0; s[i]; i++)
		{
			if (s[i]<'0' || s[i]>'9')//非数字字符
			{
				s[n++] = s[i];//将非数字字符保存起来
				s[n] =0;//s[n]=0等同于s[n]='\0'。\0'是字符串结束符
			}
		}

		printf("删除数字字符后的字符串：%s\n", s);
	
	}*/


	/*韩师2016-4.阅读程序或程序段-4：用变量count统计文件中的字符个数*/
	/*{
		FILE * fp;
		long count = 0;

		if ((fp=fopen("./TestData/filetest.txt","r"))==NULL)
		{
			printf("打开文件失败！\n");
			exit(EXIT_FAILURE);
		}

		while (!feof(fp))
		{
			fgetc(fp); //用于读取文件中的一个字符，和while构成循环
			count++;//10个
		}

		printf("count=%d\n",count);
		fclose(fp);
	}*/


	/*韩师2016-4.阅读程序或程序段-3：卖512个瓜，第一天卖一半多2个，以后每天卖剩下的一半多2个，几天卖完？*/
	/*{
		int day=0, x1=512, x2;

		while (x1!=0)
		{
			x2 = x1 / 2 -2;
			x1 = x2;
			day++;
		}

		printf("day=%d\n",day);
		
	}*/

	/*韩师2016-4.阅读程序或程序段-2：辗转相除法求最大公约数*/
	/*{
		int r, m, n;

		printf("请输入2个整数：格式（m,n）\n");
		scanf("%d,%d",&m,&n);

		if (m<n)
		{
			r = m;
			m = n;
			n = r;
		}

		r = m%n;

		while (r)
		{
			m = n;
			n = r;
			r = m%n;
		}

		printf("最大公约数：%d\n",n);
	}*/


	/*韩师2016-4.阅读程序或程序段-1：計算1-100的整数的累加和*/
	/*{
		int i=1;
		int sum = 0;

		for (; i <= 100;)//初始化条件可以省略，但是要写分号
		{
			sum += i;
			i++;
		}

		printf("sum=%d\n",sum);
	}*/


	/*韩师2016-3.阅读程序-4*/
	/*{
		int a = 100;
		fun(&a);//0
	}*/



	/*韩师2016-3.阅读程序-4*/
	/*{
		for (int i = 4; i >= 1; i--)
		{
			printf("* ");
			for (int j = 1; j <= 4-i; j++)
			{
				printf("* ");
			}

			printf("\n");
		}
	}*/


	/*韩师2016-3.阅读程序-3*/
	/*{
		int number = 12123;
		int digit;
		int s = 0;

		do
		{
			digit = number % 10;
			number /= 10;
			s += digit;
		} while (number!=0);

		printf("s=%d\n",s);//9
	}*/



	/*韩师2016-3.阅读程序-2*/
	//{
	//	struct s
	//	{
	//		int x;
	//		int y;
	//	}data[2] = {100,10,20,200};

	//	//data[2] = {100,10,20,200};等价于如下定义
	//		/*data[0].x = 10
	//		data[0].y = 100
	//		data[1].x = 20
	//		data[1].y = 200*/

	//	struct s * p = data;//p指向了数组data的第一个元素即：data[0]
	//	printf("%d\n",++(p->x));//101,p->x:p指向了数组data的第一个元素的x成员
	//}



	/*韩师2016-3.阅读程序-1*/
	/*{
		int i = 3, j = 2;
		printf("%d\n",MCRB(j,MCRA(i)));//33
	}*/



	/*韩师2017-3.阅读程序-3*/
	/*{
	union bb
	{
	long x[2];
	int y[4];
	char z[8];
	}atx;

	struct aa
	{
	long x[2];
	int y[4];
	char z[8];
	}stx;

	printf("sizeof(int): %d\n",sizeof(int));//4
	printf("sizeof(long): %d\n", sizeof(long));//4
	printf("sizeof(char): %d\n", sizeof(char));//1
	printf("sizeof(float): %d\n", sizeof(float));//4
	printf("sizeof(double): %d\n\n", sizeof(double));//8

	printf("sizeof(atx.z): %d\n", sizeof(atx.z));//8
	printf("sizeof(atx.y): %d\n", sizeof(atx.y));//16
	printf("sizeof(atx.x): %d\n", sizeof(atx.x));//8
	printf("sizeof(atx): %d\n\n", sizeof(atx));//16，共用体：最长尺寸

	printf("sizeof(stx): %d\t\n", sizeof(stx));//32，结构体，求和
	printf("sizeof(stx.z): %d\t\n", sizeof(atx.z));//8=1*8
	printf("sizeof(stx.y): %d\t\n", sizeof(atx.y));//16=4*4
	printf("sizeof(stx.x): %d\t\n", sizeof(atx.x));//8=2*4
	}*/


	/*韩师2017-3.阅读程序-4*/
	/*{
		char str[] = "tomeetme", str1[] = "toseeyou";
		char * p = str, *p1 = str1;

		for (int i = 0; i < 7; i++)
		{
			if (*(p + i) == *(p1 + i))
			{
				putchar(*(p + i));//toee
			}
		}

		printf("\n");
	}*/


	/*韩师2017-4.阅读程序-2:100~500之间有多少个数各位数字之和是8*/
	/*{
		int num,sum,count=0;

		for (int i = 100; i <= 500; i++)
		{
			sum = 0;
			num = i;

			//循环求每个数各位数的和 
			//while (num!=0)//while(num)
			//{
			//	//sum = sum + num % 10;//num%10:个位
			//	//num = num / 10;//得到一个2位数，即百位和十位，比如131得到13，
								//再进行while循环，num%10取得3累加到sum，然后13/10取得1，
								//再while循环进来后，1%10取得1累加到sum，接着1/10==0,跳出循环
			//}

			int x = num / 100; // 百位
			int y = (num % 100) / 10; // 十位
			int z = (num % 100) % 10; // 个位
			sum = x + y + z;

			if (sum!=8)
			{
				continue;
			}
			else
			{
				printf("%d\t",i);
				count++;
			}

			if (count % 5 == 0)
			{
				printf("\n");
			}
		}

		printf("\n\n一共有：%d个\n",count);
	}*/


	/*韩师2017-4.阅读程序-3*/
	//{
	//	/*总结：
	//	在c中，const是指不能被改变的变量，占有存储空间，所以编译器并不知道编译时的值，
	//	所以不知道该给数组定义多大的，而且数组定义时的下标必须为常量*/
	//	//const int N = 20;
	//	//int arr[N];//error

	//	int arr[N];
	//	printf("请输入20个整数：\n");
	//	for (int i = 0; i < N; i++)
	//	{
	//		scanf("%d",&arr[i]);
	//	}

	//	for (int i = 0; i < N; i++)
	//	{
	//		if ((i%4)==0)
	//		{
	//			printf("\n");

//		}
	//		printf("%8d,",arr[i]);
	//	}
	//}



/*韩师2017-4.阅读程序-4:字符串逆序存放*/
	/*{
		char charac;
		char str[60];
		int i, j;

		printf("输入一个字符串：\n");
		gets(str);

		for ( i = 0, j=strlen(str)-1;i<(strlen(str)/2); i++,j--)//数组下标从0开始，j初始化的时候可做-1处理，循环次数只需要字符串长度的一半即可，头尾交换
		{
			charac = str[i];
			str[i] = str[j];//若初始化时，j未做-1处理，此处需要做-1处理，否则下标越界
			str[j] = charac;
		}

		puts(str);
	}*/

}



