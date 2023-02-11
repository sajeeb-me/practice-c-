#include<bits/stdc++.h>
using namespace std;

template<class T>
class Node
{
public:
    T data;
    Node* prv;
    Node* nxt;
};

template<class T>
class Deque
{
public:
    Node<T>* head;
    Node<T>* tail;
    int sz;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }
    Node<T>* CreateNewNode(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->prv = NULL;
        newNode->nxt = NULL;
        return newNode;
    }
    void push_front(T value)
    {
        sz++;
        Node<T>* newNode = CreateNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        head->prv = newNode;
        newNode->nxt = head;
        head = newNode;
    }
    void push_back(T value)
    {
        sz++;
        Node<T>* newNode = CreateNewNode(value);
        if(tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nxt = newNode;
        newNode->prv = tail;
        tail = newNode;
    }
    void pop_back()
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
        sz--;
        Node<T>* a = tail;
        tail = tail->prv;
        delete a;
        tail->nxt = NULL;
    }
    void pop_front()
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
        sz--;
        Node<T>* a = head;
        head = head->nxt;
        delete a;
        head->prv = NULL;
    }
    T front()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        return head->data;
    }
    T back()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        return tail->data;
    }
};

int main()
{
    Deque<string> dq;
    dq.push_front("Das");
    dq.push_front("Sajeeb");
    dq.push_back("Shuvo");
    dq.push_back("Shuvo 2");

    cout << "Front: " << dq.front() << ", Back: " << dq.back() << "\n";
    dq.pop_back();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << "\n";
    dq.pop_front();
    cout << "Front: " << dq.front() << ", Back: " << dq.back() << "\n";

    return 0;
}
