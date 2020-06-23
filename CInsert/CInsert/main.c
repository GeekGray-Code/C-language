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
	

	/*chapter4 ˳��ṹ*/
	chapter4SequentialStructureTest();

	/*chapter5 ѡ��ṹ*/
	chapter5SelectStructureTest();	

	/*chapter6 ѭ���ṹ*/
	chapter6CyclicStructureTest();

	/*chapter7 ���� ���Ժ���*/
	chapter7ArrayTest();
	
	/*chapter8 ����*/
	chapter8FunctionTest();

	/*chapter10 ָ��*/
	chapter10PointerTest();

	/*chapter11 �ṹ��*/
	chapter11StructureTest();

	/*chapter13 �ļ�����*/
	chapter13FileOperationTest();

	/*pracLinkedList ����*/
	pracLinkedListTest();

	/*pracStringFunction �ַ���������*/
	pracStringFunctionTest();

	/*ϰ�� ���Ժ���*/
	pracExaminationTest();

	/*����� ���Ժ���*/
	programTest();

	/*�����㷨100�� ���Ժ���*/
	pracClassicAlgorithm100Test();

	/*�����㷨 ���Ժ���*/
	sortTest();

	
	
	return 0;
}