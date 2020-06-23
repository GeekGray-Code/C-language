#include<stdio.h>
#include<stdlib.h>

#include"chapter4_sequential_structure.h"
#include"chapter5_select_structure.h"
#include"chapter6_cyclic_structure.h"
#include"chapter7_array.h"
#include"chapter8_function.h"
#include"chapter10_pointer.h"
#include"chapter11_structure.h"
#include"chapter13_file_operation.h"

#include"prac_examination.h"
#include"prac_string_function.h"
#include"prac_linked_list.h"
#include"program.h"
#include"prac_classic_algorithm_100.h"
#include"sort.h"




int main(void)
{
	

	/*chapter4 顺序结构*/
	chapter4SequentialStructureTest();

	/*chapter5 选择结构*/
	chapter5SelectStructureTest();	

	/*chapter6 循坏结构*/
	chapter6CyclicStructureTest();

	/*chapter7 数组 测试函数*/
	chapter7ArrayTest();
	
	/*chapter8 函数*/
	chapter8FunctionTest();

	/*chapter10 指针*/
	chapter10PointerTest();

	/*chapter11 结构体*/
	chapter11StructureTest();

	/*chapter13 文件操作*/
	chapter13FileOperationTest();

	/*pracLinkedList 链表*/
	pracLinkedListTest();

	/*pracStringFunction 字符串处理函数*/
	pracStringFunctionTest();

	/*习题 测试函数*/
	pracExaminationTest();

	/*编程题 测试函数*/
	programTest();

	/*经典算法100题 测试函数*/
	pracClassicAlgorithm100Test();

	/*排序算法 测试函数*/
	sortTest();

	
	
	return 0;
}