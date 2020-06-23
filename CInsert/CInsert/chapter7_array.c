#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter7_array.h"


/*chapter7 ���� ���Ժ���*/
void chapter7ArrayTest()
{
	//calcFibonacciByArray();
	//calcVocabularyCount();
	//calcLargestString();
	//calcPrimeNumByEratonsthenes();
	//calcArrayInversion();
	//calcYangHuiTriangle();
	//calcSaddlePoint();
	//calcCharacters();
	//calcStrcmp();
	//calcStrcpy();

}



/*
���ַ�����s2�е�ȫ���ַ���ֵ���ַ�����s1��
����ʱ��'\0'ҲҪ���ƹ�ȥ��'\0'������ַ����ø���
*/
void calcStrcpy()
{
	char s1[80], s2[80];

	printf("�������ַ���s2:\n");
	//scanf("%s",s2);
	gets(s2);

	for (int i = 0; i <= strlen(s2); i++)
	{
		s1[i] = s2[i];
	}

	printf("s1:%s\n",s1);
}





/*
�������ַ���s1��s2�Ƚϣ���s1>s2�����һ����������s1=s2�����0����s1<s2�����һ������
����ַ���ASCII�Ĳ�ֵ
���磺��A��<'C'��ASCII�����2������"A"<"C" Ӧ���-2
*/
void calcStrcmp()
{
	int result,index=0;
	char s1[100], s2[100];

	printf("������ string1��\n");
	gets(s1);

	printf("������ string2��\n");
	gets(s2);

	while ((s1[index]==s2[index]) && (s1[index]!='\0'))
	{
		index++;
	}

	if (s1[index]=='\0' && s2[index]=='\0')
	{
		result = 0;
	}
	else
	{
		result = s1[index] - s2[index];
	}

	printf("\nresult:%d\n",result);
}


/*
��һƪ���£�����3�����֣�ÿ����80���ַ���
Ҫ��ֱ�ͳ�Ƴ�����Ӣ�Ĵ�д�ַ���Сд��ĸ�����֣��ո��Լ������ַ��ĸ���
*/
void calcCharacters()
{
	int upp, low, dig, space, other;
	char text[3][80];

	upp = low = dig = space = other = 0;

	for (int i = 0; i < 3; i++)
	{
		printf("�������%d������:\n",i+1);
		gets(text[i]);

		for (int j = 0; j < 80 && text[i][j]!='\0'; j++)
		{
			if (text[i][j]>='A' && text[i][j]<='Z')
			{
				upp++;
			}
			else if (text[i][j] >= 'a' && text[i][j] <= 'z')
			{
				low++;
			}
			else if (text[i][j] >= '0' && text[i][j] <= '9')
			{
				dig++;
			}
			else if (text[i][j] ==' ')
			{
				space++;
			}
			else
			{
				other++;
			}
		}
	}

	printf("upp:%d\n",upp);
	printf("low:%d\n", low);
	printf("dig:%d\n", dig);
	printf("space:%d\n", space);
	printf("other:%d\n", other);
}


/*
�ҳ�һ����ά����İ��㣬����λ���ϵ�Ԫ���ڸ���������ڸ�������С��Ҳ����û�а���
����˼·��һ����ά���������һ�����㣬Ҳ����û��
		���ҳ�һ����ֵ����Ԫ�أ�Ȼ�������Ƿ�Ϊ�����е���Сֵ������ǣ����ǰ��㣨����Ҫ�������������ˣ�
		������ǣ���������һ�е����ֵ....���ÿһ�е����ֵ�����ǰ��㣬�������û�а���
*/
void calcSaddlePoint()
{
	int arr[ROW][COLUMN];
	int max, maxColumn,flag;

	printf("�������ά���飺\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			scanf("%d",&arr[i][j]);
		}
	}

	int count=0;
	printf("��ά���飺\n");
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COLUMN; j++)
		{
			count++;
			printf("%d\t", arr[i][j]);

			if (count%5==0)
			{
				printf("\n");
			}
		}
	}



	for (int i = 0; i < ROW; i++)
	{
		max = arr[i][0];							    //��ʼ����arr[i][0]���
		maxColumn = 0;										//���к�0����maxj����
		                                                
		for (int j = 0; j < COLUMN; j++)			    //�ҳ���i���е������
		{
			if (arr[i][j]>max)
			{
				max = arr[i][j];						//�������е�����������max��
				maxColumn = j;								//����������ڵ��кŴ����maxj��
			}
		}

		flag = 1;										//�ȼ����ǰ��㣬��flagΪ1��־

		for (int k = 0; k < ROW; k++)
		{
			if (max>arr[k][maxColumn])						//�����������ͬ��Ԫ�����
			{
				flag = 0;								//���max����ͬ����С����ʾ���ǰ��㣬��flag ��1��Ϊ0
				continue;
			}
		}

		if (flag)										//���flagΪ1����ʾ�ǰ���
		{
			printf("���㣺arr[%d][%d]=%d\n",i,maxColumn,max);//�������ֵ���������к�
			break;
		}
	}

	if (!flag)											//���flagΪ0��ʾ���㲻����
	{
		printf("���㲻���ڣ�\n");
	}
}



/*
����������
�����������(a+b)^n չ��������ϵ��
���磺
(a+b)^0 չ����Ϊ1��ϵ��Ϊ1
(a+b)^1 չ����Ϊa+b��ϵ��Ϊ1��1
(a+b)^2 չ����Ϊa^2+2*a*b+b^2��ϵ��Ϊ1��2��1
(a+b)^3 չ����Ϊa^3+3*a^2*b+b^3��ϵ��Ϊ1��3��3��1
(a+b)^4 չ����Ϊa^4+4*a^3*b+6*a^2*b^2+4*a*b^3+b^4��ϵ��Ϊ1��4��6��4��1
���ɣ�
	(1)���е�һ������1
	(2)�������һ������1
	(3)�ӵ�3���𣬳�����ָ���ĵ�һ���������һ�����⣬�����������һ��ͬ�к�ǰһ������֮��
	   ���磺��4�е�2�����ǵ�3�е�2�����͵�3�е�1����֮��
	   ����������ʾ��arr[i][j]=arr[i-1][j]+arr[i-1][j-1];iΪ������jΪ����
*/
void calcYangHuiTriangle()
{
	int arr[ARRAYLENGTH][ARRAYLENGTH];

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		arr[i][i] = 1;										//ʹ�Խ���Ԫ�ص�ֵΪ1
		arr[i][0] = 1;										//ʹ��1��Ԫ�ص�ֵΪ1
	}

	for (int i = 2; i < ARRAYLENGTH; i++)					//�ӵ�3�п�ʼ����
	{
		for (int j = 1; j <= i-1; j++)
		{
			//arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j];
			arr[i][j] = arr[i - 1][j] + arr[i - 1][j - 1]; //iΪ������jΪ����
		}
	}

	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%6d",arr[i][j]);						//��������Ԫ�ص�ֵ
		}

		printf("\n");
	}

	printf("\n");
}


/*
��һ�������е�ֵ���������´��
���磺ԭ��˳��Ϊ8��6��5��4��1
Ҫ���Ϊ��1��4��5��6��8
����˼·�����м�Ԫ��Ϊ���ģ���������ԳƵ�Ԫ�ص�ֵ����
*/
void calcArrayInversion()
{
	int arr[ARRAYLENGTH] = {1,2,3,4,5};
	int temp;

	printf("ԭ���飺\n");
	for (int i = 0; i < ARRAYLENGTH; i++)//��ʾ��ʼ����Ԫ��
	{
		printf("%4d", arr[i]);
	}
	printf("\n");

	for (int i = 0; i < ARRAYLENGTH/2; i++)//���ԳƵ�Ԫ�ص�ֵ�������� i ��Ԫ����� ARRAYLENGTH - i - 1 ��Ԫ�ػ���
	{
		temp = arr[i];
		arr[i] = arr[ARRAYLENGTH - i - 1];
		arr[ARRAYLENGTH - i - 1] = temp;
	}

	printf("����Ԫ�غ�����飺\n");
	for (int i = 0; i < ARRAYLENGTH; i++)
	{
		printf("%4d",arr[i]);
	}

	printf("\n");
}






/*������������fibonacci����*/
void calcFibonacciByArray()
{
	int index;										    //�����±�����
	int fib[20] = {1,1};								//��ʼ��һ��Fib���飬ֻ��ǰ2���ֵ

	for ( index = 2; index < 20; index++)
	{
		fib[index] = fib[index - 2] + fib[index - 1];	//�ӵ�3�ʼ����ǰ��=ǰ2��֮��
	}

	for ( index = 0; index < 20; index++)
	{
		if (index%5==0)
		{
			printf("\n");								//���������5������һ��
		}

		printf("%12d ",fib[index]);
	}
}






/*����һ���ַ���ͳ�����ж��ж��ٸ����ʣ�����֮��Ҫ�ÿո����*/
void calcVocabularyCount()
{
	char string[81];			//������ʾ�ַ���
	int i;
	int count = 0;		        //��������
	int vocaFlag = 0;			//��־λ
	char c;

	printf("������һ���ַ�������֮��Ҫ�ÿո����\n");
	gets(string);

	for ( i = 0; (c=string[i])!='\0'; i++)
	{
		if (c==' ')				//��ǰ�ַ�Ϊ�ո���δ�����µ��ʣ�ʹ��־vocaFlagΪ0��count���ۼ�
		{
			vocaFlag = 0;
		}
		else if (vocaFlag == 0)	//ǰһ�ַ�Ϊ�ո�vocaFlag = 0�����µ��ʳ��֣�ʹcount+1��ʹvocaFlag = 1
		{
			vocaFlag = 1;
			count++;
		}
	}

	printf("There are %d words in the line.\n",count);
}



/*��3���ַ�����Ҫ���ҳ����������*/
void calcLargestString()
{
	char largestStr[20];				//һά���飬��������ַ���
	char string[3][20];					//��ά���飬���3���ַ���
	int i;

	printf("������3���ַ���\n");
	for ( i = 0; i < 3; i++)
	{
										//��ԭ���ǣ� char *gets(char *string);
		gets(string[i]);				//gets() �����Ĺ����Ǵӻ������ж�ȡ�ַ������洢���ַ�ָ����� str ��ָ����ڴ�ռ䡣  
	}

	if (strcmp(string[0],string[1])>0)	/*strcmp �������ڱȽ������ַ������ú����ӵ�һ���ַ���ʼ��
									    ���αȽ�ÿ���ַ��� ASCII ���С��ֱ�����������ַ�����Ȼ�ִ��������'\0'��Ϊֹ��*/
	{
		strcpy(largestStr,string[0]);	//strcpy �������ڿ����ַ������������Ľ����� '\0'��
	}
	else
	{
		strcpy(largestStr, string[1]);
	}

	if (strcmp(string[2], largestStr)>0)
	{
		strcpy(largestStr, string[2]);
	}

	printf("\nThe largest string is: %s\n",largestStr);
}


/*��ɸѡ����100֮�ڵ�����
  ɸѡ����������ɫ�ᣨEratonsthenes��ɸ��
  ���裺��һ��ֽ��д��1000���ڵ�ȫ���������ڵ������������ʣ�µľ�������
*/
void calcPrimeNumByEratonsthenes()
{
	int i, j;
	int n;							//������ݵĸ���
	int arr[101];					//����101��Ԫ��

	for ( i = 1; i <= 100; i++)		//arr[0]���ã�ֻ��arr[1]~arr[100]
	{
		arr[i] = i;					//ʹarr[1]~arr[100]��ֵΪ1~100
	}

	arr[1] = 0;						//���ڵ�arr[1]

	for ( i = 2; i < sqrt(100); i++)
	{
		for ( j = i+1; j <= 100; j++)
		{
			if (arr[i]!=0 && arr[j]!=0)
			{
				if (arr[j] % arr[i] == 0)
				{
					arr[j] = 0;		//�ѷ������ڵ�
				}
				
			}
		}
	}

	printf("\n");

	for ( i = 2,n=0; i <= 100; i++)
	{
		if (arr[i] != 0)			//ѡ��ֵ��Ϊ0������Ԫ�أ�������
		{
			printf("%5d",arr[i]);	//������������Ϊ5��
			n++;					//�ۼƱ����Ѿ���������ݸ���
		}
		if (n==10)
		{
			printf("\n");
			n = 0;
		}
	}

	printf("\n");
}


