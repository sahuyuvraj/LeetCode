// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

int Search(vector<int> ,int );

//User code will be pasted here

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        
        vector<int> vec(n);
        
        for(int i =0;i<n;i++) 
            cin >> vec[i];
        
        int K;
        cin >> K;
        
        cout << Search(vec,K) << "\n";
         
    }
}// } Driver Code Ends


//User function template for C++

// vec : given vector of elements
// K : given value whose index we need to find 
int Search(vector<int> vec, int K) {
    //code here
    int n=vec.size(),low=0,high=n-1,mid;
    while(low<=high){
        mid=low+(high-low)/2;
        if(vec[mid]==K)return mid;
       
        if(vec[low]<=vec[mid]){
                if(K>=vec[low] and K<vec[mid])high=mid-1;
                else low=mid+1;
            }else{
                if(K>vec[mid] and K<=vec[high])low=mid+1;
                else high=mid-1;
            }
    }
    
    return -1;
    
}