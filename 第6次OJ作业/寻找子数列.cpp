#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n, k;
	cin >> n >> k;
	int count = 0;
	int arr[100];
	int arr0[100];
	bool flag;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int j = 0; j < n - k; j++)
	{
		flag = true;
		for (int h = 0; h < k + 1; h++)
		{
			arr0[h] = pow(2, h) * arr[j + h];
		}
		for (int m = 0; m < k; m++)
		{
			if (arr0[m] >= arr0[m + 1])
			{
				flag = false;
			}
		}
		if (flag == true)
		{
			count++;
		}
	}
	cout << count << endl;

	return 0;
}