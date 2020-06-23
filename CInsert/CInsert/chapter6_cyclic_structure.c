#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter6_cyclic_structure.h"



/*chapter6 循环结构 测试函数*/
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

/*用公示求pi的近似值 p124*/
void calcApproximateValueOfPI()
{
	int s;
	float n, t, pi;			//pi一开始代表多项式的值，最后代表pi的值

	t = 1;					//当前项的值
	pi = 0;
	n = 1.0;				//通过它计算分母
	s = 1;					//用来表示数值的符号

	while (fabs(t)>1e-6)	//fabs()：求绝对值函数，结果为浮点型，t是浮点型所以不能用 abs()
	{
		pi = pi + t;		//把当前项term累加到pi中
		n = n + 2;			//n+2是下一项的分母
		s = -s;				//sign代表数值符号，下一项符号与上一项符号相反
		t = s / n;			//求出下一项的值term
	}

	pi = pi * 4;			//多项式的和*4，才是pi的近似值

	printf("PI= %10.6f\n",pi);
}


/*求Fibonacci数列前40个数
  第1、2两个数为1、1
  从第3个数开始，该数是其前面两个数之和
*/
void calcFibonicci40()
{
	long int f1, f2;			//第23个数之后，整数值已超过32767
	int i;
	f1 = 1;
	f2 = 1;

	for ( i = 0; i < 20; i++)	//i每增值1，计算和输出2个数,故循环20次即可
	{
		printf("%12ld %12ld",f1,f2);

		if (i%2==0)				//输出10行
		{
			printf("\n");
		}

		f1 = f1 + f2;			//计算出下一个数，并存放在f1中
		f2 = f2 + f1;			//计算出下2个数，并存放在f2中
	}
}


/*判断 num 是否为素数*/
void calcPrimeNum()
{
	int num, i, k;

	printf("请输入一个整数：\n");
	scanf("%d",&num);

	k = sqrt(num);

	for (i = 2; i <= k; i++)//让 num 被 2~sqrt(num) 之间的数除，如果其中的任何一个整数整除，提前结束循环
	{
		if (num%i == 0)
		{
			break;			//此时i的值必然小于或等于sqrt(num)
		}
	}

	if (i > k)				//若i的值大于或等于sqrt(num)+1，即大于sqrt(num)，则表明未曾被2~sqrt(num)之间的任一整数整除过
	{
		printf("%d is a prime number\n",num);
	}
	else
	{
		printf("%d is not a prime number\n",num);
	}
}



/*求100~200之间的全部素数*/
void calcPrimeNum100_200()
{
	int num, i, k,n=0;

	for ( num = 101; num <= 200; num=num+2)
	{
		k = sqrt(num);

		for (i = 2; i <= k; i++)//让 num 被2到sqrt(num)之间的数除，如果其中的任何一个整数整除，提前结束循环
		{						//根据常识，偶数不是素数，所以不必进行判定，故外层循环从101开始，每次增值2
			if (num%i == 0)
			{
				break;			//，终止内循环，此时i的值必然小于或等于sqrt(num)
			}
		}

		if (i >=k+1)			//若i的值大于或等于sqrt(num)+1，即大于sqrt(num)，则表明未曾被2~sqrt(num)之间的任一整数整除过
		{
			printf("%d ", num);
			n = n + 1;			//累计输出素数的个数
		}

		if (n%10==0)			//控制每行输出10个
		{
			printf("\n");
		}
	}

	printf("\n");
}


/*最大公约数和最小公倍数
  Greatest common divisor and least common multiple

*/
void calcGcdAndLcm()
{
	int num1, num2;				//两个正整数
	int remainder;				//余数
	int lcm;					//Least common multiple:最小公倍数
	int gcd;					//Greatest common divisor:大公约数
	int temp;					//临时变量

	printf("请输入两个正整数：格式（num1，num2）\n");
	scanf("%d,%d",&num1,&num2);

	if (num1<num2)				//若num1<num2，交换2数，确保 num1 为较大的那一个数
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}

	lcm = num1*num2;			//若num1 不小于 num2，则让两数相乘赋值给lcm

	while (num2!=0)				//用辗转相除法，即 mod 操作，直到余数为0
	{
		remainder = num1%num2;	//找到用较小的数字除去较大数字的余数，换句话说：用较大的数字和较小的数字进行 mod 操作
		num1 = num2;			//num2为较小的那个数，把它复制给num1
		num2 = remainder;		//把余数赋值给num2，下一次循环进来后实际上是：用除数num1（num2）和余数remainder进行mod操作，直到余数为0（整除）
	}

	gcd = num1;					//当余数变为0时，最后一个操作的除数即为2数的最大公约数
	lcm = lcm / gcd;			//2数相乘再除以最大公约数即为最小公倍数

	printf("它们的最大公约数为： %d\n",gcd);
	printf("它们的最小公倍数为： %d\n", lcm);
}



/*输入一行字符，分别统计出其中英文字母，空格，数字和其他字符的个数*/
void calcCharacterQuantity()
{
	int characCnt=0;		//英文字母数量
	int spaceCnt=0;			//空格数量
	int digitCnt=0;			//数字的数量
	int otherCharacCnt=0;	//其他字符的数量
	char charac;			//接收输入的字符

	printf("请输入一行字符：\n");

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

	printf("英文字母的个数为： %d\n空格的个数为： %d\n数字的个数为： %d\n其他字符的个数为： %d\n",characCnt,spaceCnt,digitCnt,otherCharacCnt);
}


/*求Sn=a+aa+aaa+...+aaa..a的值，其中a是一个数字，n表示a的位数
  例如：2+22+222+2222+22222（此时n=5），n由键盘输入
*/
void calcSn()
{
	int a, n;		//a：数； n：位数
	int i = 1;
	int sn = 0;		//多项式前i项的和
	int tn = 0;		//i个a所组成的数的值

	printf("请输入a和n的值：（格式：a，n）\n");
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



/*求1！+2！+3！+...+20！*/
void calcSumOfFactorials1To20()
{
	double sn=0;								//存放阶乘的和
	double t = 1;								//计算阶乘
	int n;

	for ( n = 1; n <=20; n++)
	{
		t = t*n;
		sn = sn + t;
	}

	printf("1！+2！+3！+...+20！= %22.15e\n",sn);//用22.15e格式输出，数据宽度为22，小数为数为15位
}


/*求（1+2+3+...+100）+(1^2+2^2+...+50^2)+(1+1/2+1/3+...+1/10)的和*/
void calcSumOfPolynomials()
{
	int n1 = 100;				//多项式1的项数
	int n2 = 50;				//多项式2的项数
	int n3 = 10;				//多项式3的项数
	double s1 = 0;				//多项式1的和:（1+2+3+...+100）
	double s2 = 0;				//多项式2的和:(1^2+2^2+...+50^2)
	double s3 = 0;				//多项式3的和:(1+1/2+1/3+...+1/10)
	double k;
	double sum;					//多项式1的和+多项式2的和+多项式3的和

	for ( k = 1; k <= n1; k++)	//计算1~100的和
	{
		s1 = s1 + k;
	}

	for (k = 1; k <= n2; k++)	//计算1~50各数的平方和
	{
		s2 = s2 + k*k;
	}

	for (k = 1; k <= n3; k++)	//计算1~10的各倒数和
	{
		s3 = s3 + 1/k;
	}

	printf("sum=%15.6f\n",s1+s2+s3);
}


/*输出所有水仙花数：指一个3位数，其各位数字立方和等于该数本身
  例如：153=1+125+27
*/
void calcDaffodilNum()
{
	int indiv;						//个位
	int ten;						//十位
	int hundred;					//百位
	int n;

	printf("水仙花数有：\n");

	for ( n = 100; n < 1000; n++)
	{
		hundred = n / 100;			//百位
		ten = n / 10 - hundred * 10;//十位
		indiv = n % 10;				//个位

		//if (n==hundred*hundred*hundred+ten*ten*ten+indiv*indiv*indiv)
		if (n==pow(hundred,3)+pow(ten,3)+pow(indiv,3))
		{
			printf("%d ",n);
		}
	}

	printf("\n");
}



/*找出1000之内的所有完数
  完数：一个数如果恰好等于它的因子之和
  例如：6=1+2+3
*/
void calcCompleteNumWithin1000()
{
	int num;								//整数
	int factorSum;							//整数因子之和
	int i;

	for ( num = 2; num < 1000; num++)
	{
		factorSum = 0;

		for ( i = 1; i < num; i++)
		{
			if ((num%i) == 0)				//如果num能被i整除，说明i是num的因子
			{
				factorSum = factorSum + i;	//累加因子的和
			}
		}

		if (factorSum==num)					//如果因子的和等于该数，则为完数
		{
			printf("%d,是完数,因子有：",num);

			for (i = 1; i < num; i++)
			{
				if (num%i == 0)
				{
					printf("%d，", i);		//输出该数的因子
				}
			}

			printf("\n");//完整找着了一个，换行输出
		}
	}
}



/*求数列的前20项之和
  数列：2/1 + 3/2 + 5/3 + 8/5 + 13/8 + 21/13+...
  规律：后一项的分母等于前一项的分子，
	   前一项的分子分母相加等于后一项的分子
*/
void calcSequenceSumTop20Items()
{
	int i;
	int count = 20;											//项数
	double molecule = 2;									//分子
	double denominator = 1;									//分母
	double sequenceSum = 0;									//数列前n项的和
	double temp;

	for ( i = 0; i <= count; i++)
	{
		sequenceSum = sequenceSum + molecule / denominator;	//累加数列和
		temp = molecule;									//把前一项的分子保存到临时变量
		molecule = molecule + denominator;					//计算后一项的分子=前一项的分子+分母
		denominator = temp;									//计算后一项的分母=前一项的分子
	}

	printf("sequenceSum=%16.10f\n",sequenceSum);
}


/*应用题1：一个球从100m高度自由落下，每次落地后反跳回原高度的一半，再落下，再反弹
      求：它在第10次落地时，共经过多少米，第10次反弹多高
*/
void calcApplicationQuestions1()
{
	double metersPassed = 100;							//n次落地时共经过的米数，一开始表示第一次落地时经过的米数
	double bounceHeight = metersPassed / 2;				//n次反跳高度：一开始为原高度的一半
	int count;

	for ( count = 2; count <= 10; count++)
	{
		metersPassed = metersPassed + 2 * bounceHeight;	//第n次落地时共经过的米数
		bounceHeight = bounceHeight / 2;				//第n次反跳高度
	}

	printf("第10次落地时共经过:%f米\n",metersPassed);
	printf("第10次反弹:%f米\n",bounceHeight);

}


/*求一个3*3的整型矩阵对角线元素之和*/
void calcSumOfProofDiagonal()
{
	int arr[3][3];
	int sum=0;

	printf("输入一个3*3的矩阵:（格式：num1，num2,.....用逗号隔开）\n");
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


/*有一个已排好序的数组，要求输入一个数后，按原来排序的规律将它插入数组中*/
void calcInsertNum()
{
	int arr[11] = {1,4,6,9,13,16,19,28,40,100};
	int temp1, temp2, num, end;

	printf("原来排序过的数组：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%d,",arr[i]);
	}

	end = arr[9];								//原数组最后一个元素

	printf("\n请输入需要插入的一个数：\n");
	scanf("%d",&num);

	if (num>end)								//如果该数大于原数组最后一个元素，将该数插到数列尾
	{
		arr[10] = num;
	}
	else                                       //该数应插入到arr[0]~arr[i-1]之间
	{
		for (int i = 0; i < 10; i++)
		{
			if (arr[i]>num)						//则应插到arr[i-1]之后，arr[i]之前
			{
				temp1 = arr[i];
				arr[i] = num;					//将num插在arr[i]处

				for (int j = i+1; j < 11; j++)	//将原来第i个元素之后的所有元素下标依次递增1
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