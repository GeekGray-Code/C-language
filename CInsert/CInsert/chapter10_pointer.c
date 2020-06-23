#include<string.h>
#include<stdarg.h>
#include <stdio.h>

#include "chapter10_pointer.h"


/*chapter10 ָ�� ���Ժ���*/
void chapter10PointerTest()
{
	/*����ʾ��*/
	//pointerTest();
	//pointerAndArray();
	//pointerOperation();
	//myStrlen("GeekGray");
	//printf("%d\n",myStrcmp("GeekGray", "GeekGrby"));
	//pointerArray();
	//arrayPointer();
	//pointerAndTwoDimensionalArray();
	//arrayPointerAndTwoDimensionalArray();
	//pointerToPointer();
	//constantsAndPointers();
	//parametersAndPointers();
	//printf("result = %d\n", sum(3,1,2,3));
	//pointerFunction();
	//functionPointer();
	//functionPointerAsParameter();
	//functionPointerAsReturnValue();

	/*�κ�ϰ��*/
	//pointerCompareNum();
	//pointerStrcmp();
	//sortStrTest();
	//sortNumTest();
}

/****************************************�κ�ϰ��************************************************************************/

/************************************************************************************************************/

/*
��n����������ʱ˳����������У��ú���ʵ��
*/

void sortNum(char* pNum, int numCnt)
{
	char temp;
	char* p1, *p2;

	for (int i = 0; i < numCnt/2; i++)
	{
		p1 = pNum + i;
		p2 = pNum + (numCnt - 1 - i);
		temp = *p1;
		*p1 = *p2;
		*p2 = temp;
	}
}

/*��n����������ʱ˳����������У��ú���ʵ��*/
void sortNumTest()
{
	int numCnt;//����
	char* pNum;
	char numArr[20];

	

	printf("�����������");
	scanf("%d",&numCnt);

	printf("��������%d����,�س����:\n",numCnt);
	for (int i = 0; i < numCnt; i++)
	{
		scanf("%d",&numArr[i]);
	}

	pNum = numArr;
	sortNum(pNum,numCnt);

	printf("���������%d����:\n", numCnt);
	for (int i = 0; i < numCnt; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");
}

/************************************************************************************************************/



/************************************************************************************************************/
/*
��������������10���ȳ����ַ���������һ��������������Ȼ�����
*/

/*�ַ�������*/
void sortStr(char str[10][6])
{
	char* p;
	char tempStr[10];

	p = tempStr;

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9-i; j++)
		{
			if (strcmp(str[j],str[j+1])>0)
			{
				/*��str[j]ָ���һά�����������str[j+1]ָ���ָ���һά��������ݻ���*/
				strcpy(p,str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], p);
			}

		}

	}
}

/*����10���ȳ����ַ���������һ��������������Ȼ�����*/
void sortStrTest()
{
	char str[10][6];

	printf("������10���ȳ����ַ���,�ַ�������Ϊ5��\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%s",str[i]);
	}

	sortStr(str);

	printf("�������ַ�����\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", str[i]);
	}
}
/************************************************************************************************************/


/************************************************************************************************************/
/*�����ַ���*/
void swapString(char *str1, char* str2)
{
	char str[20];

	strcpy(str,str1);
	strcpy(str1,str2);
	strcpy(str2, str);
}

/*����3���ַ���������С�����˳�����*/
void pointerStrcmp()
{
	char str1[31], str2[31], str3[31];

	printf("input three line:\n");

	gets(str1);
	gets(str2);
	gets(str3);

	if (strcmp(str1,str2)>0)
	{
		swapString(str1, str2);
	}
	if (strcmp(str1, str3)>0)
	{
		swapString(str1, str3);
	}
	if (strcmp(str2, str3)>0)
	{
		swapString(str2, str3);
	}

	printf("\nNow the order is:\n");
	printf("%s\n%s\n%s\n",str1,str2,str3);
}


/************************************************************************************************************/
/*����2��*/
void swapInt(int *p1, int *p2)
{
	int p;

	p = *p1;
	*p1 = *p2;
	*p2 = p;
}

/*����3������������С�����˳�����*/
void pointerCompareNum()
{
	int num1, num2, num3;
	int *p1, *p2, *p3;

	printf("input three integer num1,num2,num3\n");
	scanf("%d,%d,%d",&num1,&num2,&num3);

	p1 = &num1;
	p2 = &num2;
	p3 = &num3;

	if (num1>num2)
	{
		swapInt(p1,p2);
	}
	if (num1>num3)
	{
		swapInt(p1, p3);
	}
	if (num2>num3)
	{
		swapInt(p2, p3);
	}

	printf("Now the order is: %d,%d,%d\n",num1,num2,num3);
}




/****************************************����ʾ��***********************************************************************/
/*����ָ�������ȡ��ַ�������ȡֵ�����*/
void pointerTest()
{
	int a = 1;
	char b = 2;

	int * p = &a;
	char * c = &b;

	printf("a=%d,c=%c\n",*p,*c);				//*p ȡֵ����
	printf("a�ĵ�ַ��%p\n,b�ĵ�ַ%p\n", p, c);	//p ȡ��ַ

	*c = 'c';
	*p = 520;
	printf("ͨ��ָ���޸ı�����ֵ��\na=%d\n,b=%c\n", *p, *c);

	// sizeof()���÷�
	printf("sizeof(p)=%d\n", sizeof(p));
	printf("sizeof(c)=%d\n", sizeof(c));
	printf("sizeof(int)=%d\n", sizeof(int));
	
}

/*ָ�������,ָ�������ָ��*/
void pointerAndArray()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int *p;
	p = a;// ���1
	p = &a[0];// ���2
	

	/*��Ϊ�������������һ��Ԫ�صĵ�ַ��
	������� 1 ����� 2 �ǵȼ۵ģ�
	���ǽ����� a ���׵�ַ��ŵ�ָ����� p ��*/
	printf("a=%p\n&a[0]=%p\np=%p\n&a=%p\n", a, &a[0], p, &a);

	char str[128]="www.baidu.com";
	//char str[128] = {'b','a','i','d','u'};
	//char*str = "baidu.com";
	/*printf("\n������ٶ�������");
	scanf_s("%s",str);*/
	printf_s("�ٶ�������%s\n",str);
	printf("str�ĵ�ַ�ǣ�%p\n",str);
	printf("str�ĵ�ַ�ǣ�%p\n",&str[0]);
}

/*ָ������
��ָ��ָ������Ԫ�ص�ʱ�����ǿ��Զ�ָ��������мӼ����㣬
�������������൱��ָ�����ָ������λ����ǰ������ n ��Ԫ�ء�
���� *(p+1) ��ʾָ�� p ָ��ָ���Ԫ�ص���һ��Ԫ�أ�*(p-1) ���ʾָ����һ��Ԫ�ء�

��Ҫ֣��ǿ�����ǣ�*(p+1) �����Ǽ򵥵ؽ���ַ�� 1������ָ���������һ��Ԫ�ء�
 p+1 ���Ǽ򵥵ؽ���ַ�� 1��p+1=p+1*sizeof��m��
*/
void pointerOperation()
{
	char a[] = "GeekGray";
	int b[] = { 1, 2, 3, 4, 5 };
	float c[] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };
	double d[] = { 1.1, 1.2, 1.3, 1.4, 1.5, 1.6 };

	char *pa = a;
	printf("*pa=%c,*(pa+1)=%c,*(pa+2)=%c\n",*pa,*(pa+1),*(pa+2));
	printf("p=%p,pa+1=%p\n",pa, pa+1);
	printf("*pa=%c,*pa+1=%c\n",*pa,*pa+1);	//*pa+1:��ȡpa��ֵ��Ȼ����pa��ֵ��1������*paΪ��G������*pa+1Ϊ��H��
}

/*ָ��ʵ�� strlen��������*/
int myStrlen(char* str)
{
	char * target = str;
	int count = 0;

	while (*target++ != '\0')				//	�������飬
	{
		count++;
	}
	printf("�ַ�������Ϊ��%d\n",count);
	return count;
}


/*ָ��ʵ�� strcmp��������*/
int myStrcmp(const char* s1,const char* s2)
{
	/*int idx = 0;
	while (s1[idx]==s2[idx] && s1[idx]!='\0')
	{
		idx++;
	}*/
	while (*s1==*s2 && *s1!='\0')
	{
		s1++;	// ָ����һ�����ƶ�ָ��
		s2++;
	}

	return *s1 - *s2;
}


/*ָ��ʵ�� strcpy��������*/
char* myStrcpy(char* charDst,const char* charSrc)
{
	int idx = 0;
	while (charSrc[idx])
	{
		charDst[idx] == charSrc[idx];
		idx++;
	}
	charDst = '\0';
	return charDst;

	/*ָ��汾*/
	/*char* ret = charDst;
	while (*charDst++ = *charSrc++);

	*charDst = '\0';

	return ret;*/
}





/*ָ�����飺������,ÿ������Ԫ�ش��һ��ָ�����
  �����±�����ȼ�Ҫ��ȡֵ����������ȼ��ߣ�
  ��������Ϊ����p1 ������Ϊ���� 5 ��Ԫ�ص����顣
  ��ô����Ԫ�ص������أ���������
  ��Ȼ���ǣ���Ϊ����һ���Ǻţ���������Ӧ����ָ�����ͱ�����ָ�롣
*/
void pointerArray()
{
	int a, b, c, d, e;
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 5;
	int *p[5] = {&a,&b,&c,&d,&e};	//ָ�������ʼ��
	printf("*p=%p\n", *p);
	int i = 0;


	for ( i = 0; i < 5; i++)
	{
		printf("%d,",*p[i]);
	}

	printf("\n");

	char *pa[5] =
	{
		"GeekGray",
		"one more thing",
		"Oracle vm virtualbox"
	};

	printf("*pa=%p\n",*pa);

	int j = 0;
	for ( i = 0; i < sizeof(*pa); i++)
	{
		printf("%s\n", pa[i]);
	}
}


/*����ָ�룺��ָ��,��ָ�����һ������
  ��ΪԲ���ź������±�λ��ͬһ�����ȼ����У�
  �������ǵĽ���Զ��Ǵ����ң����� p2 �ȱ�����Ϊһ��ָ�������
  ��߻�������һ������ 5 ��Ԫ�ص����飬p2 ָ��ľ�������
  ����ָ�������������ʵ�Ͼ�������ָ���Ԫ�ص����ͣ�������� int ���Ƕ�������Ԫ�ص�����Ϊ���͡�
*/
void arrayPointer()
{
	int a[5] = {1,2,3,4,5};
	int(*p)[5]=&a;
	int i=0;

	printf("*p=%p\n", *p );
	printf("*p+1=%p\n", *p + 1);
	printf("**p=%d\n", **p);
	printf("p=%p\n", p);

	for ( i = 0; i < 5; i++)
	{
		printf("%d\n",*(*p+i));	//*p:����ĵ�ַ

	}
}


/*ָ��Ͷ�ά����*/
void pointerAndTwoDimensionalArray()
{
	int array[4][5] = {0};

	printf("sizeof(int):%d\n",sizeof(int));
	printf("array:%p\n", array);	//��ά�����ַ

	/*array+1:��2�е��׵�ַ��*��array+1��==array[1],
	array[1]���൱������ array[1][0] ������������&array[1][0]
	*/
	printf("array+1:%p\n", array + 1);
	printf("*��array+1��:%p\n", *(array+1));
	printf("array[1]:%p\n", array[1]);
	printf("&array[1][0]:%p\n", &array[1][0]);
	printf("array[1][0]:%d\n", array[1][0]);

	/* *(array+1)+3==&array[1][3]
	   *(*(array+1)+3)==array[1][3]
	*/
	printf("*(array+1)+3:%p\n", *(array + 1) + 3);
	printf("&array[1][3]:%p\n", &array[1][3]);
	printf("*(*(array+1)+3):%d\n", array[1][3]);
	
}


/*����ָ��Ͷ�ά����*/
void arrayPointerAndTwoDimensionalArray()
{
	int array[2][3] = 
						{
							{1,2,3},
							{4,5,6}
						};
	int(*p)[3] = array;	//int(*p)[3] = array=&array[0]��ֵ��ȣ����Ǹ��һ��;
	
	/*���µ�ַ*/
	printf("p= %p\n", p);
	printf("array= %p\n", array);
	printf("array[0]= %p\n", array[0]);
	printf("&array[0]= %p\n", &array[0]);
	printf("&array[0][0]: %p\n", &array[0][0]);

	printf("\n");

	printf("p+1= %p\n", p+1);
	printf("array+1= %p\n", array+1);
	printf("array[1]= %p\n", array[1]);
	printf("&array[1]= %p\n", &array[1]);
	printf("&array[1][0]: %p\n", &array[1][0]);

	printf("\n");

	/*ͨ������ָ����ʶ�ά���飬���ÿ��һ��*/
	printf("**(p+1): %d\n", **(p + 1));
	printf("**(array+1): %d\n", **(array + 1));
	printf("array[1][0]: %d\n", array[1][0]);

	printf("\n");

	printf("*(*(p+1)+2): %d\n", *(*(p + 1) + 2));
	printf("*(*(array+1)+2): %d\n", *(*(array + 1) + 2));
	printf("array[1][2]: %d\n", array[1][2]);
}


/*ָ��ָ���ָ��
  �����ظ������ڴ�
  ֻ��Ҫ�޸�һ��
*/
void pointerToPointer()
{
	int num = 520;
	int *p = &num;
	int **pp = &p;

	printf("num= %d\n",num);
	printf("*p= %d\n", *p);
	printf("**pp= %d\n", **pp);
	printf("&p= %p\npp= %p\n", &p,pp);

	printf("\n");


	/*ָ������*/
	char *cBooks[] = 
						{
							"��C����������ԡ�",
							"��C��ָ�롷",
							"��Cר�ұ�̡�",
							"������Cָ�롷",
							"��C primer plus��",
							"��C�ݽ���ȱ�ݡ�"
						};

	char **byEnglish;
	char **excellentBooks[4];

	

	byEnglish = &cBooks[4];	//�õ�����ַ����ĵ�ַ������һ��Ԫ�ص��׵�ַ��ʵ���Ͼ���ָ��ָ���ָ��
	excellentBooks[0] = &cBooks[0];
	excellentBooks[1] = &cBooks[1];
	excellentBooks[2] = &cBooks[2];
	excellentBooks[3] = &cBooks[3];

	printf("cBooks��%p\n", cBooks);
	printf("*cBooks��%p\n", *cBooks);
	printf("**byEnglish��%p\n", **byEnglish);
	printf("byEnglish��%p\n", byEnglish);
	printf("excellentBooks��%p\n", excellentBooks);
	printf("*excellentBooks��%p\n", *excellentBooks);
	printf("**excellentBooks��%p\n", **excellentBooks);

	printf("Ӣ�İ��ͼ���У�%s\n",*byEnglish);
	printf("�����ͼ���У�%s\n");

	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		printf("%s\n",*excellentBooks[i]);
	}
}


/*������ָ��*/
void constantsAndPointers()
{
	const float pi = 3.14;	//ֻ�ܶ�������д����ͼ�޸Ļᱨ��

	// ָ������ָ��
	// ָ������޸�Ϊָ��ͬ�ĳ��������
	// ����ͨ������������ȡָ��ָ�������
	// ������ͨ���������޸�ָ��ָ�������
	int num = 50;
	const int cnum = 880;
	const int *pc = &cnum;

	printf("cnum: %d,&cnum: %p\n",cnum,&cnum);

	//*pc = 1024;	// ��ͼ�޸�pc��ֵ����

	//pc = &num;	// �����޸�ָ��
	//*pc = 1024;	//��ֹ
	//num = 102;	//����


	/*����ָ��
	  ָ���������Ա��޸�
	  ָ��ָ���ֵ���Ա��޸�
	*/
	int num1 = 520;
	const int cnum1 = 888;
	int *const p1 = &num1;	//const����p

	*p1 = 1024;				//���Ըı�
	//p1 = &cnum1;			// ��ֹ�޸�


	/*ָ�����ĳ���ָ��
	  ָ���������Ա��޸�
	  ָ��ָ���ֵҲ�����Ա��޸�
	*/
	int num2 = 520;
	const int cnum2 = 888;
	const int *const p2 = &cnum2;	// ûʲô�ã�ֱ��ͨ���������Ϳ����޸�ֵ������ô����Ҳû�ã�ֻ�ܱ���p2

	//*p2 = 1024;					//��ֹ�޸�
	//p2 = &cnum2;					// ��ֹ�޸�


	/*ָ��ָ�����ĳ���ָ�롱��ָ��*/
	int num3 = 520;
	const int cnum3 = 888;
	const int *const p3 = &cnum3;
	const int *const *pp = &p3;		//ָ��ָ�����ĳ���ָ�롱��ָ��
}


/*������ָ��,������
  ��������Ԫ�ص�ַ����ȥ
*/
void getArray(int a[10])
{
	printf("getArray->sizeof(a): %d\n", sizeof(a));	//�����4�����ǵ���Ԫ����ռ�ֽ���

	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}
}


void parametersAndPointers()
{
	/*������*/
	int a[10]={1,2,3,4,5,6,7,8,9,0};

	printf("main->sizeof(a): %d\n",sizeof(a));		//�����40������������ռ�ռ�
	getArray(a);
}


/*�ɱ��������*/
int sum(int n,...)					// ����С����ռλ������ʾ����������ȷ��
{
	int i, sum = 0;
	va_list vap;					// ��������б�,vap��һ���ַ�ָ��

	va_start(vap, n);				// ��ʼ�������б������ int sum(int gg, ...); ������Ӧ���� va_start(vap, gg);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(vap, int);	// ��ȡ����ֵ
	}
	va_end(vap);					// ��β�������رղ����б�

	return sum;
}


/*ָ�뺯��
  ��Ҫ���ؾֲ�������ָ�룬�������������˽�һ�£�
  �ַ������ڳ����صģ��Ƚ����⣬�̶��洢
*/
char *getWord(char);
void pointerFunction()
{
	printf("%s\n", getWord('A'));
	printf("%s\n", getWord('B'));
	printf("%s\n", getWord('C'));
	printf("%s\n", getWord('D'));
	printf("%s\n", getWord('E'));
}

char *getWord(char c)
{
	switch (c)
	{
	case 'A': return "Apple";	//��ʵ���ص���A�ĵ�ַ
	case 'B': return "Banana";
	case 'C': return "Cat";
	case 'D': return "Dog";
	default: return "None";
		
	}
}


/*����ָ��*/
int square(int);
void functionPointer()
{
	int num=100;
	int(*fp)(int);

	fp = square;
	printf("%d * %d = %d",num,num,(*fp)(num));
}

int square(int num)
{
	return num*num;
}


/*����ָ����Ϊ��������
  ָ��һ�����������������Ҫ���㼸������.....
*/
int add(int, int);
int sub(int,int);
int calc(int (*fp)(int,int),int,int);
void functionPointerAsParameter()
{
	printf("3 + 5 = %d\n",calc(add,3,5));
	printf("3 - 5 = %d\n", calc(sub, 3, 5));
}

int add(int num1, int num2)
{
	return num1 + num2;
}

int sub(int num1, int num2)
{
	return num1 - num2;
}

int calc(int(*fp)(int, int), int num1, int num2)
{
	return (*fp)(num1, num2);
}


/*����ָ����Ϊ����ֵ
  ����һ���������Ͳ��Ҵ���2�����Ͳ����ĺ���ָ��
  */
int(*select(char op))(int num1, int num2);
void functionPointerAsReturnValue()
{
	int num1 = 100;
	int num2 = 200;
	char op1 = '-';
	char op2 = '+';

	int(*fp)(int, int);
	int(*fp1)(int, int);
	fp = select(op1);
	fp1 = select(op2);
	printf("%d %c %d = %d\n",num1,op1,num2, calc(fp, num1, num2));
	printf("%d %c %d = %d\n", num1, op2, num2, calc(fp1, num1, num2));
}

int(*select(char op))(int num1, int num2) 
{
	switch (op)
	{
	case '+': return add;
	case '-': return sub;
	
	}
} 