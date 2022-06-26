// { Driver Code Starts
#include<bits/stdc++.h>
 
using namespace std; 


bool findPair(int arr[], int size, int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int l,n;
        cin>>l>>n;
        int arr[l];
        for(int i=0;i<l;i++)
            cin>>arr[i];
        if(findPair(arr, l, n))
            cout<<1<<endl;
        else cout<<"-1"<<endl;
    }
    
  
    return 0;
}// } Driver Code Ends

bool isP(int arr[],int x,int size){
    int low=0,high=size-1,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(arr[mid]==x)return true;
        if(arr[mid]<x)low=mid+1;
        else high=mid-1;
    }
    return false;
}

bool findPair(int arr[], int size, int n){
    //code
    sort(arr,arr+size);
    if(n==0){
        for(int i=1;i<size;i++)if(arr[i-1]==arr[i])return true;
        return false;
    }
    for(int i=0;i<size;i++){
        if(isP(arr,arr[i]+n,size))return true;
    }
    return false;
}