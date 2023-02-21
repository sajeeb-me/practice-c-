#include<bits/stdc++.h>
using namespace std;

template<class T>
class MaxHeap
{
public:
    vector<T>nodes;
    MaxHeap()
    {

    }
    void up_heapify(int idx)
    {
        while(idx>0 && nodes[idx] > nodes[(idx-1)/2])
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
            if(l < nodes.size() && nodes[l] > nodes[largest])
                largest = l;
            if(r < nodes.size() && nodes[r] > nodes[largest])
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
    T getMax()
    {
        if(nodes.empty())
        {
            cout << "Heap is empty!\n";
            T a;
            return a;
        }
        return nodes[0];
    }
    T ExtractMax()
    {
        if(nodes.empty())
        {
            cout << "Heap is empty!\n";
            T a;
            return a;
        }
        T ret = nodes[0];
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
    vector<int>find_kThLargest(vector<int>a, int n)
    {
        MaxHeap h;
        h.build_from_array(a);
        vector<int>ans;
        for(int i=0; i<n; i++)
            ans.push_back(h.ExtractMax());
        return ans;
    }
};

int main()
{
    MaxHeap<int> mHeap;
//    mHeap.insert(6);
//    mHeap.insert(3);
//    mHeap.insert(4);
//    mHeap.insert(8);
//    mHeap.insert(5);
//    mHeap.insert(2);
//    mHeap.insert(9);
//    mHeap.PrintHeap();
//
//    mHeap.Delete(0);
//    mHeap.PrintHeap();
//    cout << "Max value: " << mHeap.getMax() << "\n";

    int n1, n2;
    cin >> n1 >> n2;
    vector<int>arr(n1);
    for(int i=0; i<n1; i++)
        cin >> arr[i];

    mHeap.build_from_array(arr);
    mHeap.PrintHeap();

    vector<int>kThLargest = mHeap.find_kThLargest(arr, n2);
    for(int i=0; i<kThLargest.size(); i++)
        cout << kThLargest[i] << " ";
    cout << "\n";

    return 0;
}
