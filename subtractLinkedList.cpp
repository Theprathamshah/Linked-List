#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = NULL;
    }
};
void InsertAtTail(node *&head, int val)
{
    node *n = new node(val);
    if (head == NULL)
    {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}
void Display(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void addFirst(node *&head, int data)
{
    node *n = new node(data);
    if (!head)
    {
        head = n;
        return;
    }
    n->next = head;
    head = n;
}

int subtractTwoLinkedList(node *head1, node *head2, int pos1, int pos2, node *&ans)
{
    if (!head1 and !head2)
    {
        return 0;
    }
    int data;
    int oc = 0;
    if (pos1 > pos2)
    {
        int oldBorrow = subtractTwoLinkedList(head1->next, head2, pos1 - 1, pos2, ans);

        data = head1->data + oldBorrow;
    }
    else if (pos1 < pos2)
    {
        int oldBorrow = subtractTwoLinkedList(head1, head2->next, pos1, pos2 - 1, ans);
        data = 10 + oldBorrow - head2->data;
        oc = -1;
    }
    else
    {
        int oldBorrow = subtractTwoLinkedList(head1->next, head2->next, pos1 - 1, pos2 - 1, ans);
        int diff = head1->data - head2->data+oldBorrow;
        if (diff < 0)
        {
            oc = -1;
            data = 10 - diff;
        }
        else
            data = head1->data - head2->data + oldBorrow;
    }
    addFirst(ans, data);
    return oc;
}

int main()
{
    int n;
    cin >> n;
    int num;
    cin >> num;
    node *head = new node(num);
    node *tail = head;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> num;
        tail->next = new node(num);
        tail = tail->next;
    }
    Display(head);
    int n2;
    cin >> n2;
    int num2;
    cin >> num2;
    node *head2 = new node(num2);
    node *tail2 = head2;
    for (int i = 0; i < n2 - 1; i++)
    {
        cin >> num2;
        tail2->next = new node(num2);
        tail2 = tail2->next;
    }
    Display(head2);
    node *ans = NULL;
    int oldCarry = subtractTwoLinkedList(head, head2, n, n2, ans);
    if (oldCarry < 0)
    {
        addFirst(ans, 1);
        cout << "-";
        Display(ans);
    }
    else
        Display(ans);
    return 0;
}
