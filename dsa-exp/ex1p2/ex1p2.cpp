#include <algorithm>
#include "D:\南大\程设\程序项目\dsa-exp\dsa-exp/dsaUtils.h" 
using namespace std;
int main() 
{
	const int CNT = 20;
	int a[CNT];
	// RandomizeData(a, CNT, 1, -99, 100);
	RandomizeData(a, CNT,1,-99,100); //自定义函数：相对独立的一段功能代码，便于多处调用。
	Show(a, a + CNT); //自定义函数（模板）：函数模板：泛型函数
	cout << "数组排序后：";
	sort(a, a + CNT);
	Show(a, a + CNT);
	cout << "数组按绝对值排序后：";
	sort(a, a + CNT, [](int x, int y) {return abs(x) < abs(y); });
	// 用Lambda表达式 定义一个匿名函数，以表达特定的条件
	Show(a, a + CNT);
	return 0;
}