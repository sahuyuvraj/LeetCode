//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int ans1=-1,ans2=-1;
    int low=0,high=n-1,mid;
    
    //first occurance
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x){
            ans1=mid;
            high=mid-1;
        }else if(arr[mid]>x){
            high=mid-1;
        }else low=mid+1;
    }
    
    if(ans1==-1)return {-1,-1};
    
    low=0,high=n-1;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x){
            ans2=mid;
            low=mid+1;
        }else if(arr[mid]>x)high=mid-1;
        else low=mid+1;
    }
    return {ans1,ans2};
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends