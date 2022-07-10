// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxEqualSum(int N1,int N2,int N3,vector<int> &S1,vector<int> &S2,vector<int> &S3){
        
        int s1=accumulate(S1.begin(),S1.end(),0);
        int s2=accumulate(S2.begin(),S2.end(),0);
        int s3=accumulate(S3.begin(),S3.end(),0);
        
        int i=0,j=0,k=0;
        
        while(i<N1 and j<N2 and k<N3){
            if(s1==s2 and s2==s3)return s1;
            
            if(s1>=s2 and s1>=s3){
                s1-=S1[i++];
            }else if(s2>=s1 and s2>=s3){
                s2-=S2[j++];
            }else{
                s3-=S3[k++];
            }
        }
        return 0;
    }
    
// Input:
// N1 = 3, N2 = 4, N3 = 2
// S1 = {4,2,3}      9 5
// S2 = {1,1,2,3}    7 5
// S3= {1,4}         5
// Output:
// 5
};

// { Driver Code Starts.

int main(){
    
    int t;
    cin>>t;
    while(t--){
        int n1,n2,n3;
        cin>>n1>>n2>>n3;
        vector<int> s1(n1),s2(n2),s3(n3);
        for(int i=0;i<n1;i++){
            cin>>s1[i];
        }
        for(int i=0;i<n2;i++){
            cin>>s2[i];
        }
        for(int i=0;i<n3;i++){
            cin>>s3[i];
        }
        Solution ob;
        int ans=ob.maxEqualSum(n1,n2,n3,s1,s2,s3);
        cout<<ans<<endl;
    }
    
    return 0;
}  // } Driver Code Ends