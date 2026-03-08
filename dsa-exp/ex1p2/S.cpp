#include "SqList.h"
#include "../dsa-exp/dsaUtils.h"
int main()
{
    // 定义并初始化一个int类型的SequencedList  
    SequencedList<int> myList;

    // 使用push_back添加元素  
    myList.push_back(10);
    myList.push_back(20);
    myList.push_back(30);

    // 使用insert在指定位置插入元素  
    myList.insert(1, 15); // 在索引1的位置插入元素15  

    // 检查元素是否被正确插入  
    std::cout << "List elements: ";
    for (size_t i = 0; i < myList.size(); ++i)
    {
        std::cout << myList.at(i) << " ";
    }
    std::cout << std::endl;

    // 基本的性质检查，与std::vector对比  
    std::vector<int> stdList = { 10, 15, 20, 30 };
    if (myList.size() == stdList.size())
    {
        std::cout << "The size of both lists is the same." << std::endl;
        bool listsAreEqual = true;
        for (size_t i = 0; i < myList.size(); ++i)
        {
            if (myList.at(i) != stdList[i]) 
            {
                listsAreEqual = false;
                break;
            }
        }
        if (listsAreEqual)
        {
            std::cout << "The elements in both lists are the same." << std::endl;
        }
        else
        {
            std::cout << "The elements in both lists are different." << std::endl;
        }
    }
    else
    {
        std::cout << "The size of the lists is different." << std::endl;
    }

    return 0;
}