#include<iostream>
using namespace std;
#define N 9
int main()
{
	int arr[N];
	cout << "请输入" << N << "个不同的数" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	bool flag = true;
	for (int i = 0; i < N -1 ; i++)
	{
		int c = 0;
		for (int j = 0; j < N - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				c++;
			}
		}
		if (c == 0)
		{
			break;
		}
	}
	for (int k = 0; k < N ; k++)
	{
		cout << arr[k] << " ";
	}
	return 0;
}