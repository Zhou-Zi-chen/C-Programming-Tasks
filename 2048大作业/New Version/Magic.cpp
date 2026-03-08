#include "Magic.h"

void My_magic(int magnum, int arr[][4], int n)
{
	if (magnum == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 2)
				{
					arr[i][j] = 4;
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 4)
				{
					arr[i][j] = 2;
				}
			}
		}
	}
}