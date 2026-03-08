#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int i = 0;
int MIN(int a, int b)
{
	int min = (a < b) ? a : b;
	return min;
}
int MAX(int a, int b)
{
	int max = (a > b) ? a : b;
	return max;
}
//∂¡»° ‰»Îø®≈∆–Ú¡–
void GetCards(char* cards)
{
	while ((*(cards+i) = getchar()) != '\n')
	{
		i++;
	}
	cards[i] = '\0';
}
//≈≈–Ú
void SortCards(char* cards)
{
	bool flag = true;
	for (int j = 0; j < i - 1; j++)
	{
		int c = 0;
		for (int k = 0; k < i - j - 1; k++)
		{
			if (cards[k] > cards[k + 1])
			{
				char temp = cards[k];
				cards[k] = cards[k + 1];
				cards[k + 1] = temp;
				c++;
			}
		}
		if (c == 0)
		{
			break;
		}
	}//√∞≈›≈≈–Ú∞¥’’ASCIIÀ≥–Ú≈≈¡–
	int num2 = 0;
	int pos = 0;
	while (cards[pos] == '2')
	{
		num2++;
		pos++;
	}
	int up = pos, down = i - 1;
	while (up < down)
	{
		char temp1 = cards[up];
		cards[up] = cards[down];
		cards[down] = temp1;
		up++;
		down--;
	}
	int numT = 0, numA = 0, numQ = 0;
	int endT, endA, endQ;
	for (int k = 0; k < i; k++)
	{
		if (cards[k] == 'T')
		{
			numT++;
			endT = k;
		}
		
		else if (cards[k] == 'A')
		{
			numA++;
			endA = k;
		}
	}
	//ΩªªªA∫ÕT
	int numAT = MIN(numA, numT);
	for (int k = 0; k < numAT; k++)
	{
		char temp2 = cards[endT - k];
		cards[endT - k] = cards[endA - k];
		cards[endA - k] = temp2;
	}
	
		
	if (numT > numA)
	{
		int max = MAX(numT, numA);
		for (int k = 0; k < (max - numAT); k++)
		{
			char tempT;
			tempT = cards[endT - numAT - k];
			int we = endT - numAT - k;
			int ca = 0;
			while (cards[we] > 57)
			{
				cards[we] = cards[we + 1];
				we++;
				ca++;
			}
			cards[endT - k - 1 - numAT + ca] = tempT;
		}
	}
	
	if (numT < numA)
	{
		int max = MAX(numT, numA);
		for (int k = 0; k < (max - numAT); k++)
		{
			char tempA;
			tempA = cards[endA - numA  +1+ k];
			int we = endA - numA + k+1;
			int ca = 0;
			while (cards[we-1] != 'A'&&cards[we-1]!='2' && we - 1 >= 0)
			{
				cards[we] = cards[we - 1];
				we--;
				ca++;
			}
			cards[endA - numA  + k+1 - ca] = tempA;
		}
	}
	for (int k = 0; k < i; k++)
	{
		if (cards[k] == 'Q')
		{
			numQ++;
			endQ = k;
		}
	}
	
	for (int k = 0; k < numQ; k++)
	{
		char tempQ;
		tempQ = cards[endQ-k];
		int we = endQ - k + 1;
		int ca = 0;
		while (cards[we] == 'K')
		{
			cards[we - 1] = cards[we];
			we++;
			ca++;
		}
		cards[endQ + ca-k] = tempQ;
	}
}
// ‰≥ˆ≈≈–Ú∫Û–Ú¡–
void Output(char* cards)
{
	cout << cards;
}
int main()
{
	char* cards = (char*)malloc(130 * sizeof(char));
	GetCards(cards);
	SortCards(cards);
	Output(cards);
	free(cards);

	return 0;
}