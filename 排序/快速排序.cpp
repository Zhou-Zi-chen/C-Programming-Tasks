#include<iostream>
using namespace std;
#define N 9

int split(int arr[], int first, int last)
{
	int split_point, pivot;
	pivot = arr[first];
	split_point = first;
	for (int unknown = first + 1; unknown <= last; unknown++)
	{
		if (arr[unknown] < pivot)
		{
			split_point++;
			//交换arr[split_point]和arr[unknown]的值
			int temp = arr[split_point];
			arr[split_point] = arr[unknown];
			arr[unknown] = temp;
		}
	}
	//交换arr[first]和arr[split_point]的值
	arr[first] = arr[split_point];
	arr[split_point] = pivot;
	return split_point;
}

void quick_sort(int arr[], int first, int last)
{
	if (first < last)
	{
		int split_point;
		split_point = split(arr, first, last);
		quick_sort(arr, first, split_point - 1);
		quick_sort(arr, split_point + 1, last);
	}
}

int main()
{
	int arr[N];
	cout << "请输入" << N << "个不同的数" << endl;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	quick_sort(arr, 0, N - 1);
	for (int k = 0; k < N; k++)
	{
		cout << arr[k] << " ";
	}

	return 0;
}