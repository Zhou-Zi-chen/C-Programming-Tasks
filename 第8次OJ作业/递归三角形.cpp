#include<iostream>
#include<cmath>
using namespace std;
char A[80][80];
void shu(int n)
{
	if (n == 1)
	{
		A[0][0] = '*';
	}
	else
	{
		shu(n - 1);
		int m = pow(2, n - 2);
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < m; j++)
			{
				A[i + m][j] = A[i][j + m] = A[i][j];
			}
		}
	}
}
int main()
{
	int n;
	cin >> n;
	shu(n);
	int a = pow(2, n - 1);
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < a; j++)
		{
			if (A[i][j] == '*')
			{
				cout << A[i][j] << " ";
			}
			else
			{
				cout << " " << " ";
			}
		}
		cout << endl;
	}
	return 0;
}