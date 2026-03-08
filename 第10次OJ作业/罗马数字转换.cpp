#include <iostream>
using namespace std;
int i = 0;
//以字符串形式输入罗马数字

int trans(char ch) 
{
    int num = 0;
    switch (ch)
    {
    case 'I':num = 1; break;
    case 'V':num = 5; break;
    case 'X':num = 10; break;
    case 'L':num = 50; break;
    case 'C':num = 100; break;
    case 'D':num = 500; break;
    case 'M':num = 1000; break;
    default:break;
    }
    return num;
}


void GetStrings(char* str)
{
    
    while ((str[i] = getchar()) != '\n')
    {
        i++;
    }
    str[i] = '\0';
}

//将传入的罗马数字字符串转换为整数
int romanToNum(char* str) 
{
    int num = 0;
    for (int j = 0; j < i; j++)
    {
        if (str[j] == 'I' || str[j] == 'X' || str[j] == 'C')
        {
            switch (str[j])
            {
            case 'I':
                if (str[j + 1] == 'V' || str[j + 1] == 'X')
                {
                    num += trans(str[j + 1]) - trans(str[j]);
                    j++;
                }
                else
                {
                    num += trans(str[j]);
                }; break;
            case 'X':
                if (str[j + 1] == 'L' || str[j + 1] == 'C')
                {
                    num += trans(str[j + 1]) - trans(str[j]);
                    j++;
                }
                else
                {
                    num += trans(str[j]);
                }; break;
            case 'C':
                if (str[j + 1] == 'D' || str[j + 1] == 'M')
                {
                    num += trans(str[j + 1]) - trans(str[j]);
                    j++;
                }
                else
                {
                    num += trans(str[j]);
                }; break;
            }
        }
        else
        {
            num += trans(str[j]);
        }
    }
    return num;
}

int main() {
    char* roman_string = (char*)malloc(16 * sizeof(char));
    GetStrings(roman_string);
    
    int num = romanToNum(roman_string);
    cout << num;
    free(roman_string);
    return 0;
}