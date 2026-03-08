#include<iostream>
using namespace std;
int main()
{
	int m, n;
	cin >> m >> n;
	char ch[100][100];
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> ch[i][j];
		}
	}
	int sum = 0;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n - 2; j++)
		{
			if ((ch[i][j] == 'N' && ch[i][j + 1] == 'J' && ch[i][j + 2] == 'U') || (ch[i][j] == 'U' && ch[i][j + 1] == 'J' && ch[i][j + 2] == 'N'))
			{
				sum++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m - 2; j++)
		{
			if ((ch[j][i] == 'N' && ch[j+1][i] == 'J' && ch[j+2][i] == 'U') || (ch[j][i] == 'U' && ch[j+1][i] == 'J' && ch[j+2][i] == 'N'))
			{
				sum++;
			}
		}
	}
	cout << sum;
	return 0;
}