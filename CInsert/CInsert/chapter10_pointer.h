#ifndef _CHAPTER10_POINTER_H
#define _CHAPTER10_POINTER_H 




/*代码示例*/
void chapter10PointerTest();						//chapter10 指针 测试函数
void pointerTest();									//定义指针变量、取地址运算符、取值运算符
void pointerAndArray();								//指针和数组,指向数组的指针
void pointerOperation();							//指针运算
int myStrlen(char*);								//指针实现 strlen（）函数
int myStrcmp(const char* s1, const char* s2);		//指针实现 strcmp（）函数
char* myStrcpy(char* charDst, const char* charSrc);	//指针实现 strcpy（）函数
void pointerArray();								//指针数组
void arrayPointer();								//数组指针
void pointerAndTwoDimensionalArray();				//指针和二维数组
void arrayPointerAndTwoDimensionalArray();			//数组指针和二维数组
void pointerToPointer();							//指向指针的指针
void constantsAndPointers();						//常量和指针
void parametersAndPointers();						//参数和指针,传数组
int sum(int n, ...);								//可变参数函数
void pointerFunction();								//指针函数
void functionPointer();								//函数指针
void functionPointerAsParameter();					//函数指针作为参数传递
void functionPointerAsReturnValue();				//函数指针作为返回值

/*课后习题*/
void pointerCompareNum();//输入3个整数，按由小到大的顺序输出
void pointerStrcmp();//输入3个字符串，按由小到大的顺序输出
void sortStrTest();//
void sortNumTest();//




#endif