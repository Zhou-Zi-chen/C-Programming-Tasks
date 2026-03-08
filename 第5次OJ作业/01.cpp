#include<iostream>
using namespace std;
int main()
{
	int key;
	char c;
	cin >> key ;
	c=getchar();
	char ch;
	while ((ch = getchar()) != EOF)
	{
		if ((int)ch != 32)
		{
			int a = (int)ch;
			a += key;
			cout << (char)a;
		}
		if ((int)ch == 32)
		{
			cout << " ";
		}
	}
	return 0;
}