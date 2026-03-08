#include<iostream>
#include<cstring>
using namespace std;
int max(int m, int n)
{
	int p = (m > n) ? m : n;
	return p;
}
int main()
{
	int arr[201];
	int arr1[200], arr2[200];
	for (int q = 0; q < 200; q++)
	{
		arr1[q] = arr2[q] = 0;
	}
	for (int o = 0; o < 201; o++)
	{
		arr[o] = 0;
	}
	string str1, str2;
	cin >> str1;
	int m = str1.size();
	for (int i = 0; i < m; i++)
	{
		arr1[i] = str1[m - 1 - i] - 48;
	}
	cin >> str2;
	int n = str2.size();
	for (int i = 0; i < n; i++)
	{
		arr2[i] = str2[n - 1 - i] - 48;
	}
	
	int jw = 0;
	int p = max(m, n);
	for (int k = 0; k <= p; k++)
	{
		arr[k] = (arr1[k] + arr2[k] + jw) % 10;
		if ((arr1[k] + arr2[k]+jw) > 9)
		{
			jw = 1;
		}
		else
		{
			jw = 0;
		}
	}
	if (arr[p] != 0)
	{
		cout << arr[p];
	}
	for (int h = 0; h < p; h++)
	{
		cout << arr[p - h - 1];
	}
	return 0;
}