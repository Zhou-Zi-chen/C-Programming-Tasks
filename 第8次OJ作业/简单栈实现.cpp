#include<iostream>
#include<cstring>
using namespace std;
#define N 20
int in = N, out = N;
int stuck[N];


void push(int value)
{
	in--;
	if (in < 0)
	{
		cout << "Stack full, cannot push." << endl;
	}
	else
	{
		stuck[in] = value;
		out = in;
	}
	
}

int pop()
{
	in++;
	return stuck[out];
}

int main()
{
	int n;
	string str;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> str;
		if (str[1] == 'u')
		{
		
			int x;
			cin >> x;
			push(x);
		}
		else
		{
			if (out < N)
			{
				cout << pop() << endl;
				out++;
			}
			else
			{
				cout << "Stack empty, cannot pop." << endl;
			}
		}
	}
	return 0;
}