#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n, m, k;
	cin >> n;
	if (n == 0)
	{
		cout << "0";
	}
	else
	{
		if (n < 0)
		{
			cout << "-";
		}
		k = fabs(n);
		while ((k % 10) == 0)
		{
			k /= 10;
		}
		do
		{
			m = k % 10;
			k /= 10;
			cout << m;
		} while (k > 9);
		if (k != 0)
		{
			cout << k;

		}
	}


	return 0;
}