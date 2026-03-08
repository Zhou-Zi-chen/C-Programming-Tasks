#include<iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	if (n <= 0)
	{
		cout << "No";
	}
	else
	{
		while (n % 2 == 0)
		{
			n /= 2;
		}
		if (n == 1)
		{
			cout << "Yes";
		}
		else
		{
			while (n % 3 == 0)
			{
				n /= 3;
			}
			if (n == 1)
			{
				cout << "Yes";
			}
			else
			{
				while (n % 5 == 0)
				{
					n /= 5;
				}
				if (n == 1)
				{
					cout << "Yes";
				}

			}
		}
		if (n != 1)
		{
			cout << "No";
		}
	}

	return 0;
}