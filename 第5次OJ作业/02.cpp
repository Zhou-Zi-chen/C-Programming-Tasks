#include<iostream>
using namespace std;

struct fenshu
{
	int fz;
	int fm;
};
int gys(int m, int n)
{
	int x, ys = 1;
	x = (m > n) ? n : m;
	for (int i = 2; i <= x; i++)
	{
		if (m % i == 0 && n % i == 0)
		{
			ys = i;
		}
	}
	return ys;
}

int main()
{
	char m;
	struct fenshu a1, a2;
	cin >> a1.fz >> m >> a1.fm >> a2.fz >> m >> a2.fm;
	if (a1.fm == a2.fm)
	{
		int fm = a1.fm;
		int fz = a1.fz + a2.fz;
		int h = gys(fm, fz);
		fm /= h;
		fz /= h;
		if (fm == 1)
		{
			cout << fz;
		}
		else
		{
			cout << fz << "/" << fm;
		}
	}
	else
	{
		int fm = a1.fm * a2.fm;
		a1.fz = a1.fz * a2.fm;
		a2.fz = a2.fz * a1.fm;
		int fz = a1.fz + a2.fz;
		int h = gys(fm, fz);
		fm /= h;
		fz /= h;
		if (fm == 1)
		{
			cout << fz;
		}
		else
		{
			cout << fz << "/" << fm;
		}
	}
	return 0;
}