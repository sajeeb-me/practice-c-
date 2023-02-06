#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* nxt;
};

class Queue
{
public:
    node* head;
    node* tail;
    int sz;

    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node* CreateNewNode(int value)
    {
        node* newNode = new node;
        newNode->data = value;
        newNode->nxt = NULL;
        return newNode;
    }

    void enqueue(int value)
    {
        sz++;
        node* newNode = CreateNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nxt = newNode;
        tail = newNode;
    }

    void dequeue()
    {
        if(sz == 0)
        {
            cout << "Queue is empty!\n";
            return;
        }
        if(sz == 1)
        {
            delete head;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node* a = head;
        head = head->nxt;
        sz--;
        delete a;
    }

    int front()
    {
        if(sz == 0)
        {
            cout << "Queue is empty!\n";
            return -1;
        }
        return head->data;
    }

    int size()
    {
        return sz;
    }
};

int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.enqueue(7);

    cout << "Q size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << "Q size: " << q.size() << "\n";

    return 0;
}
