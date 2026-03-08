#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
using namespace std;
//¶ÁÈ¡×Ö·û´®
void GetStrings(char* str_list, int N)
{
    for (int i = 0; i < N; i++)
    {
        cin >> str_list[i];
    }
    str_list[N] = '\0';
}
//ÅÐ¶Ï¶Ô³Æ×Ö·û´®£¬²¢Êä³ö
//Attention!! str_list[i] is forbidden!!
void Func(char* str_list,int N)
{
    int num = 0;
    for (int i = 0; i < N; i++)
    {
        bool Flag=true;
       
        char temp = str_list[N - 1];
        for (int j = N - 1; j >= 0; j--)
        {
            str_list[j] = str_list[j - 1];
        }
        str_list[0] = temp;


        for (int up = 0, down = N - 1; up < down; up++, down--)
        {
            if (str_list[up] != str_list[down])
            {
                num++;
                Flag = false;
                break;
            }
        }
        if (Flag == true)
        {
            for (int i = 0; i < N; i++)
            {
                cout << str_list[i] << ' ';
            }
            return;
        }
    }
    if (num == N)
    {
        cout << "False";
    }
}

int main()
{
    char* str_list = (char*)malloc(530 * sizeof(char));
    int N;
    cin >> N;
    GetStrings(str_list, N);
    Func(str_list, N);
    return 0;
}