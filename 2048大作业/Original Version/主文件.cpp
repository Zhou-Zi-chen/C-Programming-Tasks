#include<iostream>
#include "Menu.h"
#include "classicalversion.h"
#include "newversion.h"
using namespace std;

int main()
{
	Menu();//输出菜单
	cout << "请选择模式或退出游戏" << endl;
	int select;
	cin >> select;

	switch (select)//选择模式
	{
	case 1:
		system("cls");
		classical(); 
		break;
	case 2:
		system("cls");
		newversion();
		break;
	case 3:
		cout << "欢迎下次使用" << endl;
		return 0;
		break;
	default:break;
	}

	return 0;
}