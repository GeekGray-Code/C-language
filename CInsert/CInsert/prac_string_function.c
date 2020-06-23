#include <stdio.h>
#include<stdlib.h>
#include<string.h>

#include"prac_string_function.h"


/*�ַ������� ���Ժ���*/
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
	// ʵ���϶����ַ����飬���޸ģ��ռ��Զ����գ������ַ���
	char str[6] = { 'a', 'b', 'c', '\0' };			// Ҫ������
	char str1[] = { 'a', 'b', 'c', 'd', 'e', '\0' };
	char str2[] = { "abcde" };						// ֱ��д�ַ�������
	char str3[] = "abcde";							// �ַ������������ſ��Բ�Ҫ

	// ָ����ʽ���ַ������������޸ģ���̬����ռ䣬��Ϊ����ʱ�������ַ���
	// char* ���Ա�ʾ�ַ���������һ�����ַ���
	char *str4 = "abcde";		// 
	char *str5 = "abcde";

	printf("addr of str2: %p\n", str2);
	printf("addr of str3: %p\n", str3);				// str3 �� str4 ��ͬ
	printf("addr of str4: %p\n", str4);				// str4 �� str5 ��һ����
	printf("addr of str5: %p\n", str5);
}


/*putchar��getchar*/
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

	printf("sizeof(str): %d\n", sizeof(str));	//11���ߴ��С������ĩβ�ĸ���
	printf("strlen(str): %u\n", strlen(str));	//10:�ַ�����������������
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
		printf("�����ַ�����ȫһ�£�\n");
	}
	else
	{
		printf("�����ַ�����ͬ��\n");
	}
}

void strchrTest()
{
	char s[] = "hello";
	char* p = strchr(s, 'l');
	p = strchr(p + 1, 'l');	//

	printf("%s\n", p);
}