#include<iostream>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int arr[300];
	int arr1[300];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	int k;
	cin >> k;
	for (int j = 0; j < n; j++)
	{
		int m = (j + k) % n;
		arr1[m] = arr[j];
	}
	for (int j = 0; j < n; j++)
	{
		cout << arr1[j] << " ";
	}
	return 0;
}