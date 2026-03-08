#include<iostream>
using namespace std;

int path(int n)
{
	int sum ;
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 1;
	}
	else if (n == 3)
	{
		return 2;
	}
	
	else
	{
		if (n % 2 == 0)
		{
			sum = path(n - 1) + path(n - 2) + path(n - 3);
		}
		if (n % 2 == 1)
		{
			sum = path(n - 1) + path(n - 2);
		}
	}
	return sum;
	
}

int main()
{
	int n;
	cout << "请输入结点：";
	cin >> n;
	while (n <= 1)
	{
		cout << "n需要大于1，请重新输入：";
		cin >> n;
	}
	cout << "路径数是：" << path(n) << endl;
	return 0;
}