#include<iostream>
#include<iomanip>
using namespace std;
void time_min(int *a,int *b)
{
	while (*a >= 60)
	{
		*a -= 60;
		*b += 1;
	}
	while (*a <0)
	{
		*a += 60;
		*b -= 1;
	}
}
void time_hour(int* a)
{
	while (*a < 0)
	{
		*a += 24;
	}
	while (*a >= 24)
	{
		*a -= 24;
	}
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int n;
	cin >> n;
	if (n == 0)
	{
		cout << "The time is " << setw(2) << setfill('0') << a << ":" << setw(2) << setfill('0') << b << ":" << setw(2) << setfill('0') << c << endl;
	}
	else
	{
		int k, h, m;
		for (int i = 0; i < n; i++)
		{
			if (i >= 1)
			{
				c += 5;
				time_min(&c, &b);
			}
			
			cin >> k >> h >> m;
			if (k == 1)
			{
				a += h;
				b += m;
				time_min(&b, &a);
				time_hour(&a);
				cout << "So far the time is " << setw(2) << setfill('0') << a << ":" << setw(2) << setfill('0') << b << ":" << setw(2) << setfill('0') << c << endl;
			}
			if (k == 0)
			{
				a -= h;
				b -= m;
				time_min(&b, &a);
				time_hour(&a);
				cout << "So far the time is " << setw(2) << setfill('0') << a << ":" << setw(2) << setfill('0') << b << ":" << setw(2) << setfill('0') << c << endl;
			}
		}
	}
	return 0;
}