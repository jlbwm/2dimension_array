#include <stdio.h>


void d1_value(int array[], int num)
{
		for(int i = 0; i< num; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
}

void d1_point(int *array, int num)
{
		for(int i = 0; i< num; i++)
		{
			printf("%d ", array[i]);
		}
		printf("\n");
}


void d2_pointarray(int* a[], int row, int column) 
{
	//指针的数组,有多个一维数组，每个一维数组有一个指向头的指针，存储在一个数组中 a[]存的是若干个指针
	for(int i = 0; i< row; i++)
	{
		for(int j = 0; j< column; j++)
		{
			printf("%d ", a[i][j]); 
		}
		printf("\n");
	}
}

void d2_arraypoint(int (*p)[3], int row) //a[3]
{
	//int (*p)[3] 一维数组的指针，此数组有3个元素 
	//传入a,a是二维数组a[][]的指针
	//p = a
	for(int i = 0; i< row; i++)
	{
		for(int j = 0; j< 3; j++)
		{
			printf("%d ", p[i][j]); 
		}
		printf("\n");
	}
}


void d2_2dpointer(int** a, int row, int column) 
{
	//二维指针，*a指向每一行，*（*a）指向每一列
	for(int i = 0; i< row; i++)
	{
		for(int j = 0; j< column; j++)
		{
			printf("%d ", *( (int *)a + column*i + j) ); //手动找地址 (int *)a 二维数组内存头
		}
		printf("\n");
	}
}




int main(int argc, char const *argv[])
{
	int a[][3] = {	
					{1, 2, 3},
					{4, 5, 6}
				};

	int b[] = {1, 2, 3};

	d1_value(b, 3);
	printf("\n");

	d1_point(b, 3);
	printf("\n");


	d2_2dpointer((int **)a, 2, 3);
	printf("\n");

	
	{
		int* pa[2]; //数组，存储指针
		for(int i = 0; i< 2; i++)
		{
			pa[i] = a[i];
		}
		d2_pointarray(pa, 2, 3);
		printf("\n");
	}
	
	
	d2_arraypoint(a ,2);

	
	return 0;
}
