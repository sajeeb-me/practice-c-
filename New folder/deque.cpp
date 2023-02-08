#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node* prv;
    node* nxt;
};

class Deque
{
public:
    node* head;
    node* tail;
    int sz;
    int rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    node* CreateNewNode(int value)
    {
        node* newNode = new node;
        newNode->data = value;
        newNode->prv = NULL;
        newNode->nxt = NULL;
        return newNode;
    }

    void InsertAtTail(int value)
    {
        node* newNode = CreateNewNode(value);
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

    void InsertAtHead(int value)
    {
        node* newNode = CreateNewNode(value);
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

    void push_back(int value)
    {
        rev == 0 ? InsertAtTail(value) : InsertAtHead(value);
    }
    void push_front(int value)
    {
        rev == 0 ? InsertAtHead(value) : InsertAtTail(value);
    }

    void DeleteLast()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            return;
        }
        if(sz == 1)
        {
            delete tail;
            head = NULL;
            tail = NULL;
            sz--;
            return;
        }
        node* a = tail;
        tail = tail->prv;
        delete a;
        tail->nxt = NULL;
        sz--;
    }
    void DeleteFirst()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
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
        delete a;
        head->prv = NULL;
        sz--;
    }

    void pop_back()
    {
        rev == 0 ? DeleteLast() : DeleteFirst();
    }

    void pop_front()
    {
        rev == 0 ? DeleteFirst() : DeleteLast();
    }

    int front()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            return -1;
        }
        if(rev == 0)
            return head->data;
        else
            return tail->data;
    }
    int back()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            return -1;
        }
        if(rev == 0)
            return tail->data;
        else
            return head->data;
    }
    int size()
    {
        return sz;
    }
    void reverse_deque()
    {
        if(rev == 0)
            rev = 1;
        else
            rev = 0;
    }
};

int main()
{
    Deque d;
    d.push_back(5);
    d.push_back(15);
    d.push_back(25);
    d.push_back(20);
    d.push_back(30);
    d.reverse_deque();

    cout << "size: " << d.size() << "\n";

    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    d.pop_front();
    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    d.pop_back();
    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

    cout << "size: " << d.size() << "\n";

    return 0;
}
