#include<iostream>
using namespace std;


int main()
{
	int n, x = 0, y = 0, b = 0;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == -2)
		{
			b += 1;
			while (b < 0)
			{
				b += 4;
			}
			while (b > 3)
			{
				b -= 4;
			}
		}
		else if (a == -1)
		{
			b -= 1;
			while (b < 0)
			{
				b += 4;
			}
			while (b > 3)
			{
				b -= 4;
			}
		}
		else
		{
			switch (b)
			{
			case 0:y += a; break;
			case 1:x -= a; break;
			case 2:y -= a; break;
			case 3:x += a; break;
			default:break;
			}
		}
	}
	cout << "(" << x << "," << y << ")";

	return 0;
}