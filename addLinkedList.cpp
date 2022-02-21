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

void insertAtHead(node* &head,int data)
{
    if(!head)
    {
        head= new node(data);
        return;
    }
    node* n = new node(data);
    n->next = head;
    head= n;
}

int addTwoLinkedList(node* head1,node* head2,int pos1,int pos2,node* &ans)
{   
    if(!head1 and !head2)
    {
        return 0;
    }
    int data;
    if(pos1>pos2)
    {
        int oc = addTwoLinkedList(head1->next,head2,pos1-1,pos2,ans);
        data = oc + head1->data;
    }
    else if(pos2>pos1)
    {
        int oc = addTwoLinkedList(head1,head2->next,pos1,pos2,ans);
        data = oc + head2->data;
    }
    else
    {
        int oc = addTwoLinkedList(head1->next,head2->next,pos1-1,pos2-1,ans);
        data = oc + head1->data +head2->data;
    }
    int nc = data/10;
    int ndata = data%10;
    insertAtHead(ans,ndata);
    return nc;

}


int main()
{
    int n;
    cin >> n;
    int num;
    cin>>num;
    node* head = new node(num);
    node* tail = head;
    for (int i = 0; i < n-1; i++)
    {
        cin>>num;
        tail->next = new node(num);
        tail = tail->next;
    }
    Display(head);
    int n2;
    cin >> n2;
    int num2;
    cin>>num2;
    node* head2 = new node(num2);
    node* tail2 = head2;
    for (int i = 0; i < n2-1; i++)
    {
        cin>>num2;
        tail2->next = new node(num2);
        tail2 = tail2->next;
    }
    Display(head2);
    node*ans = NULL;
    int oldCarry = addTwoLinkedList(head,head2,n,n2,ans);
    cout<<"Old carry is "<<oldCarry<<endl;
    if(oldCarry!=0)
    {
        insertAtHead(ans,oldCarry);
    }
    cout<<"Addition of given two linked list is "<<endl;
    Display(ans);
    return 0;
}
/**
 * @brief 
//!INTPUT 

4
9 9 9 9
1
1

 * 
 */