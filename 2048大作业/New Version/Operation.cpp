#include "Operation.h"

void Wyi(int arr[][4], int n,int *sp)//上移操作
{
	(*sp)--;//操作一次分数-1
	for (int j = 0; j < 4; j++)//逐列操作
	{
		int w = 0;
		for (int i = 0; i < 4; i++)
		{
			if (arr[i][j] != 0)//如果前面是0就往上移动
			{
				arr[w][j] = arr[i][j];
				if (w != i)
				{
					arr[i][j] = 0;
				}
				w++;
			}
		}
		
		for (int i = 0; i < 3; i++)//同一行中相同数字相加
		{
			if (arr[i][j] == arr[i + 1][j])
			{
				*sp += arr[i][j];
				arr[i][j] = arr[i][j] + arr[i + 1][j];
				int k = i+1;
				while(k<3)//整体上移
				{
					arr[k][j] = arr[k + 1][j];
					k++;
				}
				arr[3][j] = 0;//相加一次在最下面补一个0
			}
		}

	}
}

void Ayi(int arr[][4], int n, int *sp)//左移操作
{
	(*sp)--;
	for (int i = 0; i < 4; i++)
	{
		int w = 0;
		for (int j = 0; j < 4; j++)
		{
			if (arr[i][j] != 0)
			{
				arr[i][w] = arr[i][j];
				if (w != j)
				{
					arr[i][j] = 0;
				}
				w++;
			}
		}
		
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] == arr[i][j + 1])
			{
				*sp += arr[i][j];
				arr[i][j] = arr[i][j] + arr[i][j + 1];
				int k = j + 1;
				while (k < 3)
				{
					arr[i][k] = arr[i][k+1];
					k++;
				}
				arr[i][3] = 0;
			}
		}	
	}
}

void Dyi(int arr[][4], int n, int* sp)//右移操作
{
	(*sp)--;
	for (int i = 0; i < 4; i++)
	{
		int w = 3;
		for (int j = 3; j >=0 ; j--)
		{
			if (arr[i][j] != 0)
			{
				arr[i][w] = arr[i][j];
				if (w != j)
				{
					arr[i][j] = 0;
				}
				w--;
			}
		}

		for (int j = 3; j >= 1; j--)
		{
			if (arr[i][j] == arr[i][j - 1])
			{
				*sp += arr[i][j];
				arr[i][j] = arr[i][j] + arr[i][j - 1];
				int k = j - 1;
				while (k > 0)
				{
					arr[i][k] = arr[i][k - 1];
					k--;
				}
				arr[i][0] = 0;
			}
		}
	}
}
void Syi(int arr[][4], int n, int* sp)//下移操作
{
	(*sp)--;
	for (int j = 0; j < 4; j++)
	{
		int w = 3;
		for (int i = 3; i >=0; i--)
		{
			if (arr[i][j] != 0)
			{
				arr[w][j] = arr[i][j];
				if (w != i)
				{
					arr[i][j] = 0;
				}
				w--;
			}
		}

		for (int i = 3; i >=1; i--)
		{
			if (arr[i][j] == arr[i - 1][j])
			{
				*sp += arr[i][j];
				arr[i][j] = arr[i][j] + arr[i - 1][j];
				int k = i - 1;
				while (k > 0)
				{
					arr[k][j] = arr[k - 1][j];
					k--;
				}
				arr[0][j] = 0;
			}
		}

	}
}