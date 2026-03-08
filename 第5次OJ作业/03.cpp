#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	string str;
	cin >> str;
	int n = str.size();
	char arr[300];
	int k = 0;
	for (k = 0; k < n; k++)
	{
		arr[k] = str[k];
		int m = (int)str[k];
		for (int h = 0; h < k; h++)
		{
			int n = (int)str[h];
			if (m == n || m == n + 32 || m == n - 32)
			{
				if (m >= 97 && m <= 122)
				{
					cout << str[k];
				}
				else
				{
					m += 32;
					cout << (char)m;
				}
				goto L1;
			}
		}
	}
L1:;
	if (k == n)
	{
		cout << "None";
	}
	return 0;
}