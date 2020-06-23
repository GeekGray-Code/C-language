#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

#include"chapter4_sequential_structure.h"



/*chapter4 ˳��ṹ ���Ժ���*/
void chapter4SequentialStructureTest()
{
	//calcTriangleArea();
	//calcCaseConversion();
	//calcRootOfEquation();
	//calcCircleArea();
}

/*�����������*/
void calcTriangleArea()
{
	float side,side1, side2, side3, area;						//�������߱������������

	printf("���������������ߣ���ʽ���߳�1���߳�2���߳�3��\n");
	scanf("%f,%f,%f",&side1,&side2,&side3);

	side = (side1+side2+side3) / 2;								//���߹�ϵ
	area = sqrt(side*(side-side1*(side-side2)*(side-side3)));	//�����ϵ,sqrt:��ƽ��������

	printf("side1=%7.2f\nside2=%7.2f\nside3=%7.2f\nside=%7.2f\narea=%7.2f\n",side1,side2,side3,side,area);
}


/*��Сдת��*/
void calcCaseConversion()
{
	char c1, c2;

	c1 = getchar();
	printf("%c,%d\n",c1,c1);

	c2 = c1 + 32;
	printf("%c,%d\n",c2,c2);
}


/*��һԪ���η��̵ĸ�*/
void calcRootOfEquation()
{
	float a, b, c, disc, x1, x2, p, q;	//ϵ���������Գ���

	printf("������һԪ���η��̵�3��ϵ������ʽ��a��b��c��\n");
	scanf("%f,%f,%f",&a,&b,&c);

	disc = b*b - 4 * a*c;				//�б�ʽ
	p = -b / (2 * a);					//�Գ���
	q = sqrt(disc)/(2*a);

	if (q>=0)
	{
		x1 = (p+q);
		x2 = p - q;

		printf("���̣�%fx^2+%fx+%f �Ľ�Ϊ\n",a,b,c);
		printf("x1= %f\nx2= %f",x1,x2);
	}
	else
	{
		printf("�÷�����һ�Թ������\n");
	}
}


/*��Բ���������ز���*/
void calcCircleArea()
{
	float r = 1.5;				//Բ�뾶
	float h = 3;				//Բ����ĸ�
	float circlePerimeter;		//Բ�ܳ�
	float circleArea;			//Բ���
	float sphereSurfaceArea;	//Բ������
	float sphereVolume;			//�������
	float cylinderVolume;		//Բ�������

	circlePerimeter = 2 * PI*r;
	circleArea = PI*r*r;
	sphereSurfaceArea = 4 * PI*r*r;
	sphereVolume = 4 * PI*r*r*r;
	cylinderVolume = PI*r*r*h;

	printf("Բ�뾶��%f\n",r);
	printf("Բ����ĸߣ�%f\n", h);
	printf("Բ�ܳ���%f\n", circlePerimeter);
	printf("Բ�����%f\n", circleArea);
	printf("Բ��������%f\n", sphereSurfaceArea);
	printf("���������%f\n", sphereVolume);
	printf("Բ���������%f\n", cylinderVolume);
}