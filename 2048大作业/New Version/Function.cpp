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
	int num = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0)
			{
				num++;
			}
		}
	}
	srand(time(0));
	int res = rand() % num;
	int numpos = -1;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] == 0)
			{
				numpos++;
				
				if(numpos==res)
				{
					if (1 == rand() % 3)
					{
						arr[i][j] = 4;
						break;
					}
					else
					{
						arr[i][j] = 2;
						break;
					}
				}
			}
		}
	}


	
}