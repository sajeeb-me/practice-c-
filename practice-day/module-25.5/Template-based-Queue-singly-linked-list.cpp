#include<bits/stdc++.h>
using namespace std;

template<class T>
class node
{
public:
    T data;
    node* nxt;
};

template<class T>
class Queue
{
public:
    node<T>* head;
    node<T>* tail;
    int sz;

    Queue()
    {
        head = NULL;
        tail = NULL;
        sz = 0;
    }

    node<T>* createNewNode(T value)
    {
        node<T>* newNode = new node<T>;
        newNode->data = value;
        newNode->nxt = NULL;
        return newNode;
    }

    void enqueue(T value)
    {
        sz++;
        node<T>* newNode = createNewNode(value);
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
            cout << "Stack is empty!\n";
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
        node<T>* a = head;
        head = head->nxt;
        delete a;
        sz--;
    }

    T front()
    {
        if(sz == 0)
        {
            cout << "Queue is empty!\n";
            T a;
            return a;
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
    Queue<char> q;
    q.enqueue('a');
    q.enqueue('b');
    q.enqueue('c');

    cout << "Size: " << q.size() << "\n";
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << q.front() << "\n";
    q.dequeue();
    cout << "Size: " << q.size() << "\n";

    cout << "\n\n";

    Queue<string> q1;
    q1.enqueue("Sajeeb");
    q1.enqueue("Das");
    q1.enqueue("Shuvo");

    cout << "Size: " << q1.size() << "\n";
    cout << q1.front() << "\n";
    q1.dequeue();
    cout << q1.front() << "\n";
    q1.dequeue();
    cout << q1.front() << "\n";
    q1.dequeue();
    cout << "Size: " << q1.size() << "\n";

    return 0;
}
