#include<iostream>
using namespace std;

struct Node
{
	int a;
	Node* next;
};

Node* Build(int n)
{
	Node* head = NULL;
	if (n == 0)
	{
		return head;
	}
	else
	{
		head = new Node;
		head->next = NULL;
		cin >> head->a;
		for (int i = 0; i < n - 1; i++)
		{
			Node* p = new Node;
			p->next = head;
			cin >> p->a;
			head = p;
		}
		return head;
	}
}

void Output(Node* head)
{
	Node* p = head;
	while (p->next != NULL)
	{
		cout << p->a << " ";
		p = p->next;
	}
	cout << p->a << endl;
}

Node* Listsort(Node* head)
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node* fast = head->next;
	Node* slow = head;
	while (fast != NULL && fast->next != NULL)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	Node* tmp = slow->next;
	slow->next = NULL;
	Node* left = Listsort(head);
	Node* right = Listsort(tmp);
	Node* h = new Node;
	Node* res = h;
	while (left != NULL && right != NULL)
	{
		if (left->a < right->a)
		{
			h->next = left;
			left = left->next;
		}
		else
		{
			h->next = right;
			right = right->next;
		}
		h = h->next;
	}
	h->next = left != NULL ? left : right;
	return res->next;
}

int main()
{
	int n = 6;
	Node* head = Build(6);
	Output(head);
	head = Listsort(head);
	Output(head);
	return 0;
}