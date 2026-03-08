#include<iostream>
#include<cmath>
using namespace std;

int sum = 0;

int jiecheng(int x)
{
	if (x == 0)
	{
		return 1;
	}
	else
	{
		long int b = 1;
		for (int i = 1; i <= x; i++)
		{
			b *= i;
		}
		return b;
	}
}


int main()
{
	int N;
	cin >> N;
	
	int sum = 0;
	if (N % 2 == 0)
	{
		for (int i = 0; i <= N / 2; i++)
		{
			sum += pow(2, i) * jiecheng(N - i) / (jiecheng(i) * jiecheng(N - 2 * i));
		}
	}
	else
	{
		for (int i = 0; i < (N + 1) / 2; i++)
		{
			sum += pow(2, i) * jiecheng(N-i) / (jiecheng(i) * jiecheng(N-2*i));
		}
	}
	
	cout << sum;
	return 0;
}