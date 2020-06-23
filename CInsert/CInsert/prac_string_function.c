#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include"prac_string_function.h"


/*字符串函数 测试函数*/
void pracStringFunctionTest()
{
	//declarString();
	//putcharTest();
	//strlenTest();
	//strcpyTest();
	//strcmpTest();
	//strchrTest();
}

void declarString()
{
	// 实际上都是字符数组，可修改，空间自动回收，构造字符串
	char str[6] = { 'a', 'b', 'c', '\0' };			// 要带杠铃
	char str1[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	char str2[] = { "abcde" };						// 直接写字符串常量
	char str3[] = "abcde";							// 字符串常量大括号可以不要

	// 指针形式，字符串常量不可修改，动态分配空间，作为参数时，处理字符串
	// char* 可以表示字符串，但不一定是字符串
	char *str4 = "abcde";		// 
	char *str5 = "abcde";

	printf("addr of str2: %p\n", str2);
	printf("addr of str3: %p\n", str3);				// str3 和 str4 不同
	printf("addr of str4: %p\n", str4);				// str4 和 str5 是一样的
	printf("addr of str5: %p\n", str5);
}


/*putchar、getchar*/
void putcharTest()
{
	int ch;

	while ((ch = getchar()) != EOF)
	{
		putchar(ch);
	}
}

void strlenTest()
{
	char str[] = "I love you";

	printf("sizeof(str): %d\n", sizeof(str));	//11：尺寸大小，包含末尾的杠铃
	printf("strlen(str): %u\n", strlen(str));	//10:字符个数，不包含杠铃
}


void strcpyTest()
{
	char str[] = "I love you";
	char str1[] = "newString";
	char str2[100];

	strcpy_s(str, 10, str1);
	strcpy_s(str2, 20, "Copy successful");

	printf("str: %s\n", str);
	printf("str1: %s\n", str1);
	printf("str2: %s\n", str2);
}


void strcmpTest()
{
	char str1[10] = "FishC.com";
	char str2[20] = "FishC.com";

	if (!strcmp(str1, str2))
	{
		printf("两个字符串完全一致！\n");
	}
	else
	{
		printf("两个字符串不同！\n");
	}
}

void strchrTest()
{
	char s[] = "hello";
	char* p = strchr(s, 'l');
	p = strchr(p + 1, 'l');	//

	printf("%s\n", p);
}