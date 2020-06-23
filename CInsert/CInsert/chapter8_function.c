#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter8_function.h"


/*chapter8 函数 测试函数*/
void chapter8FunctionTest()
{
	//funConvertArrayTest();
	//funInverseStringTest();
	//funConcatStringTest();
	//funCopyVowelTest();
	//funPrintDigitsTest();
	//longestWordStartPositionTest();
	//funConvertNumTest();
	//funCountingDays();
	
}



/******************************************************************************************************************
给出年月日，计算该日是该年的第几天
*/

/*计算第几天*/
int sumDay(int month, int day)
{
	int dayTab[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	for (int i = 0; i < month; i++)
	{
		day += dayTab[i];
	}

	return day;
}

/*判断是否为闰年*/
int isLeap(int year)
{
	int leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	return leap;
}

/*计算该日是该年的第几天*/
void funCountingDays()
{
	int year, month, day, dayCount;

	printf("input date(year,month,day)\n");
	scanf("%d,%d,%d",&year,&month,&day);
	

	dayCount = sumDay(month,day);
	if (isLeap(year))
	{
		dayCount += 1;
	}

	printf("%d-%d-%d", year, month, day);
	printf(" is the %dth day in this year\n",dayCount);
}




/******************************************************************************************************************
用递归法将一个整数n转换成字符串
*/

/*
funConvertNum()只处理正数
说明：
假如num的值是345，n/10的值为34！=0，再调用funConvertNum函数
此时形参num的值为34，再执行函数体，num/10的值为3！=0，再调用funConvertNum函数
此时形参num的值为3，再执行函数体，num/10的值为3==0，不再调用funConvertNum函数，而执行putchar
此时n的值为3，n%10的值是3，字符'0'的ASCII码值为48，48+3=51，51是字符‘3’的ASCII码
因此putchar(num%10+'0');输出字符'3',接着输出一个空格

然后：流程返回到上一次调用funConvertNum函数处，应该接着执行putchar(num%10+'0')
此时的num是上一次调用funConvertNum函数时的num值为34
因此，num%10的值为4，4+‘0’=52，为字符'4'的ASCII码

然后：流程又返回上一次调用funConvertNum函数处，应该接着执行putchar(num%10+'0')
此时的num是 第一次 调用funConvertNum函数时的num值为345
因此，num%10的值为5，5+‘0’=52，为字符'5'的ASCII码

至此：funConvertNum函数递归调用结束，返回主函数 
*/
void funConvertNum(int num)
{
	int i;

	if ((i=num/10)!=0)
	{
		funConvertNum(i);
	}

	putchar(num%10+'0');	// 字符'0'的ASCII码值为48
	putchar(32);	        //输出一个空格
}

/* funConvertNum 测试函数 */
void funConvertNumTest()
{
	int num;

	printf("请输入一个整数：\n");
	scanf("%d",&num);
	printf("转换输出：\n");

	if (num<0)//如果输入的是负数，先输出一个负号和空格
	{
		putchar('-');
		putchar(' ');
		num = -num;//使输入的负数变为正数
	}

	funConvertNum(num);
	printf("\n");
}


/******************************************************************************************************************
输入一个字符串，将此字符串中最长的单词输出 
longestWordStartPosition():找出最长单词的位置，返回值是该行字符中最长单词的起始位置
isAlphabtic():判断当前字符是否为字母
*/

/*判断当前字符是否为字母*/
int isAlphabtic(char c)
{
	if ((c>='a' && c<='z') || (c>='A' && c<='Z'))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*找出最长单词的位置，返回值是该行字符中最长单词的起始位置*/
int longestWordStartPosition(char string[])
{
	int alphaCount = 0;	//当前单词已累计的字母个数
	int length = 0;	    //先前单词中最长单词的长度
	int flag = 1;	    //表示单词是否已经开始，1表示开始
	int longestWSP = 0;	//最长单词的起始位置
	int currentWSP;	    //当前单词的起始位置

	for (int i = 0; i <= strlen(string); i++)
	{
		if (isAlphabtic(string[i]))
		{
			if (flag)
			{
				currentWSP = i;
				flag = 0;
			}
			else
			{
				alphaCount++;
			}
		}
		else
		{
			flag = 1;

			if (alphaCount>=length)
			{
				length = alphaCount;
				longestWSP = currentWSP;
				alphaCount = 0;
			}
		}

	}

	return longestWSP;
}

/*longestWordStartPosition 测试函数*/
void longestWordStartPositionTest()
{
	char lineString[100];

	printf("请输入1行字符串：\n");
	gets(lineString);

	printf("最长的单词是：\n");
	for (int i = longestWordStartPosition(lineString); isAlphabtic(lineString[i]); i++)
	{
		printf("%c",lineString[i]);
	}

	printf("\n");
}




/******************************************************************************************************************
输入一个4位数字，要去输出这4个数字字符，但两个数字之间空一个空格
如：输入1990，输出1 9 9 0
*/
void funPrintDigits(char digitsStr[])
{
	for (int i = strlen(digitsStr); i > 0; i--)
	{
		digitsStr[2*i] = digitsStr[i];
		digitsStr[2 * i-1] = ' ';
	}

	printf("output:%s\n",digitsStr);
}

/*funPrintDigits 测试函数*/
void funPrintDigitsTest()
{
	char digitsStr[80];

	printf("请输入一个4位数字：\n");
	gets(digitsStr);

	funPrintDigits(digitsStr);
}




/******************************************************************************************************************
将一个字符串中的元音字母复制到另一个字符串中然后输出该字符串
*/
void funCopyVowel(char srcStr[],char destStr[])
{
	int i, j;

	for ( i = 0,j=0;srcStr[i]!='\0'; i++)
	{
		if (
			srcStr[i] == 'a' || srcStr[i] == 'A' ||
			srcStr[i] == 'e' || srcStr[i] == 'E' || 
			srcStr[i] == 'i' || srcStr[i] == 'I' || 
			srcStr[i] == 'o' || srcStr[i] == 'O' || 
			srcStr[i] == 'u' || srcStr[i] == 'U'
			)
		{
			destStr[j] = srcStr[j];
			j++;
		}
	}

	destStr[j] = '\0';
}

/*funCopyVowel 测试函数*/
void funCopyVowelTest()
{
	char srcStr[80], destStr[80];

	printf("请输入一个字符串：\n");
	gets(srcStr);

	funCopyVowel(srcStr,destStr);

	printf("The vowel letters are:%s\n",destStr);
}




/******************************************************************************************************************
字符串拼接
*/
void funConcatString(char string1[],char string2[],char string[])
{
	int i, j;

	for ( i = 0; string1[i]!='\0'; i++)
	{
		string[i] = string1[i];
	}

	for ( j= 0; string2[j] != '\0'; j++)
	{
		string[i+j] = string2[j];
	}

	string[i+j] = '\0';
}

/*字符串拼接测试函数*/
void funConcatStringTest()
{
	char string[100], string1[50], string2[50];

	printf("input string1:\n");
	gets(string1);
	printf("input string2:\n");
	gets(string2);

	funConcatString(string1,string2,string);

	printf("The new string is: %s\n",string);

}




/******************************************************************************************************************
字符串反序存放
*/
void funInverseString(char string[])
{
	char str;
	
	for (int i = 0,j=strlen(string); i < (strlen(string)/2); i++,j--)
	{
		str = string[i];
		string[i] = string[j-1];
		string[j - 1] = str;
	}
}

/*funInverseString 测试函数*/
void funInverseStringTest()
{
	char string[128];

	printf("请输入一个字符串：\n");
	gets(string);

	funInverseString(string);

	printf("inverse string:\n%s\n",string);


}




/******************************************************************************************************************
使给定的一个3*3的二维整型数组转置，即行列互换
*/
void funConvertArray(int array[][3])
{
	int temp;

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = i+1; j < ARRAYLENGTH; j++)
		{
			temp = array[i][j];
			array[i][j] = array[j][i];
			array[j][i] = temp;
		}
	}
}
/*convertArray 测试函数*/
void funConvertArrayTest()
{
	int array[ARRAYLENGTH][ARRAYLENGTH];
	printf("请输入一个3*3的数组：\n");
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = 0; j < ARRAYLENGTH; j++)
		{
			scanf("%d",&array[i][j]);
		}
	}

	printf("\noriginal array:\n");
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = 0; j < ARRAYLENGTH; j++)
		{
			printf("%5d", array[i][j]);
		}

		printf("\n");
	}

	funConvertArray(array);

	printf("\ncovert array:\n");
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = 0; j < ARRAYLENGTH; j++)
		{
			printf("%5d", array[i][j]);
		}

		printf("\n");
	}
}



