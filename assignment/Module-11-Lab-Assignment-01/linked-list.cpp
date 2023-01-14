#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

class LinkedList
{
public:
    Node* head;
    int size;

    LinkedList()
    {
        this->head = NULL;
        this->size = 0;
    }

    void InsertAtHead(int data)
    {
        Node* newNode = new Node(data);
        newNode->next = this->head;
        this->head = newNode;
        this->size++;
    }

    int getSize()
    {
        return this->size;
    }

    int getValue(int index)
    {
        if (index >= this->size)
        {
            return -1;
        }

        Node* current = this->head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        return current->data;
    }

    void Traverse()
    {
        Node* current = this->head;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void printReverse(Node* current)
    {
        if (current == NULL)
        {
            return;
        }

        printReverse(current->next);
        cout << current->data << " ";
    }

    void swapFirst()
    {
        if (this->size < 2)
        {
            return;
        }

        Node* second = this->head->next;
        this->head->next = second->next;
        second->next = this->head;
        this->head = second;
    }

};

int main()
{
    LinkedList l;
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(5);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(6);
    l.InsertAtHead(30);
    cout<<l.getSize()<<"\n";
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    cout<<l.getValue(2)<<"\n";

    cout<<l.getValue(6)<<"\n";

    l.printReverse(l.head);
    cout << "\n";
    l.Traverse();
    l.swapFirst();
    l.Traverse();
    l.printReverse(l.head);
    cout << "\n";


    return 0;
}
