#include<iostream>
using namespace std;

int fib(int n)
{
	int sum = fib(n - 1) + fib(n - 2);
	return sum;
}

int main()
{
	int n;
	cout << "请输入n的值：";
	cin >> n;
	cout << "第" << n << "个斐波那契数是：" << fib(n) << endl;
	return 0;
}