#include<iostream>
using namespace std;


Node* Build(int n);
void Output(Node* head);
Node* Add(Node* head, int pos);

int main()
{
	int n;
	cin >> n;
	Node* head = Build(n);
	Output(head);
	int pos;
	cout << "请输入要插入的位置（第n个位置前）：" << endl;
	cin >> pos;
	head=Add(head, pos);
	Output(head);
	return 0;
}





Node* Add(Node* head,int pos)
{
	Node* p = head;
	Node* cur = new Node;
	cin >> cur->a;
	int k = 1;
	while (k < pos && p->next != NULL)
	{
		p = p->next;
		k++;
	}
	if (k == pos)
	{
		if (pos == 1)
		{
			cur->next = head;
			head = cur;
		}
		else
		{
			cur->next = p;
			Node* temp = head;
			while (temp->next != p)
			{
				temp = temp->next;
			}
			temp->next = p;
		}	
	}
	else if (k + 1 == pos)
	{
		cur->next = NULL;
		p->next = cur;
	}
	else
	{
		cout << "Error" << endl;
	}
	return head;
}