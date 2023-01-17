#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node* next;
};

class LinkedList
{
public:
    Node* head;
    int sz;

    LinkedList()
    {
        head = NULL;
        sz = 0;
    }

    Node* createNewNode (int value)
    {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;
        return newNode;
    }

    void InsertAtHead(int value)
    {
        sz++;
        Node* newNode = createNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void Traverse()
    {
        Node* a = head;
        if(head == NULL)
            return;
        while(a != NULL)
        {
            cout << a->value << " ";
            a = a->next;
        }
        cout << "\n";
    }

    int GetSize()
    {
        return sz;
    }

    void RemoveElement()
    {
        sz--;
        Node* a = head;
        head = a->next;
        delete a;
    }

    void RemoveLastElement()
    {
        sz--;
        Node* a = head;
        Node* previous;
        while (a->next != NULL)
        {
            previous = a;
            a = a->next;
        }
        delete a;
        previous->next = NULL;
    }

    void FindElementInIndex(int value)
    {
        Node* a = head;
        int index = 0;
        while(index != value)
        {
            a=a->next;
            index++;
        }
        cout << a->value << "\n";
    }

    void AddNewElement(int value)
    {
        sz++;
        Node* newNode = createNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        Node* a = head;
        while(a->next != NULL)
        {
            a = a->next;
        }
        a->next = newNode;
    }

    string CheckValue(int value)
    {
        Node* a = head;
        while(a != NULL)
        {
            if(a->value == value)
                return "True";
            a = a->next;
        }
        return "False";
    }

    void SortNode()
    {
        Node* a = head;
        while(a != NULL)
        {
            if(a->value > a->next->value)
            {
                Node* temp = a->next;
                cout<<"big: " << temp->value << "\n";
                a->next = temp->next;
                temp->next = a;
                a=a->next;
            }
                a = a->next;
        }
        cout << "\n";
    }

};

int main()
{
    LinkedList l;

    l.InsertAtHead(5);
    l.InsertAtHead(4);
    l.InsertAtHead(3);
    l.InsertAtHead(2);
    l.InsertAtHead(1);
    l.InsertAtHead(0);
    l.Traverse();

    l.RemoveElement();
    l.Traverse();

    l.RemoveLastElement();
    l.Traverse();

    l.FindElementInIndex(2);

    l.AddNewElement(6);
    l.AddNewElement(0);
    l.Traverse();

    cout << l.CheckValue(4) << "\n";

    l.SortNode();
    cout << "After sorting: ";
    l.Traverse();


    cout << "Size: " << l.GetSize() << "\n";

    return 0;
}
