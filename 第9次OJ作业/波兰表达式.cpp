#include<iostream>
#include<string>

using namespace std;

int Notation()
{
	string process;
	cin >> process;
	if (process == "+")
	{
		return Notation() + Notation();
	}
	else if (process == "-")
	{
		return Notation() - Notation();
	}
	else if (process == "*")
	{
		return Notation() * Notation();
	}
	else if (process == "/")
	{
		return Notation() / Notation();
	}
	else
	{
		return stoi(process);
	}
}

int main()
{
	cout << Notation() << endl;

	return 0;
}