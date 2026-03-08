#include<iostream>
using namespace std;

struct Stu
{
	int num;
	int Ch;
	int Math;
	int Eng;
	int sum;
};

int main()
{
	int n;
	cin >> n;
	Stu arr[50];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i].num;
		cin >> arr[i].Ch;
		cin >> arr[i].Math;
		cin >> arr[i].Eng;
		arr[i].sum = arr[i].Ch + arr[i].Math + arr[i].Eng;
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j].sum < arr[j + 1].sum)
			{
				Stu temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j].sum == arr[j + 1].sum)
			{
				if (arr[j].Math < arr[j + 1].Math)
				{
					Stu temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
				
			}
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if ((arr[j].sum == arr[j + 1].sum)&&(arr[j].Math==arr[j+1].Math))
			{
				if (arr[j].num > arr[j + 1].num)
				{
					Stu temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}

			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		cout << arr[i].num << " " << arr[i].Ch << " " << arr[i].Math << " " << arr[i].Eng <<" " << arr[i].sum << endl;
	}

	return 0;
}