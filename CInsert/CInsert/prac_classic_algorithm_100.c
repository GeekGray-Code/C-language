#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

#include"prac_classic_algorithm_100.h"



/*pracClassicAlgorithm100 测试函数*/
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
C 练习实例67
题目： 输入数组，最大的与第一个元素交换，最小的与最后一个元素交换，输出数组。。

程序分析： 谭浩强的书中答案有问题

*/
void prac67()
{
	void printArr(int arr[], int arrLen);
	void moveArr(int arr[], int arrLen, int offset);


	int arr[20];
	int arrLen, offset;

	printf("请输入数组的大小：\n");
	scanf("%d",&arrLen);

	printf("请输入数组的内容：\n");
	for (int i = 0; i < arrLen; i++)
	{
		scanf("%d", &arr[i]);
	}

	printf("请输入数组的滚动偏移量：\n");
	scanf("%d", &offset);

	printf("打印滚动前的数组：\n");
	printArr(arr,arrLen);

	printf("打印滚动后的数组：\n");
	moveArr(arr, arrLen, offset);//滚动数组
	printArr(arr,arrLen);
	
}

/*打印数组*/
void printArr(int arr[],int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		printf("%4d",arr[i]);
	}

	printf("\n");
}

/*滚动数组*/
void moveArr(int arr[], int arrLen, int offset)
{
	int *p, *arrEnd;
	int last;

	arrEnd = arr + arrLen;//数组最后一个元素的下一个位置


	while (offset)//滚动，直到偏移量为0
	{
		last = *(arrEnd - 1);

		for (p = arrEnd - 1; p != arr; --p)//向右滚动一位
		{
			*p = *(p - 1);
		}

		*arr = last;
		--offset;
	}
}




/*
C 练习实例35
题目： 字符串反转，如将字符串 "www.itsayer.com" 反转为 "moc.boonur.www"。

*/
void prac35()
{
	void reverseStr(char* str);

	char s[] = "www.itsayer.com";
	reverseStr(s);
	printf("反转后的字符串：%s\n",s);
}

void reverseStr(char* str)
{
	int strLen = 0;
	char* p = str;

	while (*p)//获取字符串长度
	{
		strLen++;
		p++;
	}

	//交换
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
C 练习实例32
题目： 删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母。

*/
void prac32()
{
	char* deleteCharacters(char* str, char* charSet);

	char s1[2] = "a";
	char s2[5] = "aca";

	printf("删除指定字母后的字符串：\n");
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
		hash[charSet[i]] = 1;//把指定字符位置为1
	}

	int currentIndex = 0;

	for (int i = 0; i < strlen(str); i++)
	{
		if (!hash[str[i]])//跳过指定字符
		{
			str[currentIndex++] = str[i];
		}

	}

	str[currentIndex] = '\0';

	return str;
}





/*
C 练习实例30 - 回文数
题目： 一个5位数，判断它是不是回文数。即12321是回文数，个位与万位相同，十位与千位相同。

程序分析： 学会分解出每一位数。

*/
void prac30()
{
	long dig, ten, hundred, thousand, tenThousand,num;

	printf("请输入一个五位数：\n");
	scanf("%d",&num);

	tenThousand = num / 10000;
	thousand = num % 10000 / 1000;
	ten = num % 100 / 10;
	dig = num % 10;

	if (dig==tenThousand && ten==thousand)
	{
		printf("这是回文数!\n");
	}
	else
	{
		printf("这不是回文数!\n");
	}
}






/*
练习实例28
题目： 有5个人坐在一起，问第五个人多少岁？他说比第4个人大2岁。问第4个人岁数，他说比第3个人大2岁。问第三个人，又说比第2人大两岁。问第2个人，说比第一个人大两岁。最后问第一个人，他说是10岁。请问第五个人多大？

程序分析： 利用递归的方法，递归分为回推和递推两个阶段。要想知道第五个人岁数，需知道第四人的岁数，依次类推，推到第一人（10岁），再往回推。
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
C 练习实例27
题目： 利用递归函数调用方式，将所输入的5个字符，以相反顺序打印出来。

程序分析： 无。

*/
void prac27()
{
	int i = 5;
	void palin(int n);

	printf("请输入5个字符\40:\40");
	palin(i);
	printf("\n");
}


void palin(int n)
{
	char next;

	if (n<=1)
	{
		next = getchar();
		printf("相反顺序输出结果\40:\40");
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
C 练习实例26
题目： 利用递归方法求5!。

程序分析： 递归公式：fn=fn_1*4!

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
C 练习实例21
题目： 猴子吃桃问题：猴子第一天摘下若干个桃子，当即吃了一半，还不瘾，又多吃了一个 第二天早上又将剩下的桃子吃掉一半，又多吃了一个。以后每天早上都吃了前一天剩下 的一半零一个。到第10天早上想再吃时，见只剩下一个桃子了。求第一天共摘了多少。

程序分析： 采取逆向思维的方法，从后往前推断。

1) 设x1为前一天桃子数，设x2为第二天桃子数， 则：

x2=x1/2-1, x1=(x2+1)*2

x3=x2/2-1, x2=(x3+1)*2

以此类推： x前=(x后+1)*2

2) 从第10天可以类推到第1天，是一个循环过程。

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

	printf("总数为 %d\n",x1);
}





/*
C 练习实例14 - 将一个正整数分解质因数
题目： 将一个正整数分解质因数。例如：输入90,打印出90=233*5。

程序分析： 对n进行分解质因数，应先找到一个最小的质数k，然后按下述步骤完成：

(1)如果这个质数恰等于（小于的时候，继续执行循环）n，则说明分解质因数的过程已经结束，另外 打印出即可。
(2)但n能被k整除，则应打印出k的值，并用n除以k的商,作为新的正整数n.重复执行第二步。
(3)如果n不能被k整除，则用k+1作为k的值,重复执行第一步。
*/
void prac14()
{
	int num;

	printf("请输入一个整数:\n");
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
C 练习实例13 - 水仙花数
题目： 打印出所有的"水仙花数"，所谓"水仙花数"是指一个三位数，其各位数字立方和等于该数 本身。例如：153是一个"水仙花数"，因为153=1的三次方＋5的三次方＋3的三次方。

程序分析： 利用for循环控制100-999个数，每个数分解出个位，十位，百位
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
C 练习实例12
题目： 判断101到200之间的素数。

程序分析： 判断素数的方法：用一个数分别去除2到sqrt(这个数)，如果能被整除， 则表明此数不是素数，反之是素数。
*/
void prac12()
{
	int k,leap=1;
	int count = 0;//计数

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
C 练习实例11
题目： 古典问题（兔子生崽）：有一对兔子，从出生后第3个月起每个月都生一对兔子，小兔子长到第三个月后每个月又生一对兔子，假如兔子都不死，问每个月的兔子总数为多少？（输出前40个月即可）

程序分析： 兔子的规律为数列1,1,2,3,5,8,13,21....，即下个月是上两个月之和（从第三个月开始）。
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
			printf("\n");//控制输出，每行4个
		}

		f1 = f1 + f2;//前两个月加起来赋值给第三个月
		f2 = f1 + f2;
	}
}








/*
C 练习实例9
题目： 要求输出国际象棋棋盘。

程序分析： 国际象棋棋盘由64个黑白相间的格子组成，分为8行*8列。用i控制行，j来控制列，根据i+j的和的变化来控制输出黑方格，还是白方格
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
C 练习实例8
题目： 输出9*9口诀。

程序分析： 分行与列考虑，共 9 行 9 列，i 控制行，j 控制列。
*/
void prac08()
{
	int row;//行
	int column;//列
	int result;

	for ( row = 1; row < 10; row++)
	{
		for (column = 1; column <= row; column++)
		{
			result = row*column;
			printf("%d*%d=%-3d",row,column,result);
		}

		printf("\n");//每打印一行后换行
	}
}



/*
C 练习实例4
题目： 输入某年某月某日，判断这一天是这一年的第几天？

程序分析： 以3月5日为例，应该先把前两个月的加起来，然后再加上5天即本年的第几天，特殊情况，闰年且输入月份大于3时需考虑多加一天
*/
void prac04()
{
	int day, month, year, sum, leap;

	printf("请输入年月日，格式：年.月.日（2015.10.10）\n");
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

	sum += day;//再加上某天的天数

	if (year%400==0 || (year%4==0 && year%100!=0))//判断闰年
	{
		leap = 1;
	}
	else
	{
		leap = 0;
	}

	if (leap==1 && month>2)
	{
		sum++;//如果是闰年且月份大于2，总天数应该加一天
	}

	printf("这是%d年中的第%d天\n",year,sum);
}




/*
C 练习实例3
题目： 一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？

程序分析：

假设该数为 x。

1、则：x + 100 = n2, x + 100 + 168 = m2

2、计算等式：m2 - n2 = (m + n)(m - n) = 168

3、设置： m + n = i，m - n = j，i * j =168，i 和 j 至少一个是偶数

4、可得： m = (i + j) / 2， n = (i - j) / 2，i 和 j 要么都是偶数，要么都是奇数。

5、从 3 和 4 推导可知道，i 与 j 均是大于等于 2 的偶数。

6、由于 i * j = 168， j>=2，则 1 < i < 168 / 2 + 1。

7、接下来将 i 的所有数字循环计算即可。

*/
void prac03()
{
	long int x, y;

	for (long int i = 0; i < 100000; i++)
	{
		x = sqrt(i+100);//为该数加上100后开方后的结果
		y = sqrt(i+100+168);//为该数加上100,再加上168后开方后的结果

		if (x*x==i+100 && y*y==i+268)//如果一个数的平方根的平方等于该数，说明是完全平方数
		{
			printf("\n%ld",i);
		}
	}

}




/*
C 练习实例2
题目：企业发放的奖金根据利润提成。

利润(I)低于或等于10万元时，奖金可提10%；
利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
20万到40万之间时，高于20万元的部分，可提成5%；
40万到60万之间时高于40万元的部分，可提成3%；
60万到100万之间时，高于60万元的部分，可提成1.5%；
高于100万元时，超过100万元的部分按1%提成。
从键盘输入当月利润I，求应发放奖金总数？

程序分析：请利用数轴来分界，定位。注意定义时需把奖金定义成长整型。


*/
void prac02()
{
	double I;	//当月利润，键盘输入
	double bonus1, bonus2, bonus4, bonus6, bonus10, finalBonus;

	printf("请输入当月净利润I：\n");
	scanf("%lf",&I);

	bonus1 = 100000 * 0.1;	            
	bonus2 = bonus1 + 100000 * 0.075;   
	bonus4 = bonus2 + 200000 * 0.05;    
	bonus6 = bonus4 + 200000 * 0.03;   
	bonus10 = bonus6 + 400000 * 0.015;	

	if (I<=100000)
	{
		finalBonus = I*0.1;//低于或等于10万元时，奖金可提10%
	}
	else if (I<=200000)
	{
		finalBonus = bonus1+ (I-100000)*0.075;//利润高于10万元，低于20万元时，低于10万元的部分按10%提成，高于10万元的部分，可提成7.5%；
	}
	else if (I<=400000)
	{
		finalBonus = bonus2 + (I - 200000)*0.05;//20万到40万之间时，高于20万元的部分，可提成5%
	}
	else if (I <= 600000)
	{
		finalBonus = bonus4 + (I - 400000)*0.03;//40万到60万之间时高于40万元的部分，可提成3%
	}
	else if (I <= 1000000)
	{
		finalBonus = bonus6 + (I - 600000)*0.015;//60万到100万之间时，高于60万元的部分，可提成1.5%
	}
	else if (I > 1000000)
	{
		finalBonus = bonus10 + (I - 1000000)*0.01;//高于100万元时，超过100万元的部分按1%提成
	}

	printf("提成为：%lf\n",finalBonus);

}




/*
题目：有1、2、3、4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？

程序分析：可填在百位、十位、个位的数字都是1、2、3、4。组成所有的排列后再去掉不满足条件的排列。
*/
void prac01()
{
	int digits, ten, hundre;	//个十百位

	for (digits = 1; digits < 5; digits++)//三重for循环
	{
		for (ten = 1; ten < 5; ten++)
		{
			for (hundre = 1; hundre < 5; hundre++)
			{
				if (digits!=ten && digits!=hundre && ten!=hundre)//确保个十百位互不相同
				{
					printf("%d%d%d\n",hundre,ten,digits);
				}
			}
		}
	}
}
