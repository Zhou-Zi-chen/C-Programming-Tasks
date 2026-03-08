#include <iostream>
using namespace std;

struct Node 
{
    int val;
    Node* next;
};

Node* reverse(Node* head, int len)
{
    Node* po1 = head;
    Node* temp = NULL;
    for (int i = 0; i < len - 2; i++)
    {
        temp = po1->next;
        po1->next = temp->next;
        temp->next = head;
        head = temp;
        temp = NULL;
    }
    Node* tail = head;
    for (int i = 0; i < len - 1; i++)
    {
        tail = tail->next;
    }
    tail->next = head;
    head = tail;
    temp = head;
    for (int i = 0; i < len - 1; i++)
    {
        temp = temp->next;
    }
    temp->next = NULL;
    return head;
}

void output(Node* head) 
{
    Node* current = head;
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

int main() {
    int len;
    cin >> len;

    Node* head = test(len);
    head = reverse(head, len);
    output(head);
    return 0;
}

Node* test(int len) {
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