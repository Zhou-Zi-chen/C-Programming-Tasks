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
	//读取str1,str2
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
	//判断str1,str2的大小关系
	bool flag = true;
	bool flag1 = false;
	int flag2 = 0;
	if (m > n)
	{
		flag = true;
		for (int i = 0; i < n; i++)
		{
			arr2[i] = (-arr2[i]);
		}
	}
	else if(m<n)
	{
		flag = false;
		for (int q = 0; q < 200; q++)
		{
			arr1[q] = (-arr1[q]);
		}
	}
	//m=n
	else
	{
		for (int i = 0; i < m; i++)
		{
			if (arr1[m - 1 - i] < arr2[n - 1 - i])
			{
				flag = false;
				break;
			}
			else if (arr1[m - 1 - i] == arr2[n - 1 - i])
			{
				flag2++;
			}
			else
			{
				flag = true;
				break;
			}
		}
		


		if (flag2 == m )
		{
			flag1 = true;
		}

		if (flag == true)
		{
			for (int i = 0; i < n; i++)
			{
				arr2[i] = (-arr2[i]);
			}
		}
		else
		{
			for (int q = 0; q < 200; q++)
			{
				arr1[q] = (-arr1[q]);
			}
		}
	}
	

	int p = max(m, n);
	//str1>str2
	if (flag == true&&flag1==false)
	{
		int r = 0;
		while (r < p)
		{
			if (arr1[r] + arr2[r] >= 0)
			{
				arr[r] = arr1[r] + arr2[r];
			}
			else
			{
				arr[r] = arr1[r] + 10 + arr2[r];
				arr1[r + 1] -= 1;
			}
			r++;
		}

		int i = 0;
		for (i; i < p; i++)
		{
			if (arr[p - i - 1] != 0)
			{
				break;
			}
		}
		for (int j = 0; j < p - i; j++)
		{
			cout << arr[p - 1 - j - i];
		}
	}
	//str1<str2
	else if(flag == false && flag1 == false)
	{
		int r = 0;
		while (r < p)
		{
			if (arr2[r] + arr1[r] >= 0)
			{
				arr[r] = arr2[r] + arr1[r];
			}
			else
			{
				arr[r] = arr2[r] + 10 + arr1[r];
				arr2[r + 1] -= 1;
			}
			r++;
		}

		cout << "-";
		int i = 0;
		for (i; i < p; i++)
		{
			if (arr[p - i - 1] != 0)
			{
				break;
			}
		}
		for (int j = 0; j < p - i; j++)
		{
			cout << arr[p - 1 - j - i];
		}
	}
	//str1=str2
	else
	{
		cout << "0";
	}
	return 0;
}