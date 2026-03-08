#include "classicalversion.h"
#include "core.h"
#include "Function.h"
#include<iostream>
using namespace std;

void classical()
{
	int row = 0, col = 0;
	int arr[4][4];
	int score = 0;
	int* sp = &score;//分数
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			arr[i][j] = 0;
		}
	}//对4*4数组的初始化

	cout << "规则如下：" << endl;
	cout << "上：W" << "	" << "下：S" << "	" << "左：A" << "	" << "右：D" << endl;
	cout << "注意！！中途输入‘W’、‘A’、‘S’、‘D’以外的键会直接退出程序" << endl;
	cout << "输入‘Y’开始游戏，输入其他键则退出游戏" << endl;

	char enter;
	cin >> enter;
	if (enter == 'Y')
	{
		system("cls");
		do
		{
			row = random();
		} while (row != 0 && row != 3);
		do
		{
			col = random();
		} while (col != 0 && col != 3);
		arr[row][col] = 2;//在四个角中的一个地方随机出现2
		do
		{
			row = random();
			col = random();
		} while (arr[row][col] == 2);
		arr[row][col] = 2;//游戏的初始化

		show(arr, 4);
		cout << "The score is:" << *sp << endl;
		char c;
		cout << "请输入操作：";
		cin >> c;
		while (c == 'W' || c == 'A' || c == 'S' || c == 'D')
		{
			system("cls");
			core(c, arr, sp);
			show(arr, 4);
			cout << "The score is:" << *sp << endl;
			//判断是否得出了2048
			bool Flag1 = false;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (arr[i][j] == 2048)
					{
						Flag1 = true;
						break;
					}
				}
			}
			if (Flag1 == true)
			{
				cout << "恭喜您成功了！" << endl;
				return;
			}
			//判断是否4*4已经填满
			bool Flag2 = true;
			for (int i = 0; i < 4; i++)
			{
				for (int j = 0; j < 4; j++)
				{
					if (arr[i][j] == 0)
					{
						Flag2 = false;
						break;
					}
				}
			}
			if (Flag2 == true)
			{
				cout << "很遗憾失败了！" << endl;
				return;
			}
			cout << "请输入操作：";
			cin >> c;
		}
	}
	else
	{
		return;
	}
}