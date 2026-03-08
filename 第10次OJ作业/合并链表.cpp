#include <iostream>
using namespace std;

struct Node 
{
    int val;
    Node* next;
};

Node* merge(Node* head1, Node* head2) 
{
    Node* tail1 = head1;
    Node* tail2 = head2;
    while (tail1->next != NULL)
    {
        tail1 = tail1->next;
    }
    while (tail2->next != NULL)
    {
        tail2 = tail2->next;
    }
    if (tail1->val < tail2->val)
    {
        Node* temp = head1;
        head1 = head2;
        head2 = temp;
        delete temp;
    }


    Node* temp2 = NULL;
    Node* temp1 = head1;
    if (head2->val < head1->val)
    {
        Node* small = head2;
        int k = 0;
        while (small->next!=NULL&&small->val < head1->val)
        {
            small = small->next;
            k++;
        }
        small = head2;
        Node* temp = NULL;
        for (int i = 0; i < k-1; i++)
        {
            small = small->next;
        }
        temp = small->next;
        small->next = head1;
        head1 = head2;
        head2 = temp;
    }
    while (head2->next != NULL)//将链表2逐个插入到链表1，直到剩下最后一个
    {
        if ((temp1->val <= head2->val)&&(temp1->next->val>= head2->val))
        {
            temp2 = head2;
            head2 = head2->next;
            temp2 ->next= temp1->next;
            temp1->next = temp2;
            temp1 = temp1->next;
        }
        
        else
        {
            temp1 = temp1->next;
        }
    }

    //插入链表2的最后一个节点
    if (temp1->next == NULL)//如果此时链表1也到了末尾
    {
        if (head2->val >= temp1->val)
        {
            temp1->next = head2;
            head2->next = NULL;
        }
    }
    else
    {
        while (temp1->next != NULL)
        {
            if ((temp1->val <= head2->val) && (temp1->next->val >= head2->val))
            {
                head2->next = temp1->next;
                temp1->next = head2;
                break;
            }
            else
            {
                temp1 = temp1->next;
            }
        }
        if (temp1->next == NULL)
        {
            if (head2->val > temp1->val)
            {
                temp1->next = head2;
                head2->next = NULL;
            }
            else
            {
                Node* temp = head1;
                while (temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                head2->next = temp1;
                temp->next = head2;
                temp1->next = NULL;
            }
        }
        
    }
    return head1;
}

void output(Node* head1) 
{
    Node* current = head1;
    while ((current->next) != NULL)
    {
        cout << current->val << " ";
        current = current->next;
    }
    if (current->next == NULL)
    {
        cout << current->val;
    }
}

Node* test(int len);

int main() 
{
    int len1, len2;
    cin >> len1;
    Node* head1 = test(len1);
    cin >> len2;
    Node* head2 = test(len2);
    head1 = merge(head1, head2);
    output(head1);
    return 0;
}

Node* test(int len) 
{
    Node* head = new Node;
    int x;
    cin >> x;
    len--;
    head->val = x;
    head->next = NULL;
    Node* cur = head;
    while (len > 0) {
        Node* temp = new Node;
        cin >> x;
        len--;
        temp->val = x;
        temp->next = NULL;
        cur->next = temp;
        cur = temp;
    }
    return head;
}