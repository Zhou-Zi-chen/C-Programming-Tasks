#include<iostream>
using namespace std;
#include<algorithm>
int main()
{
	int num[4] = { 0,1,2,3 };
	do
	{
		for (int i = 0; i < 4; i++)
		{
			cout << num[i];
		}
		cout << endl;
	} while (next_permutation(num , num + 4));
	return 0;
}