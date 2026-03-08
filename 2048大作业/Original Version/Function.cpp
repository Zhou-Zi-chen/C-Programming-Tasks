#include "Function.h"
#include<iostream>
#include<cstdlib>
#include<ctime>

void show(int arr[][4], int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			std::cout << arr[i][j] << '\t';
		}
		std::cout << std::endl;
	}
}

int random()//0-3的随机数，用于随即定位数组中的某一个0元素
{
	srand(time(0));
	int res = rand() % 4;
	return res;
}

void appear(int arr[][4],int n)//在0位置随机出现2或4
{
	int row = 0, col = 0;
	do
	{
		row = random();
		col = random();
	} while (arr[row][col] != 0);
	srand(time(0));
	if (1 == rand()%3)
	{
		arr[row][col] = 4;
	}
	else
	{
		arr[row][col] = 2;
	}
}