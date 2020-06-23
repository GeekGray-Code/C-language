#ifndef _CHAPTER8_FUNCTION_H
#define _CHAPTER8_FUNCTION_H 




#define ARRAYLENGTH 3

void chapter8FunctionTest();											//chapter8 函数 测试函数
void funConvertArray(int array[][3]);									/*使给定的一个3*3的二维整型数组转置，即行列互换*/
void funConvertArrayTest();												/*convertArray 测试函数*/
void funInverseStringTest();											/*funInverseString 测试函数*/
void funConcatString(char string1[], char string2[], char string[]);	/*字符串拼接*/
void funConcatStringTest();												/*字符串拼接测试函数*/
void funCopyVowel(char srcStr[], char destStr[]);                       //将一个字符串中的元音字母复制到另一个字符串中然后输出该字符串
void funCopyVowelTest();                                                //funCopyVowel 测试函数
void funPrintDigits(char digitsStr[]);                                  //输入一个4位数字，要去输出这4个数字字符，但两个数字之间空一个空格
void funPrintDigitsTest();                                              //funPrintDigits 测试函数
void longestWordStartPositionTest();                                    //longestWordStartPosition 测试函数
void funConvertNumTest();                                               //funConvertNum 测试函数
void funCountingDays();//计算该日是该年的第几天






#endif