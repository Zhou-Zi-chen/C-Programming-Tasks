#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int matrix[100][100];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}

	bool flag1 = true;
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][i] == 0)
		{
			flag1 = false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (matrix[i][n - i - 1] == 0)
		{
			flag1 = false;
		}
	}
	for (int i = 0; i < n; i++)
	{
		int c = 0;
		while (c != i && c != (n - 1 - i) && c < n)
		{
			if (matrix[i][c] != 0)
			{
				flag1 = false;
			}
			c++;
		}
	}

	if (flag1 == true)
	{
		cout << "true";
	}
	else
	{
		cout << "false";
	}
	return 0;
}