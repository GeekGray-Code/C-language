#include<string.h>
#include<stdarg.h>
#include <stdio.h>

#include "chapter10_pointer.h"


/*chapter10 指针 测试函数*/
void chapter10PointerTest()
{
	/*代码示例*/
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

	/*课后习题*/
	//pointerCompareNum();
	//pointerStrcmp();
	//sortStrTest();
	//sortNumTest();
}

/****************************************课后习题************************************************************************/

/************************************************************************************************************/

/*
将n个数按输入时顺序的逆序排列，用函数实现
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

/*将n个数按输入时顺序的逆序排列，用函数实现*/
void sortNumTest()
{
	int numCnt;//个数
	char* pNum;
	char numArr[20];

	

	printf("请输入个数：");
	scanf("%d",&numCnt);

	printf("请输入这%d个数,回车间隔:\n",numCnt);
	for (int i = 0; i < numCnt; i++)
	{
		scanf("%d",&numArr[i]);
	}

	pNum = numArr;
	sortNum(pNum,numCnt);

	printf("逆序输出这%d个数:\n", numCnt);
	for (int i = 0; i < numCnt; i++)
	{
		printf("%d", numArr[i]);
	}

	printf("\n");
}

/************************************************************************************************************/



/************************************************************************************************************/
/*
在主函数中输入10个等长的字符串，用另一函数对它们排序，然后输出
*/

/*字符串排序*/
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
				/*将str[j]指向的一维数组的内容与str[j+1]指向的指向的一维数组的内容互换*/
				strcpy(p,str[j]);
				strcpy(str[j], str[j+1]);
				strcpy(str[j+1], p);
			}

		}

	}
}

/*输入10个等长的字符串，用另一函数对它们排序，然后输出*/
void sortStrTest()
{
	char str[10][6];

	printf("请输入10个等长的字符串,字符串长度为5！\n");
	for (int i = 0; i < 10; i++)
	{
		scanf("%s",str[i]);
	}

	sortStr(str);

	printf("排序后的字符串：\n");
	for (int i = 0; i < 10; i++)
	{
		printf("%s\n", str[i]);
	}
}
/************************************************************************************************************/


/************************************************************************************************************/
/*交换字符串*/
void swapString(char *str1, char* str2)
{
	char str[20];

	strcpy(str,str1);
	strcpy(str1,str2);
	strcpy(str2, str);
}

/*输入3个字符串，按由小到大的顺序输出*/
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
/*交换2数*/
void swapInt(int *p1, int *p2)
{
	int p;

	p = *p1;
	*p1 = *p2;
	*p2 = p;
}

/*输入3个整数，按由小到大的顺序输出*/
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




/****************************************代码示例***********************************************************************/
/*定义指针变量、取地址运算符、取值运算符*/
void pointerTest()
{
	int a = 1;
	char b = 2;

	int * p = &a;
	char * c = &b;

	printf("a=%d,c=%c\n",*p,*c);				//*p 取值运算
	printf("a的地址：%p\n,b的地址%p\n", p, c);	//p 取地址

	*c = 'c';
	*p = 520;
	printf("通过指针修改变量的值：\na=%d\n,b=%c\n", *p, *c);

	// sizeof()的用法
	printf("sizeof(p)=%d\n", sizeof(p));
	printf("sizeof(c)=%d\n", sizeof(c));
	printf("sizeof(int)=%d\n", sizeof(int));
	
}

/*指针和数组,指向数组的指针*/
void pointerAndArray()
{
	int a[] = { 1, 2, 3, 4, 5 };
	int *p;
	p = a;// 语句1
	p = &a[0];// 语句2
	

	/*因为数组名即数组第一个元素的地址，
	所以语句 1 和语句 2 是等价的，
	都是将数组 a 的首地址存放到指针变量 p 中*/
	printf("a=%p\n&a[0]=%p\np=%p\n&a=%p\n", a, &a[0], p, &a);

	char str[128]="www.baidu.com";
	//char str[128] = {'b','a','i','d','u'};
	//char*str = "baidu.com";
	/*printf("\n请输入百度域名：");
	scanf_s("%s",str);*/
	printf_s("百度域名：%s\n",str);
	printf("str的地址是：%p\n",str);
	printf("str的地址是：%p\n",&str[0]);
}

/*指针运算
当指针指向数组元素的时候，我们可以对指针变量进行加减运算，
这样做的意义相当于指向距离指针所在位置向前或向后第 n 个元素。
比如 *(p+1) 表示指向 p 指针指向的元素的下一个元素；*(p-1) 则表示指向上一个元素。

需要郑重强调的是：*(p+1) 并不是简单地将地址加 1，而是指向数组的下一个元素。
 p+1 就是简单地将地址加 1，p+1=p+1*sizeof（m）
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
	printf("*pa=%c,*pa+1=%c\n",*pa,*pa+1);	//*pa+1:先取pa的值，然后让pa的值加1，比如*pa为‘G’，则*pa+1为‘H’
}

/*指针实现 strlen（）函数*/
int myStrlen(char* str)
{
	char * target = str;
	int count = 0;

	while (*target++ != '\0')				//	遍历数组，
	{
		count++;
	}
	printf("字符串长度为：%d\n",count);
	return count;
}


/*指针实现 strcmp（）函数*/
int myStrcmp(const char* s1,const char* s2)
{
	/*int idx = 0;
	while (s1[idx]==s2[idx] && s1[idx]!='\0')
	{
		idx++;
	}*/
	while (*s1==*s2 && *s1!='\0')
	{
		s1++;	// 指向下一个，移动指针
		s2++;
	}

	return *s1 - *s2;
}


/*指针实现 strcpy（）函数*/
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

	/*指针版本*/
	/*char* ret = charDst;
	while (*charDst++ = *charSrc++);

	*charDst = '\0';

	return ret;*/
}





/*指针数组：是数组,每个数组元素存放一个指针变量
  数组下标的优先级要比取值运算符的优先级高，
  所以先入为主，p1 被定义为具有 5 个元素的数组。
  那么数组元素的类型呢？是整型吗？
  显然不是，因为还有一个星号，所以它们应该是指向整型变量的指针。
*/
void pointerArray()
{
	int a, b, c, d, e;
	a = 1;
	b = 2;
	c = 3;
	d = 4;
	e = 5;
	int *p[5] = {&a,&b,&c,&d,&e};	//指针数组初始化
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


/*数组指针：是指针,它指向的是一个数组
  因为圆括号和数组下标位于同一个优先级队列，
  由于它们的结合性都是从左到右，所以 p2 先被定义为一个指针变量。
  后边还紧跟着一个具有 5 个元素的数组，p2 指向的就是它。
  由于指针变量的类型事实上就是它所指向的元素的类型，所以这个 int 就是定义数组元素的类型为整型。
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
		printf("%d\n",*(*p+i));	//*p:数组的地址

	}
}


/*指针和二维数组*/
void pointerAndTwoDimensionalArray()
{
	int array[4][5] = {0};

	printf("sizeof(int):%d\n",sizeof(int));
	printf("array:%p\n", array);	//二维数组地址

	/*array+1:第2行的首地址，*（array+1）==array[1],
	array[1]又相当于数组 array[1][0] 的数组名，即&array[1][0]
	*/
	printf("array+1:%p\n", array + 1);
	printf("*（array+1）:%p\n", *(array+1));
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


/*数组指针和二维数组*/
void arrayPointerAndTwoDimensionalArray()
{
	int array[2][3] = 
						{
							{1,2,3},
							{4,5,6}
						};
	int(*p)[3] = array;	//int(*p)[3] = array=&array[0]，值相等，但是概念不一样;
	
	/*看下地址*/
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

	/*通过数组指针访问二维数组，利用跨度一致*/
	printf("**(p+1): %d\n", **(p + 1));
	printf("**(array+1): %d\n", **(array + 1));
	printf("array[1][0]: %d\n", array[1][0]);

	printf("\n");

	printf("*(*(p+1)+2): %d\n", *(*(p + 1) + 2));
	printf("*(*(array+1)+2): %d\n", *(*(array + 1) + 2));
	printf("array[1][2]: %d\n", array[1][2]);
}


/*指向指针的指针
  避免重复分配内存
  只需要修改一处
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


	/*指针数组*/
	char *cBooks[] = 
						{
							"《C程序设计语言》",
							"《C和指针》",
							"《C专家编程》",
							"《征服C指针》",
							"《C primer plus》",
							"《C陷进与缺陷》"
						};

	char **byEnglish;
	char **excellentBooks[4];

	

	byEnglish = &cBooks[4];	//得到这个字符串的地址，即第一个元素的首地址，实际上就是指向指针的指针
	excellentBooks[0] = &cBooks[0];
	excellentBooks[1] = &cBooks[1];
	excellentBooks[2] = &cBooks[2];
	excellentBooks[3] = &cBooks[3];

	printf("cBooks：%p\n", cBooks);
	printf("*cBooks：%p\n", *cBooks);
	printf("**byEnglish：%p\n", **byEnglish);
	printf("byEnglish：%p\n", byEnglish);
	printf("excellentBooks：%p\n", excellentBooks);
	printf("*excellentBooks：%p\n", *excellentBooks);
	printf("**excellentBooks：%p\n", **excellentBooks);

	printf("英文版的图书有：%s\n",*byEnglish);
	printf("优秀的图书有：%s\n");

	int i = 0;
	for ( i = 0; i < 4; i++)
	{
		printf("%s\n",*excellentBooks[i]);
	}
}


/*常量和指针*/
void constantsAndPointers()
{
	const float pi = 3.14;	//只能读，不能写，试图修改会报错

	// 指向常量的指针
	// 指针可以修改为指向不同的常量或变量
	// 可以通过解引用来读取指针指向的数据
	// 不可以通过解引用修改指针指向的数据
	int num = 50;
	const int cnum = 880;
	const int *pc = &cnum;

	printf("cnum: %d,&cnum: %p\n",cnum,&cnum);

	//*pc = 1024;	// 试图修改pc的值不行

	//pc = &num;	// 可以修改指向
	//*pc = 1024;	//禁止
	//num = 102;	//可以


	/*常量指针
	  指针自身不可以被修改
	  指针指向的值可以被修改
	*/
	int num1 = 520;
	const int cnum1 = 888;
	int *const p1 = &num1;	//const修饰p

	*p1 = 1024;				//可以改变
	//p1 = &cnum1;			// 禁止修改


	/*指向常量的常量指针
	  指针自身不可以被修改
	  指针指向的值也不可以被修改
	*/
	int num2 = 520;
	const int cnum2 = 888;
	const int *const p2 = &cnum2;	// 没什么用，直接通过变量名就可以修改值，再怎么限制也没用，只能保护p2

	//*p2 = 1024;					//禁止修改
	//p2 = &cnum2;					// 禁止修改


	/*指向“指向常量的常量指针”的指针*/
	int num3 = 520;
	const int cnum3 = 888;
	const int *const p3 = &cnum3;
	const int *const *pp = &p3;		//指向“指向常量的常量指针”的指针
}


/*参数和指针,传数组
  将数组首元素地址传过去
*/
void getArray(int a[10])
{
	printf("getArray->sizeof(a): %d\n", sizeof(a));	//结果是4，就是单个元素所占字节数

	int i = 0;
	for ( i = 0; i < 10; i++)
	{
		printf("a[%d] = %d\n",i,a[i]);
	}
}


void parametersAndPointers()
{
	/*传数组*/
	int a[10]={1,2,3,4,5,6,7,8,9,0};

	printf("main->sizeof(a): %d\n",sizeof(a));		//结果是40，整个数组所占空间
	getArray(a);
}


/*可变参数函数*/
int sum(int n,...)					// 三个小点是占位符，表示参数个数不确定
{
	int i, sum = 0;
	va_list vap;					// 定义参数列表,vap是一个字符指针

	va_start(vap, n);				// 初始化参数列表，如果是 int sum(int gg, ...); 则这里应该是 va_start(vap, gg);
	for (i = 0; i < n; i++)
	{
		sum += va_arg(vap, int);	// 获取参数值
	}
	va_end(vap);					// 收尾工作，关闭参数列表

	return sum;
}


/*指针函数
  不要返回局部变量的指针，作用域生存期了解一下，
  字符串是在常量池的，比较特殊，固定存储
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
	case 'A': return "Apple";	//其实返回的是A的地址
	case 'B': return "Banana";
	case 'C': return "Cat";
	case 'D': return "Dog";
	default: return "None";
		
	}
}


/*函数指针*/
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


/*函数指针作为参数传递
  指向一个函数，这个函数需要满足几个参数.....
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


/*函数指针作为返回值
  返回一个返回整型并且带有2个整型参数的函数指针
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