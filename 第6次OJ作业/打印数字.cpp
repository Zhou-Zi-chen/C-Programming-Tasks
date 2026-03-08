#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	char str[101];
	for (int i = 0; i < n; i++)
	{
		cin >> str[i];
	}
	int arr[100];
	for (int i = 0; i < n; i++)
	{
		arr[i] = (int)str[i] - 48;
	}
	int m = 0;
	//第一行
	for (int p = 0; p < n; p++)
	{

		switch (arr[p])
		{
		case 0:cout << "XXX"; break;
		case 1:cout << "..X"; break;
		case 2:cout << "XXX"; break;
		case 3:cout << "XXX"; break;
		case 4:cout << "X.X"; break;
		case 5:cout << "XXX"; break;
		case 6:cout << "XXX"; break;
		case 7:cout << "XXX"; break;
		case 8:cout << "XXX"; break;
		case 9:cout << "XXX"; break;
		}
		if (m < n - 1)
		{
			cout << ".";
			m++;
		}
	}
	cout << endl;
	//第二行
	m = 0;
	for (int p = 0; p < n; p++)
	{
		switch (arr[p])
		{
		case 0:cout << "X.X"; break;
		case 1:cout << "..X"; break;
		case 2:cout << "..X"; break;
		case 3:cout << "..X"; break;
		case 4:cout << "X.X"; break;
		case 5:cout << "X.."; break;
		case 6:cout << "X.."; break;
		case 7:cout << "..X"; break;
		case 8:cout << "X.X"; break;
		case 9:cout << "X.X"; break;
		}
		if (m < n - 1)
		{
			cout << ".";
			m++;
		}

	}
	cout << endl;
	//第三行
	m = 0;
	for (int p = 0; p < n; p++)
	{

		switch (arr[p])
		{
		case 0:cout << "X.X"; break;
		case 1:cout << "..X"; break;
		case 2:cout << "XXX"; break;
		case 3:cout << "XXX"; break;
		case 4:cout << "XXX"; break;
		case 5:cout << "XXX"; break;
		case 6:cout << "XXX"; break;
		case 7:cout << "..X"; break;
		case 8:cout << "XXX"; break;
		case 9:cout << "XXX"; break;
		}
		if (m < n - 1)
		{
			cout << ".";
			m++;
		}

	}
	cout << endl;
	//第四行
	m = 0;
	for (int p = 0; p < n; p++)
	{
		switch (arr[p])
		{
		case 0:cout << "X.X"; break;
		case 1:cout << "..X"; break;
		case 2:cout << "X.."; break;
		case 3:cout << "..X"; break;
		case 4:cout << "..X"; break;
		case 5:cout << "..X"; break;
		case 6:cout << "X.X"; break;
		case 7:cout << "..X"; break;
		case 8:cout << "X.X"; break;
		case 9:cout << "..X"; break;
		}
		if (m < n - 1)
		{
			cout << ".";
			m++;
		}

	}
	cout << endl;
	//第五行
	m = 0;
	for (int p = 0; p < n; p++)
	{
		switch (arr[p])
		{
		case 0:cout << "XXX"; break;
		case 1:cout << "..X"; break;
		case 2:cout << "XXX"; break;
		case 3:cout << "XXX"; break;
		case 4:cout << "..X"; break;
		case 5:cout << "XXX"; break;
		case 6:cout << "XXX"; break;
		case 7:cout << "..X"; break;
		case 8:cout << "XXX"; break;
		case 9:cout << "XXX"; break;
		}
		if (m < n - 1)
		{
			cout << ".";
			m++;
		}

	}
	cout << endl;

	return 0;
}