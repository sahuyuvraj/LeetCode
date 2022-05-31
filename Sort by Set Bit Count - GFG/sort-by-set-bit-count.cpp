// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    int count_bit(int n){
        int cnt=0;
        while(n){
            if(n&1)cnt++;
            n>>=1;
        }
        return cnt;
    }
    static bool cmp(pair<int,int>&a,pair<int,int>&b){
        if(a.first==b.first)
        return a.second<b.second;
        return a.first>b.first;
    }
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        vector<pair<int,int>>v;
        int arr2[n];
        for(int i=0;i<n;i++)arr2[i]=arr[i];
       for(int i=0;i<n;i++){
           int cnt=count_bit(arr[i]);
           v.push_back({cnt,i});
       }
       sort(v.begin(),v.end(),cmp);
       for(int i=0;i<n;i++){
           arr[i]=arr2[v[i].second];
       }
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends