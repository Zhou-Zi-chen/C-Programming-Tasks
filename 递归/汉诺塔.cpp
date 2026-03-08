#include<iostream>
using namespace std;

void Hanoi(int n, char A,char B,char C)//n个盘子，起始位置，中转位置，结束位置
{
	if (n == 1)
	{
		cout << "将圆盘" << n << "从" << A << "移动到" << C << endl;
	}
	else
	{
		Hanoi(n - 1, A, C, B);
		cout << "将圆盘" << n << "从" << A << "移动到" << C << endl;
		Hanoi(n - 1, B, A, C);
	}
}

int main()
{
	int n;
	cout << "请输入圆盘的个数：";
	cin >> n;
	Hanoi(n, 'A', 'B', 'C');

	return 0;
}