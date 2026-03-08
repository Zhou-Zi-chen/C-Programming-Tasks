#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct TicketNode
{
    //ToDo
    string name;// 订票人的名字，不超过20个字符，中间不带空格
    int price = 0;// 车票的价格
    TicketNode* next;// 指向下一个车票的指针
} TicketNode;

/*YOU CAN ADD ANY FUNCTIONS IF YOU WANT*/

void ticketSys(int n, TicketNode* head) {
    string dec;
    for (int i = 0; i < n; i++)
    {
        cin >> dec;
        if (dec == "SALE")
        {
            TicketNode* p = new TicketNode;
            cin >> p->name;
            cin >> p->price;
            p->next = NULL;
            if (head == NULL)//如果链表为空
            {
                head = p;
            }
            else
            {
                TicketNode* prew = head;
                TicketNode* cur = head;
                while ((cur->next != NULL) && (cur->price < p->price))
                {
                    cur = cur->next;
                }//寻找插入位置
                if (cur->next == NULL)//如果现在CUR在最后一个节点
                {
                    if (cur->price < p->price)//把p插在最后
                    {
                        cur->next = p;
                    }
                    else//把p插在cur前
                    {
                        if (cur != head)//如果不是头结点
                        {
                            while (prew->next != cur)
                            {
                                prew = prew->next;
                            }
                            p->next = cur;
                            prew->next = p;
                        }
                        else//如果是头结点
                        {
                            p->next = head;
                            head = p;
                        }
                    }

                }
                else//如果cur不是最后一个节点
                {
                    if (cur != head)
                    {
                        while (prew->next != cur)
                        {
                            prew = prew->next;
                        }
                        p->next = cur;
                        prew->next = p;
                    }
                    else
                    {
                        p->next = head;
                        head = p;
                    }
                }
            }
        }
        else if (dec == "REFUND")
        {
            string name;
            cin >> name;
            TicketNode* cur = head;
            while ((cur->next != NULL) && (cur->name != name))
            {
                cur = cur->next;
            }

            TicketNode* pre = head;
            if (cur == head)
            {
                head = cur->next;
                delete cur;
            }
            else if (cur->next != NULL)
            {
                while (pre->next != cur)
                {
                    pre = pre->next;
                }
                pre->next = cur->next;
                delete cur;
            }
            else
            {
                while (pre->next != cur)
                {
                    pre = pre->next;
                }
                pre->next = NULL;
                delete cur;
            }
        }
        else if (dec == "DISPLAY")
        {
            TicketNode* cur = head;
            if (head == NULL)
            {
                continue;
            }
            while (cur->next != NULL)
            {
                cout << cur->name << " ";
                cout << cur->price << endl;
                cur = cur->next;
            }
            cout << cur->name << " ";
            cout << cur->price << endl;
            cout << endl;
        }
        else
        {
            i--;
            continue;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    TicketNode* head = NULL;
    ticketSys(n, head);
    return 0;
}