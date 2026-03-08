#include<iostream>
using namespace std;

int zho(int n)
{
	int sum;
	if (n == 1)
	{
		sum = 1;
		return sum;
	}
	else if (n == 2)
	{
		sum = 3;
		return sum;
	}
	else
	{
		sum = zho(n - 1) + 2 * zho(n - 2);
	}
	return sum;
}

int main()
{
	int N;
	cin >> N;
	cout << zho(N);
}