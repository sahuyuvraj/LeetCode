// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    typedef long long ll;
    ll ans=0;
    
    void merge(ll arr[],ll start,ll end,ll mid){
        ll n1=mid-start+1;
        ll n2=end-mid;
        
        ll left[n1],right[n2];
        
        for(int i=0;i<n1;i++)left[i]=arr[start+i];
        for(int i=0;i<n2;i++)right[i]=arr[mid+1+i];
        
        ll i=0,j=0,k=start;
        while(i<n1 and j<n2){
            if(left[i]<=right[j])arr[k++]=left[i++];
            else ans+=(n1-i),arr[k++]=right[j++];
        }
        
        while(i<n1)arr[k++]=left[i++];
        while(i<n2)arr[k++]=right[j++];
    }
    
    void mergeSort(ll arr[],ll start,ll end){
        if(start>=end)return;
        ll mid=start+(end-start)/2;
        mergeSort(arr,start,mid);
        mergeSort(arr,mid+1,end);
        merge(arr,start,end,mid);
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        mergeSort(arr,0,N-1);
        return ans;
    }

};

// { Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}
  // } Driver Code Ends