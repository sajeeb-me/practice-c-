#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* nxt;
    Node* prv;
};

class LinkedList
{
public:
    Node* head;
    Node* tail;
    int sz;

    LinkedList()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    Node* CreateNewNode(int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->nxt = NULL;
        newNode->prv = NULL;
        return newNode;
    }
    void insertHead(int value)
    {
        Node* newNode = CreateNewNode(value);
        if(sz == 0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        head->prv = newNode;
        newNode->nxt = head;
        head = newNode;
        sz++;
    }
    void insertTail(int value)
    {
        Node* newNode = CreateNewNode(value);
        if(sz == 0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        tail->nxt = newNode;
        newNode->prv = tail;
        tail = newNode;
        sz++;
    }
    void insertMid(int value)
    {
        Node* newNode = CreateNewNode(value);
        int mid = sz/2;
        Node* a = head;
        int cur_idx = 1;
        while(cur_idx != mid)
        {
            a = a->nxt;
            cur_idx++;
        }
        newNode->nxt = a->nxt;
        newNode->prv = a;
        Node* b = a->nxt;
        a->nxt = newNode;
        b->prv = newNode;
        sz++;
    }
    void print()
    {
        Node* a = head;
        while(a != NULL)
        {
            cout << a->value << " ";
            a = a->nxt;
        }
        cout << "\n";
    }
    void Merge(LinkedList a)
    {
        if(a.head == NULL)
        {
            return;
        }
        if(head == NULL)
        {
            head = a.head;
            tail = a.tail;
            sz = a.sz;
            return;
        }
        tail->nxt = a.head;
        a.head->prv = tail;
        tail = a.tail;
        sz += a.sz;
    }
};
int main()
{
    LinkedList a;
    LinkedList b;

    a.insertHead(1);
    a.insertTail(5);
    a.insertMid(3);
    a.insertHead(0);
    a.insertTail(10);
    a.print(); // prints  0 1 3 5 10

    b.insertHead(10);
    b.insertTail(50);
    b.insertMid(30);
    b.insertHead(9);
    b.insertTail(100);
    b.print(); // prints  9 10 30 50 100

    a.Merge(b);
    a.print(); // prints  0 1 3 5 10 9 10 30 50 100
    b.print(); // prints  9 10 30 50 100
}
