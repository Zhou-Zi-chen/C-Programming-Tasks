#include<iostream>
using namespace std;

int num(int x)
{
	int sum = 0;
	if (x == 1 || x == 2 || x == 3)
	{
		sum = 1;
		return sum;
	}
	else
	{
		sum = num(x - 1) + num(x - 3);
		return sum;
	}
}

int main()
{
	int x;
	cin >> x;
	cout << num(x);
	return 0;
}