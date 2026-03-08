#include "cleaning.h"

void cleaner(int clean,int arr[][4],int n)
{
	if (clean == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (arr[i][j] == 2)
				{
					arr[i][j] = 0;
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
					arr[i][j] = 0;
				}
			}
		}
	}
}