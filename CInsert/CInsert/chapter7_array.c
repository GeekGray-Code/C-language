#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter7_array.h"


/*chapter7 数组 测试函数*/
void chapter7ArrayTest()
{
	//calcFibonacciByArray();
	//calcVocabularyCount();
	//calcLargestString();
	//calcPrimeNumByEratonsthenes();
	//calcArrayInversion();
	//calcYangHuiTriangle();
	//calcSaddlePoint();
	//calcCharacters();
	//calcStrcmp();
	//calcStrcpy();

}



/*
将字符数组s2中的全部字符赋值到字符数组s1中
复制时，'\0'也要复制过去，'\0'后面的字符不用复制
*/
void calcStrcpy()
{
	char s1[80], s2[80];

	printf("请输入字符串s2:\n");
	//scanf("%s",s2);
	gets(s2);

	for (int i = 0; i <= strlen(s2); i++)
	{
		s1[i] = s2[i];
	}

	printf("s1:%s\n",s1);
}





/*
将两个字符串s1和s2比较，若s1>s2，输出一个正数，若s1=s2，输出0，若s1<s2，输出一个负数
输出字符的ASCII的差值
例如：‘A’<'C'的ASCII码相差2，所以"A"<"C" 应输出-2
*/
void calcStrcmp()
{
	int result,index=0;
	char s1[100], s2[100];

	printf("请输入 string1：\n");
	gets(s1);

	printf("请输入 string2：\n");
	gets(s2);

	while ((s1[index]==s2[index]) && (s1[index]!='\0'))
	{
		index++;
	}

	if (s1[index]=='\0' && s2[index]=='\0')
	{
		result = 0;
	}
	else
	{
		result = s1[index] - s2[index];
	}

	printf("\nresult:%d\n",result);
}


/*
有一篇文章，共有3行文字，每行有80个字符，
要求分别统计出其中英文大写字符，小写字母，数字，空格以及其他字符的个数
*/
void calcCharacters()
{
	int upp, low, dig, space, other;
	char text[3][80];

	upp = low = dig = space = other = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("请输入第%d行文字:\n",i+1);
		gets(text[i]);

		for (int j = 0; j < 80 && text[i][j]!='\0'; j++)
		{
			if (text[i][j]>='A' && text[i][j]<='Z')
			{
				upp++;
			}
			else if (text[i][j] >= 'a' && text[i][j] <= 'z')
			{
				low++;
			}
			else if (text[i][j] >= '0' && text[i][j] <= '9')
			{
				dig++;
			}
			else if (text[i][j] ==' ')
			{
				space++;
			}
			else
			{
				other++;
			}
		}
	}

	printf("upp:%d\n",upp);
	printf("low:%d\n", low);
	printf("dig:%d\n", dig);
	printf("space:%d\n", space);
	printf("other:%d\n", other);
}


/*
找出一个二维数组的鞍点，即该位置上的元素在该行上最大，在该列上最小，也可能没有鞍点
解题思路：一个二维数组最多有一个鞍点，也可能没有
		先找出一行中值最大的元素，然后检查它是否为该列中的最小值，如果是，则是鞍点（不需要再找其他鞍点了）
		如果不是，则再找下一行的最大值....如果每一行的最大值都不是鞍点，则该数组没有鞍点
*/
void calcSaddlePoint()
{
	int arr[ROW][COLUMN];
	int max, maxColumn,flag;

	printf("请输入二维数组：\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	int count=0;
	printf("二维数组：\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			count++;
			printf("%d\t", arr[i][j]);

			if (count%5==0)
			{
				printf("\n");
			}
		}
	}



	for (int i = 0; i < ROW; i++)
	{
		max = arr[i][0];							    //开始假设arr[i][0]最大
		maxColumn = 0;										//将列号0赋给maxj保存
		                                                
		for (int j = 0; j < COLUMN; j++)			    //找出第i行中的最大数
		{
			if (arr[i][j]>max)
			{
				max = arr[i][j];						//将本行中的最大数存放在max中
				maxColumn = j;								//将最大数所在的列号存放在maxj中
			}
		}

		flag = 1;										//先假设是鞍点，以flag为1标志

		for (int k = 0; k < ROW; k++)
		{
			if (max>arr[k][maxColumn])						//将最大数和其同列元素相比
			{
				flag = 0;								//如果max不是同列最小，表示不是鞍点，令flag 从1变为0
				continue;
			}
		}

		if (flag)										//如果flag为1，表示是鞍点
		{
			printf("鞍点：arr[%d][%d]=%d\n",i,maxColumn,max);//输出鞍点值的所在行列号
			break;
		}
	}

	if (!flag)											//如果flag为0表示鞍点不存在
	{
		printf("鞍点不存在！\n");
	}
}



/*
输出杨辉三角
杨辉三角形是(a+b)^n 展开后各项的系数
例如：
(a+b)^0 展开后为1，系数为1
(a+b)^1 展开后为a+b，系数为1，1
(a+b)^2 展开后为a^2+2*a*b+b^2，系数为1，2，1
(a+b)^3 展开后为a^3+3*a^2*b+b^3，系数为1，3，3，1
(a+b)^4 展开后为a^4+4*a^3*b+6*a^2*b^2+4*a*b^3+b^4，系数为1，4，6，4，1
规律：
	(1)各行第一个数是1
	(2)各行最后一个数是1
	(3)从第3行起，除上面指出的第一个数和最后一个数外，其余各数是上一行同列和前一列两数之和
	   例如：第4行第2个数是第3行第2个数和第3行第1个数之和
	   可以这样表示：arr[i][j]=arr[i-1][j]+arr[i-1][j-1];i为行数，j为列数
*/
void calcYangHuiTriangle()
{
	int arr[ARRAYLENGTH][ARRAYLENGTH];

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		arr[i][i] = 1;										//使对角线元素的值为1
		arr[i][0] = 1;										//使第1列元素的值为1
	}

	for (int i = 2; i < ARRAYLENGTH; i++)					//从第3行开始处理
	{
		for (int j = 1; j <= i-1; j++)
		{
			//arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j];
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1]; //i为行数，j为列数
		}
	}

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%6d",arr[i][j]);						//输出数组各元素的值
		}

		printf("\n");
	}

	printf("\n");
}


/*
将一个数组中的值按逆序重新存放
例如：原来顺序为8，6，5，4，1
要求改为：1，4，5，6，8
解题思路：以中间元素为中心，将其两侧对称的元素的值互换
*/
void calcArrayInversion()
{
	int arr[ARRAYLENGTH] = {1,2,3,4,5};
	int temp;

	printf("原数组：\n");
	for (int i = 0; i < ARRAYLENGTH; i++)//显示初始数组元素
	{
		printf("%4d", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < ARRAYLENGTH/2; i++)//将对称的元素的值互换，第 i 个元素与第 ARRAYLENGTH - i - 1 个元素互换
	{
		temp = arr[i];
		arr[i] = arr[ARRAYLENGTH - i - 1];
		arr[ARRAYLENGTH - i - 1] = temp;
	}

	printf("倒置元素后的数组：\n");
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		printf("%4d",arr[i]);
	}

	printf("\n");
}






/*用数组来处理fibonacci数列*/
void calcFibonacciByArray()
{
	int index;										    //数组下标索引
	int fib[20] = {1,1};								//初始化一个Fib数组，只赋前2项的值

	for ( index = 2; index < 20; index++)
	{
		fib[index] = fib[index - 2] + fib[index - 1];	//从第3项开始，当前项=前2项之和
	}

	for ( index = 0; index < 20; index++)
	{
		if (index%5==0)
		{
			printf("\n");								//控制输出，5个数据一行
		}

		printf("%12d ",fib[index]);
	}
}






/*输入一行字符，统计其中都有多少个单词，单词之间要用空格隔开*/
void calcVocabularyCount()
{
	char string[81];			//用来表示字符串
	int i;
	int count = 0;		        //单词数量
	int vocaFlag = 0;			//标志位
	char c;

	printf("请输入一行字符，单词之间要用空格隔开\n");
	gets(string);

	for ( i = 0; (c=string[i])!='\0'; i++)
	{
		if (c==' ')				//当前字符为空格，则未出现新单词，使标志vocaFlag为0，count不累加
		{
			vocaFlag = 0;
		}
		else if (vocaFlag == 0)	//前一字符为空格（vocaFlag = 0），新单词出现，使count+1，使vocaFlag = 1
		{
			vocaFlag = 1;
			count++;
		}
	}

	printf("There are %d words in the line.\n",count);
}



/*有3个字符串，要求找出其中最大者*/
void calcLargestString()
{
	char largestStr[20];				//一维数组，存放最大的字符串
	char string[3][20];					//二维数组，存放3个字符串
	int i;

	printf("请输入3个字符串\n");
	for ( i = 0; i < 3; i++)
	{
										//其原型是： char *gets(char *string);
		gets(string[i]);				//gets() 函数的功能是从缓冲区中读取字符串并存储到字符指针变量 str 所指向的内存空间。  
	}

	if (strcmp(string[0],string[1])>0)	/*strcmp 函数用于比较两个字符串。该函数从第一个字符开始，
									    依次比较每个字符的 ASCII 码大小，直到发现两个字符不相等或抵达结束符（'\0'）为止。*/
	{
		strcpy(largestStr,string[0]);	//strcpy 函数用于拷贝字符串，包含最后的结束符 '\0'。
	}
	else
	{
		strcpy(largestStr, string[1]);
	}

	if (strcmp(string[2], largestStr)>0)
	{
		strcpy(largestStr, string[2]);
	}

	printf("\nThe largest string is: %s\n",largestStr);
}


/*用筛选法求100之内的素数
  筛选法：埃拉托色尼（Eratonsthenes）筛法
  步骤：在一张纸上写下1000以内的全部整数，挖掉非素数，最后剩下的就是素数
*/
void calcPrimeNumByEratonsthenes()
{
	int i, j;
	int n;							//输出数据的个数
	int arr[101];					//包含101个元素

	for ( i = 1; i <= 100; i++)		//arr[0]不用，只用arr[1]~arr[100]
	{
		arr[i] = i;					//使arr[1]~arr[100]的值为1~100
	}

	arr[1] = 0;						//先挖掉arr[1]

	for ( i = 2; i < sqrt(100); i++)
	{
		for ( j = i+1; j <= 100; j++)
		{
			if (arr[i]!=0 && arr[j]!=0)
			{
				if (arr[j] % arr[i] == 0)
				{
					arr[j] = 0;		//把非素数挖掉
				}
				
			}
		}
	}

	printf("\n");

	for ( i = 2,n=0; i <= 100; i++)
	{
		if (arr[i] != 0)			//选出值不为0的数组元素，即素数
		{
			printf("%5d",arr[i]);	//输出素数，宽度为5列
			n++;					//累计本行已经输出的数据个数
		}
		if (n==10)
		{
			printf("\n");
			n = 0;
		}
	}

	printf("\n");
}


