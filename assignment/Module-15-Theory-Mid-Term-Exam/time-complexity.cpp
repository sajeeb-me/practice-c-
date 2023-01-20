#include<bits/stdc++.h>
using namespace std;

/*
Bubble Sort: O(n^2)
Insertion Sort: O(n^2)
Merge Sort: O(n log n)
*/

/*
void InsertAtHead(int value)
{
    node* a = CreateNewNode(value);
    if(head == NULL)
    {
        head = a;
        return;
    }
    a->nxt = head;
    head = a;

}

void InsertAtAnyIndex(int index, int value)
{
    if(index == 0)
    {
        InsertAtHead(value);
        return;
    }
    node* a = head;
    int cur_index = 0;
    while(cur_index != index-1)
    {
        a=a->nxt;
        cur_index++;
    }
    node* newNode = CreateNewNode(value);
    newNode->nxt = a->nxt;
    a->nxt = newNode;
}

void DeleteAtHead()
{
    if(head == NULL) return;
    node* a = head;
    head = a->nxt;
    delete a;
}

void DeleteAtAnyIndex(int index)
{
    if(index < 0 || index > sz-1)
    {
        cout << "index " << index << " is invelied!\n";
        return;
    }
    if(index == 0)
    {
        DeleteAtHead();
        return;
    }
    node* a = head;
    int cur_index = 0;
    while(cur_index != index-1)
    {
        a=a->nxt;
        cur_index++;
    }
    node* b = a->nxt;
    a->nxt = b->nxt;
    delete b;
}
*/


int main()
{
    int n=10;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout<< i << "\n";
            cout<< (n/i) << "\n";
        }
    }

    return 0;
}
