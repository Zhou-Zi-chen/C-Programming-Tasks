#include<iostream>
#include<cmath>
using namespace std;
#include<algorithm>

int cal1(char operation[], double num[], int n)
{
	double sum = num[0];
	for (int i = 0; i < 3; i++)
	{
		switch (operation[i])
		{
		case '+':sum += num[i+1]; break;
		case '-':sum -= num[i+1]; break;
		case '*':sum *= num[i+1]; break;
		case '/':sum /= num[i+1]; break;
		}
	}
	return sum;
}//((AB)C)D

int cal2(char operation[], double num[], int n)
{
	double sum = num[1];
	switch (operation[1])
	{
	case '+':sum += num[2]; break;
	case '-':sum -= num[2]; break;
	case '*':sum *= num[2]; break;
	case '/':sum /= num[2]; break;
	}
	switch (operation[0])
	{
	case '+':sum += num[0]; break;
	case '-':sum -= num[0]; break;
	case '*':sum *= num[0]; break;
	case '/':sum /= num[0]; break;
	}
	switch (operation[2])
	{
	case '+':sum += num[3]; break;
	case '-':sum -= num[3]; break;
	case '*':sum *= num[3]; break;
	case '/':sum /= num[3]; break;
	}
	return sum;
}//(A(BC))D

int cal3(char operation[], double num[], int n)
{
	double sum = num[1];
	switch (operation[1])
	{
	case '+':sum += num[2]; break;
	case '-':sum -= num[2]; break;
	case '*':sum *= num[2]; break;
	case '/':sum /= num[2]; break;
	}
	switch (operation[2])
	{
	case '+':sum += num[3]; break;
	case '-':sum -= num[3]; break;
	case '*':sum *= num[3]; break;
	case '/':sum /= num[3]; break;
	}
	switch (operation[0])
	{
	case '+':sum += num[0]; break;
	case '-':sum -= num[0]; break;
	case '*':sum *= num[0]; break;
	case '/':sum /= num[0]; break;
	}
	return sum;
}//A((BC)D)
int cal4(char operation[], double num[], int n)
{
	double sum = num[2];
	switch (operation[2])
	{
	case '+':sum += num[3]; break;
	case '-':sum -= num[3]; break;
	case '*':sum *= num[3]; break;
	case '/':sum /= num[3]; break;
	}
	switch (operation[1])
	{
	case '+':sum += num[1]; break;
	case '-':sum -= num[1]; break;
	case '*':sum *= num[1]; break;
	case '/':sum /= num[1]; break;
	}
	switch (operation[0])
	{
	case '+':sum += num[0]; break;
	case '-':sum -= num[0]; break;
	case '*':sum *= num[0]; break;
	case '/':sum = num[0]/sum; break;
	}
	return sum;
}//A(B(CD))
int cal5(char operation[], double num[], int n)
{
	double sum1 = num[0];
	double sum2 = num[2];
	double sum;
	switch (operation[0])
	{
	case '+':sum1+= num[1]; break;
	case '-':sum1 -= num[1]; break;
	case '*':sum1 *= num[1]; break;
	case '/':sum1 /= num[1]; break;
	}
	switch (operation[2])
	{
	case '+':sum2 += num[3]; break;
	case '-':sum2 -= num[3]; break;
	case '*':sum2 *= num[3]; break;
	case '/':sum2 /= num[3]; break;
	}
	switch (operation[1])
	{
	case '+':sum = sum1+sum2; break;
	case '-':sum = sum1 - sum2; break;
	case '*':sum = sum1 * sum2; break;
	case '/':sum = sum1 / sum2; break;
	}
	return sum;
}//(AB)(CD)

bool compare(double num[],int n)
{
	char operation[3];
	char swch[4] = { '+','-','*','/' };
	double res = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				operation[0] = swch[i];
				operation[1] = swch[j];
				operation[2] = swch[k];//ÅÅ³öÔËËã·û

				do
				{
					res = fabs(cal1(operation, num, 4));
					if (fabs(res - 24) < 1e-6)
					{
						return true;
					}
					res = fabs(cal2(operation, num, 4));
					if (fabs(res - 24) < 1e-6)
					{
						return true;
					}
					res = fabs(cal3(operation, num, 4));
					if (fabs(res - 24) < 1e-6)
					{
						return true;
					}
					res = fabs(cal4(operation, num, 4));
					if (fabs(res - 24) < 1e-6)
					{
						return true;
					}
					res = fabs(cal5(operation, num, 4));
					if (fabs(res - 24) < 1e-6)
					{
						return true;
					}
				} while (next_permutation(num, num + 4));
			}
		}
	}
	return false;
}

int main()
{
	double num[4];
	for (int i = 0; i < 4; i++)
	{
		cin >> num[i];
	}

	bool flag = false;
	flag = compare(num, 4);
	if (flag)
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}
	
	return 0;
}