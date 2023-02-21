#include<bits/stdc++.h>
using namespace std;

template<class T>
class MinHeap
{
public:
    vector<T>nodes;
    MinHeap()
    {

    }
    void up_heapify(int idx)
    {
        while(idx>0 && nodes[idx] < nodes[(idx-1)/2])
        {
            swap(nodes[idx], nodes[(idx-1)/2]);
            idx = (idx-1)/2;
        }
    }
    void insert(T value)
    {
        nodes.push_back(value);
        up_heapify(nodes.size() - 1);
    }
    void PrintHeap()
    {
        for(int i=0; i<nodes.size(); i++)
            cout << nodes[i] << " ";
        cout << "\n";
    }
    void down_heapify(int idx)
    {
        while(1)
        {
            int largest = idx;
            int l = 2*idx+1;
            int r = 2*idx+2;
            if(l < nodes.size() && nodes[l] < nodes[largest])
                largest = l;
            if(r < nodes.size() && nodes[r] < nodes[largest])
                largest = r;
            if(largest == idx)
                break;
            swap(nodes[idx], nodes[largest]);
            idx = largest;
        }
    }
    void Delete(int idx)
    {
        if(idx >= nodes.size())
            return;
        swap(nodes[idx], nodes[nodes.size()-1]);
        nodes.pop_back();
        down_heapify(idx);
    }
    T getMin()
    {
        if(nodes.empty())
        {
            cout << "Heap is empty!\n";
            T a;
            return a;
        }
        return nodes[0];
    }
    T ExtractMin()
    {
        if(nodes.empty())
        {
            cout << "Heap is empty!\n";
            T a;
            return a;
        }
        int ret = nodes[0];
        Delete(0);
        return ret;
    }
    void build_from_array(vector<int>&a)
    {
        nodes = a;
        int n = nodes.size();
        int last_non_leaf = n/2-1;
        for(int i= last_non_leaf; i>=0; i--)
            down_heapify(i);
    }
    vector<T>heap_sort(vector<int>a)
    {
        MinHeap m;
        m.build_from_array(a);
        vector<T>ans;
        for(int i=0; i<nodes.size(); i++)
        {
            ans.push_back(m.ExtractMin());
        }
        return ans;
    }
    int size()
    {
        return nodes.size();
    }
};

class PriorityQueue
{
public:
    MinHeap<int> m;
    PriorityQueue()
    {

    }
    void push(int x)
    {
        m.insert(-x);
    }
    int top()
    {
        int value = -m.getMin();
        return value;
    }
    void pop()
    {
        m.Delete(0);
    }
    int size()
    {
        return m.size();
    }

};

int main()
{
    PriorityQueue pq;
    pq.push(6);
    pq.push(7);
    pq.push(3);
    pq.push(2);
    pq.push(4);
    pq.push(1);
    pq.push(8);
    cout << "Top: " << pq.top() << "\n" ;
    pq.pop();
    cout << "Top: " << pq.top() << "\n" ;
    pq.pop();
    cout << "Top: " << pq.top() << "\n" ;
    pq.pop();
    cout << "Top: " << pq.top() << "\n" ;
    pq.pop();
    cout << "Top: " << pq.top() << "\n" ;
    pq.pop();
    cout << "Top: " << pq.top() << "\n" ;


//    MinHeap<int> mHeap;
//    mHeap.insert(6);
//    mHeap.insert(3);
//    mHeap.insert(4);
//    mHeap.insert(8);
//    mHeap.insert(5);
//    mHeap.insert(2);
//    mHeap.insert(9);
//    mHeap.PrintHeap();
//
////    mHeap.Delete(0);
////    mHeap.PrintHeap();
////    cout << "Min value: " << mHeap.getMin() << "\n";
//
//
//    vector<int>a = {10,9,8,7,1,2,3,4};
//    mHeap.build_from_array(a);
//    mHeap.PrintHeap();
//
//    vector<int>sorted_heap = mHeap.heap_sort(a);
//    for(int i=0; i<sorted_heap.size(); i++)
//        cout << sorted_heap[i] << " ";
//    cout << "\n";

    return 0;
}
