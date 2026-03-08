#include <iostream>
using namespace std;

int Max(int i, int j)
{
    int max = (i > j) ? i : j;
    return max;
}
int Min(int i, int j)
{
    int min = (i < j) ? i : j;
    return min;
}

struct Node
{
    int val;
    Node* next;
};

// 其它你需要的辅助函数。

Node* insertListNode(Node* head, int i, int val)
{
    // TODO: 向链表中加入一个值为val的节点，使其位于链表的第i个位置。
    
    
    Node* add = new Node;
    add->val = val;
    Node* cur = head;
    if (i == 0)
    {
        add->next = head;
        head = add;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            cur = cur->next;
        }
        Node* temp = head;
        while (temp->next != cur)
        {
            temp = temp->next;
        }
        add->next = cur;
        temp->next = add;
    }
    return head;
}

Node* deleteListNode(Node* head, int i)
{
    // TODO: 删除链表的第i个节点。
    Node* cur = head;
    if (i == 0)
    {
        head = cur->next;
        delete cur;
    }
    else
    {
        for (int j = 0; j < i; j++)
        {
            cur = cur->next;
        }
        Node* temp = head;
        while (temp->next != cur)
        {
            temp = temp->next;
        }
        temp->next = cur->next;
        delete cur;
    }
    return head;
}

Node* swapListNode(Node* head, int i, int j)
{
    // TODO: 交换链表的第i个节点和第j个节点。
    if (i == j)//如果相同则不进行操作
    {
        return head;
    }
    Node* up = head;
    Node* down = head;
    int i1 = min(i, j);
    int j1 = max(i, j);
    for (int k = 0; k < i1; k++)
    {
        up = up->next;
    }
    for (int k = 0; k < j1; k++)
    {
        down = down->next;
    }//寻找要交换的两个节点
    
    Node* temp_downp = new Node;
    Node* temp_upp = new Node;
    temp_upp->val = up->val;
    temp_downp->val = down->val;//拷贝一份要交换的节点

    if (i1 == 0)
    {
        if (j1 == 1)
        {
            temp_upp->next = up->next->next;
            temp_downp->next = temp_upp;
            head = temp_downp;
        }
        else
        {
            temp_downp->next = head->next;
            head = temp_downp;
            Node* downb = head;
            while (downb->next != down)
            {
                downb = downb->next;
            }
            temp_upp->next = down->next;
            downb->next = temp_upp;
        }
    }
    else
    {
        Node* upb = head;
        Node* downb = head;
        while (upb->next != up)
        {
            upb = upb->next;
        }
        while (downb->next != down)
        {
            downb = downb->next;
        }//寻找up和down的上一个节点
        
        temp_upp->next = down->next;
        downb->next = temp_upp;
        temp_downp->next = up->next;
        upb->next = temp_downp;
        
    }
    delete up;
    delete down;
    return head;
}

int findListNode(Node* head, int val)
{
    int pos = 0;
    Node* cur = head;
    if (head == nullptr)
    {
        return -1;
    }
    while ((cur->next!=NULL)&&(cur->val != val))
    {
        cur = cur->next;
        pos++;
    }
    if (cur->next != NULL)
    {
        return pos;
    }
    else
    {
        if (cur->val == val)
        {
            return pos;
        }
        else
        {
            return - 1;
        }
    }
    // TODO: 返回链表中第一个值为val的节点的下标，没有返回-1。
}

void printList(Node* head)
{
    // TODO: 从前向后打印链表的内容，元素之间用"->"连接。链表为空的话输出null。
    if (head == NULL)
    {
        cout << "null";
    }
    else
    {
        Node* cur = head;
        while (cur->next != NULL)
        {
            cout << cur->val << "->";
            cur = cur->next;
        }
        cout << cur->val;
    }
}

void deleteListAll(Node* head)
{
    while (head != nullptr)
    {
        Node* node = head;
        head = head->next;
        delete node;
    }
}

int main()
{
    int n, val, i, j;
    string op;

    // 链表的头节点。
    Node* head = nullptr;

    cin >> n;
    while (n--)
    {
        cin >> op;
        if (op == "find")
        {
            cin >> val;
            cout << findListNode(head, val) << endl;
        }
        else
        {
            // 这三种操作有可能改变链表的头节点，
            // 因此对应的函数需要返回操作后的链表头节点。
            if (op == "insert")
            {
                cin >> i >> val;
                head = insertListNode(head, i, val);
            }
            else if (op == "delete")
            {
                cin >> i;
                head = deleteListNode(head, i);
            }
            else if (op == "swap")
            {
                cin >> i >> j;
                head = swapListNode(head, i, j);
            }
            printList(head);
            cout << endl;
        }
    }

    // 释放剩余的内存。
    // 把不用的指针置空是一个好习惯。
    deleteListAll(head);
    head = nullptr;

    return 0;
}