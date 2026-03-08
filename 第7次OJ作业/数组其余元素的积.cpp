#include<iostream>
using namespace std;
int main()
{
	int nums[1000], answers[1000];
	int n=1;
	char ch;
	cin >> nums[0];
	for (n; n < 2001; n++)
	{
		ch = getchar();
		if (ch == '\n'||ch==EOF)
		{
			break;
		}
		cin >> nums[n];
	}
	if (n > 1)
	{
		
		for (int j = 0; j < n; j++)
		{
			int total = 1;
			for (int k = 0; k < n; k++)
			{
				if (k == j)
				{
					total *= 1;
				}
				else
				{
					total *= nums[k];
				}
			}
			answers[j] = total;
		}
	}
	if (n == 1)
	{
		answers[0] = 0;
	}
	for (int m = 0; m < n; m++)
	{
		cout << answers[m] << " ";
	}
	cout << endl;
	return 0;
}