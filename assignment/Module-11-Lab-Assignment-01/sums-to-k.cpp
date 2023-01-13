#include<bits/stdc++.h>
using namespace std;

int mergeSort(vector<int>arr, int l, int r, int k)
{
    int cnt = 0;
    if (l < r)
    {
        int m = (l+r)/2;

        cnt += mergeSort(arr, l, m, k);
        cnt += mergeSort(arr, m+1, r, k);

        int i = l, j = m+1, index = 0;
        vector<int>temp(r-l+1);

        while (i <= m && j <= r)
        {
            if (arr[i] < arr[j])
                temp[index++] = arr[i++];
            else
                temp[index++] = arr[j++];
        }

        while (i <= m)
            temp[index++] = arr[i++];

        while (j <= r)
            temp[index++] = arr[j++];

        for (int i = l; i <= r; i++)
            arr[i] = temp[i-l];

        int left = l;
        int right = r;
        while (left < right)
        {
            if (arr[left] + arr[right] == k)
            {
                cnt++;
                left++;
                right--;
            }
            else if (arr[left] + arr[right] < k)
                left++;
            else
                right--;
        }
    }
    return cnt;
}

int main()
{
    int n, k, cnt;
    cin>>n;
    vector<int>arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];

    cin>>k;

    cnt = mergeSort(arr, 0, n-1, k);
    cout << cnt << "\n";

    return 0;
}
