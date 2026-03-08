#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

int length(char ch[])
{
	int length = 0;

	int i = 0;
	while (ch[i] != '\0')
	{
		i++;
		length++;
	}
	return length;
}

int main()
{
	string str;
	cin >> str;
	int len = str.size();
	char ch[3000];
	for (int i = 0; i < len; i++)
	{
		ch[i] = str[i];
	}
	ch[len] = '\0';
	int num_down = 0;
	for (int i = 0; i < len; i++)
	{
		if (ch[i] == ']')
		{
			num_down++;
		}
	}
	if (num_down == 0)
	{
		cout << ch;
	}
	else
	{
		for (int i = 0; i < num_down; i++)
		{
			len = length(ch);
			int num_up=1;
			for (int k = 0; k < len; k++)
			{
				if (ch[k] == '[' )
				{
					if (num_up == num_down - i)
					{
						int cru = k - 1;
						int xun = ch[cru] - '0';
						int u = 0;
						while ((ch[cru-1] -'0' <= 9) && (ch[cru - 1]-'0' >= 1))
						{
							cru--;
							u++;
							xun = (ch[cru] - '0') * pow(10, u) + xun;
						}
						char temp[500];
						int start=0;
						while (ch[k + 1] != ']')
						{
							temp[start] = ch[k + 1];
							start++;
							k++;
						}
						temp[start] = '\0';
						int mark = start;
						
						int len_temp = length(temp);
						for (int p = 0; p < xun-1; p++)
						{
							for (int q = 0; q < len_temp; q++)
							{
								temp[mark] = temp[q];
								mark++;
							}
						}
						temp[mark] = '\0';
						int res = cru + 3 + len_temp;
						int pace = len_temp * xun - len_temp - 3;
						if (pace >= 0)
						{
							for (int p = 0; p < len - res + 1; p++)
							{
								ch[len - p + pace-u] = ch[len - p];
							}
						}
						else
						{
							for (int p = 0; p < len - res + 1; p++)
							{
								ch[cru+len_temp*xun+p] = ch[res + p];
							}
							
						}
						
						for (int p = 0; p < xun * len_temp; p++)
						{
							ch[cru + p] = temp[p];
						}
						break;
					}
					else
					{
						num_up++;
					}
				}
			}
		}
		cout << ch;
	}
	return 0;
}