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

    LinkedList()
    {
        head = NULL;
    }

    Node* createNewNode(int data)
    {
        Node* newNode = new Node;
        newNode->value = data;
        newNode->next = NULL;
        return newNode;
    }

    void insertAtHead(int num)
    {
        Node* newNode = createNewNode(num);
        if(head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void traverse()
    {
        Node* traverseNode = head;

        if(traverseNode == NULL)
            return;

        while(traverseNode != NULL)
        {
            cout << traverseNode->value << " ";
            traverseNode = traverseNode->next;
        }
        cout << "\n";
    }

    int searchDistinctValue(int num)
    {
        Node* a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->value == num)
                return index;
            a=a->next;
            index++;
        }
        return -1;
    }

    void searchAllValue(int num)
    {
        Node* a = head;
        int index = 0;
        while(a != NULL)
        {
            if(a->value == num)
                cout << num << " is found at index: " << index << "\n";
            a=a->next;
            index++;
        }
    }
};

int main()
{
    LinkedList l;

    l.insertAtHead(10);
    l.insertAtHead(20);
    l.insertAtHead(30);
    l.insertAtHead(40);
    l.insertAtHead(30);

    l.traverse();

    return 0;
}
