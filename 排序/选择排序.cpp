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
	for (int i = 0; i < N-1 ; i++)
	{
		int pivot = 0;
		for (int j = 0; j < N-i-1 ; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				pivot = j + 1;
			}
		}
		int temp = arr[N -1 - i];
		arr[N - 1 - i] = arr[pivot];
		arr[pivot] = temp;
	}
	for (int k = 0; k < N; k++)
	{
		cout << arr[k] << " ";
	}
	return 0;
}