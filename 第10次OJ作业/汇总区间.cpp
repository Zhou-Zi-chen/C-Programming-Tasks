#include <iostream>
using namespace std;

char ch[15];
char* trans(int num)
{
    int i = 0;
    if (num >= 0)
    {
        while (num > 9)
        {
            ch[i] = (char)(num % 10 + 48);
            num /= 10;
            i++;
        }
        ch[i] = (char)(num + 48);
        ch[i + 1] = '\0';
    }
    else if(num<0&&num!= -2147483648)
    {
        int num1 = -num;
        while (num1 > 9)
        {
            ch[i] = (char)(num1 % 10 + 48);
            num1 /= 10;
            i++;
        }
        ch[i] = (char)(num1 + 48);
        ch[i + 1] = '-';
        ch[i + 2] = '\0';
    }
    else
    {
        int num2 = 214748364;
        ch[i] = (char)(8 + 48);
        i++;
        while (num2 > 9)
        {
            ch[i] = (char)(num2 % 10 + 48);
            num2 /= 10;
            i++;
        }
        ch[i] = (char)(num2 + 48);
        ch[i + 1] = '-';
        ch[i + 2] = '\0';
    }
    return ch;
}

int mer(char* section, char* ch, int pos)
{
    int count = 0;
    int i = 0;
    while (ch[i] != '\0')
    {
        count++;
        i++;
    }
    for (int k = 0; k < count; k++)
    {
        section[pos] = ch[count - 1 - k];
        pos++;
    }
    return pos;
}

//输入数组，共有len个元素
//其中len为参数，在main函数中输入
void GetArray(int* arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        cin >> *(arr+i);
    }
}

// 根据输入的数组获得区间列表，存在字符串section中
//该字符串已在main函数中初始化完成
void getSectionList(int* arr, int len, char* section) 
{
    char* ch;
    int pos = 0;
    int i = 0;
    int up, down;
    int start, end;
    while (i < len)
    {
        up = down = arr[i];
        start = end = i;
        while (arr[i] + 1 == arr[i + 1])
        {
            down = arr[i + 1];
            i++;
            end++;
        }
        if (start < end)
        {
            ch = trans(arr[start]);
            pos = mer(section, ch, pos);
            section[pos] = '-';
            pos++;
            section[pos] = '>';
            pos++;
            ch = trans(arr[end]);
            pos = mer(section, ch, pos);
            section[pos] = ',';
            pos++;
        }
        else
        {
            ch = trans(arr[start]);
            pos = mer(section, ch, pos);
            *(section + pos) = ',';
            pos++;
        }
        i++;
    }
    *(section + pos-1) = '\0';
}

int main() {
    //输入元素的个数
    int len;
    cin >> len;
    int* arr = (int*)malloc(21 * sizeof(int));
    char* section_list = (char*)malloc(300 * sizeof(char));
    GetArray(arr, len);
    getSectionList(arr, len, section_list);
    cout << section_list;
    free(arr);
    free(section_list);
    return 0;
}
