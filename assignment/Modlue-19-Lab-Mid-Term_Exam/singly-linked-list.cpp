#include<bits/stdc++.h>

using namespace std;

class node
{
public:
    int data;
    node * nxt;
};

class LinkedList
{
public:
    node * head;
    int sz;
    LinkedList()
    {
        head = NULL;
        sz=0;
    }

    //Creates a new node with data = value and nxt= NULL
    node* CreateNewNode(int value)
    {
        node *newnode = new node;
        newnode->data = value;
        newnode->nxt = NULL;
        return newnode;
    }

    // Insert new value at Head
    void InsertAtHead(int value)
    {
        sz++;
        node *a = CreateNewNode(value);
        if(head == NULL)
        {
            head = a;
            return;
        }
        //If head is not NULL
        a->nxt = head;
        head = a;
    }

    //Prints the linked list
    void Traverse()
    {
        node* a = head;
        while(a!= NULL)
        {
            cout<<a->data<<" ";
            a = a->nxt;
        }
        cout<<"\n";
    }

    int getLast()
    {
        if(head == NULL)
            return -1;

        node* a = head;
        while(a->nxt != NULL)
            a = a->nxt;

        return a->data;
    }

    double getAverage()
    {
        double total=0, countEl=0;
        node* a = head;
        while(a != NULL)
        {
            total += a->data;
            countEl++;
            a = a->nxt;
        }
        double avarage = total/countEl;
        return avarage;
    }

};

int main()
{
    LinkedList l;
    l.InsertAtHead(7);
    l.InsertAtHead(4);
    l.InsertAtHead(6);
    l.InsertAtHead(2);
    l.InsertAtHead(3);
    l.Traverse();

    cout << l.getLast() << "\n";
    cout << l.getAverage() << "\n";

    return 0;
}
