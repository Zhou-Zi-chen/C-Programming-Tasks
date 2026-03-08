#include <iostream>
#include <vector>
using namespace std;
void RandomizeData(int* a, int cnt, unsigned int seed , int minValue, int maxValue );
template <typename IIt> void Show(IIt first, IIt last); // C++样式接口
// 模板函数的定义都放在头文件中

template <typename IIt>
void Show(IIt first, IIt last) 
{
	while (first != last) 
	{
		cout << *first << " ";
		first++;
	}
	cout << endl;
}