#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(int argc, char* argv[]) 
{
	if (argc == 3) {
		cout << "你输入的命令行参数是：" << argv[1] << "和" << argv[2] << endl;
		cout << argv[1] << " + " << argv[2] << " = " << stoi(argv[1]) + stoi(argv[2]) << endl;
	}
	vector<string> words{ "Hello", "C++", "World", "!" };
	for (const auto& word : words) {
		cout << word << " ";
	}
	cout << endl;
	return 0;
}