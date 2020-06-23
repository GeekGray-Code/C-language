#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter8_function.h"


/*chapter8 ���� ���Ժ���*/
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
���������գ���������Ǹ���ĵڼ���
*/

/*����ڼ���*/
int sumDay(int month, int day)
{
	int dayTab[] = {0,31,28,31,30,31,30,31,31,30,31,30,31};

	for (int i = 0; i < month; i++)
	{
		day += dayTab[i];
	}

	return day;
}

/*�ж��Ƿ�Ϊ����*/
int isLeap(int year)
{
	int leap;

	leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;

	return leap;
}

/*��������Ǹ���ĵڼ���*/
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
�õݹ鷨��һ������nת�����ַ���
*/

/*
funConvertNum()ֻ��������
˵����
����num��ֵ��345��n/10��ֵΪ34��=0���ٵ���funConvertNum����
��ʱ�β�num��ֵΪ34����ִ�к����壬num/10��ֵΪ3��=0���ٵ���funConvertNum����
��ʱ�β�num��ֵΪ3����ִ�к����壬num/10��ֵΪ3==0�����ٵ���funConvertNum��������ִ��putchar
��ʱn��ֵΪ3��n%10��ֵ��3���ַ�'0'��ASCII��ֵΪ48��48+3=51��51���ַ���3����ASCII��
���putchar(num%10+'0');����ַ�'3',�������һ���ո�

Ȼ�����̷��ص���һ�ε���funConvertNum��������Ӧ�ý���ִ��putchar(num%10+'0')
��ʱ��num����һ�ε���funConvertNum����ʱ��numֵΪ34
��ˣ�num%10��ֵΪ4��4+��0��=52��Ϊ�ַ�'4'��ASCII��

Ȼ�������ַ�����һ�ε���funConvertNum��������Ӧ�ý���ִ��putchar(num%10+'0')
��ʱ��num�� ��һ�� ����funConvertNum����ʱ��numֵΪ345
��ˣ�num%10��ֵΪ5��5+��0��=52��Ϊ�ַ�'5'��ASCII��

���ˣ�funConvertNum�����ݹ���ý��������������� 
*/
void funConvertNum(int num)
{
	int i;

	if ((i=num/10)!=0)
	{
		funConvertNum(i);
	}

	putchar(num%10+'0');	// �ַ�'0'��ASCII��ֵΪ48
	putchar(32);	        //���һ���ո�
}

/* funConvertNum ���Ժ��� */
void funConvertNumTest()
{
	int num;

	printf("������һ��������\n");
	scanf("%d",&num);
	printf("ת�������\n");

	if (num<0)//���������Ǹ����������һ�����źͿո�
	{
		putchar('-');
		putchar(' ');
		num = -num;//ʹ����ĸ�����Ϊ����
	}

	funConvertNum(num);
	printf("\n");
}


/******************************************************************************************************************
����һ���ַ����������ַ�������ĵ������ 
longestWordStartPosition():�ҳ�����ʵ�λ�ã�����ֵ�Ǹ����ַ�������ʵ���ʼλ��
isAlphabtic():�жϵ�ǰ�ַ��Ƿ�Ϊ��ĸ
*/

/*�жϵ�ǰ�ַ��Ƿ�Ϊ��ĸ*/
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

/*�ҳ�����ʵ�λ�ã�����ֵ�Ǹ����ַ�������ʵ���ʼλ��*/
int longestWordStartPosition(char string[])
{
	int alphaCount = 0;	//��ǰ�������ۼƵ���ĸ����
	int length = 0;	    //��ǰ����������ʵĳ���
	int flag = 1;	    //��ʾ�����Ƿ��Ѿ���ʼ��1��ʾ��ʼ
	int longestWSP = 0;	//����ʵ���ʼλ��
	int currentWSP;	    //��ǰ���ʵ���ʼλ��

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

/*longestWordStartPosition ���Ժ���*/
void longestWordStartPositionTest()
{
	char lineString[100];

	printf("������1���ַ�����\n");
	gets(lineString);

	printf("��ĵ����ǣ�\n");
	for (int i = longestWordStartPosition(lineString); isAlphabtic(lineString[i]); i++)
	{
		printf("%c",lineString[i]);
	}

	printf("\n");
}




/******************************************************************************************************************
����һ��4λ���֣�Ҫȥ�����4�������ַ�������������֮���һ���ո�
�磺����1990�����1 9 9 0
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

/*funPrintDigits ���Ժ���*/
void funPrintDigitsTest()
{
	char digitsStr[80];

	printf("������һ��4λ���֣�\n");
	gets(digitsStr);

	funPrintDigits(digitsStr);
}




/******************************************************************************************************************
��һ���ַ����е�Ԫ����ĸ���Ƶ���һ���ַ�����Ȼ��������ַ���
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

/*funCopyVowel ���Ժ���*/
void funCopyVowelTest()
{
	char srcStr[80], destStr[80];

	printf("������һ���ַ�����\n");
	gets(srcStr);

	funCopyVowel(srcStr,destStr);

	printf("The vowel letters are:%s\n",destStr);
}




/******************************************************************************************************************
�ַ���ƴ��
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

/*�ַ���ƴ�Ӳ��Ժ���*/
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
�ַ���������
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

/*funInverseString ���Ժ���*/
void funInverseStringTest()
{
	char string[128];

	printf("������һ���ַ�����\n");
	gets(string);

	funInverseString(string);

	printf("inverse string:\n%s\n",string);


}




/******************************************************************************************************************
ʹ������һ��3*3�Ķ�ά��������ת�ã������л���
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
/*convertArray ���Ժ���*/
void funConvertArrayTest()
{
	int array[ARRAYLENGTH][ARRAYLENGTH];
	printf("������һ��3*3�����飺\n");
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



