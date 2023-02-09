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
    int sz, rev;

    Deque()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
        rev = 0;
    }

    Node<T>* CreateNewNode(T value)
    {
        Node<T>* newNode = new Node<T>;
        newNode->data = value;
        newNode->prv = NULL;
        newNode->nxt = NULL;
        return newNode;
    }

    void InsertAtHead(T value)
    {
        Node<T>* newNode = CreateNewNode(value);
        if(sz == 0)
        {
            head = newNode;
            tail = newNode;
            sz++;
            return;
        }
        newNode->nxt = head;
        head->prv = newNode;
        head = newNode;
        sz++;
    }
    void InsertAtTail(T value)
    {
        Node<T>* newNode = CreateNewNode(value);
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
        Node<T>* a = head;
        head = head->nxt;
        head->prv = NULL;
        delete a;
        sz--;
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
        Node<T>* a = tail;
        tail = tail->prv;
        tail->nxt = NULL;
        delete a;
        sz--;
    }
    void reverse_deque()
    {
        if(rev == 0)
            rev = 1;
        else
            rev = 0;
    }
    void push_front(T value)
    {
        rev == 0 ? InsertAtHead(value) : InsertAtTail(value);
    }
    void push_back(T value)
    {
        rev == 0 ? InsertAtTail(value) : InsertAtHead(value);
    }
    void pop_front()
    {
        rev == 0 ? DeleteFirst() : DeleteLast();
    }
    void pop_back()
    {
        rev == 0 ? DeleteLast() : DeleteFirst();
    }
    T front()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        if(rev == 0)
            return head->data;
        else
            return tail->data;
    }
    T back()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        if(rev == 0)
            return tail->data;
        else
            return head->data;
    }
    T max_val()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        Node<T>* a = head;
        T maxVal = a->data;
        while(a != NULL)
        {
            if(a->data > maxVal)
                maxVal = a->data;
            a = a->nxt;
        }
        return maxVal;
    }
    T min_val()
    {
        if(sz == 0)
        {
            cout << "Deque is empty!\n";
            T a;
            return a;
        }
        Node<T>* a = head;
        T minVal = a->data;
        while(a != NULL)
        {
            if(a->data < minVal)
                minVal = a->data;
            a = a->nxt;
        }
        return minVal;
    }
};

int main()
{
    Deque<int> d;
    d.push_front(5);
    d.push_front(10);
    d.push_back(15);
    d.push_back(20);
//    d.reverse_deque();

    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";
    cout << "Max val: " << d.max_val() << ", Min val: " << d.min_val() << "\n";

//    d.pop_front();
//    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";
//
//    d.pop_back();
//    cout << "Front: " << d.front() << ", Back: " << d.back() << "\n";

//    cout << "Max val: " << d.max_val() << ", Min val: " << d.min_val() << "\n";
    return 0;
}
