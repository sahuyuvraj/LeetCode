// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a,a+n);
        
     int i=0;
     while(k and i<n){
         if(a[i]<0)k=k-1,a[i]=abs(a[i]);
         i++;
     }
     sort(a,a+n);
     i=0;
     
     while(k--)a[i]=-a[i];
     
     long long sum=0;
     for(i=0;i<n;i++)sum+=a[i];
     return sum;
    }
};

// { Driver Code Starts.
int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         Solution ob;
         cout<<ob.maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}  // } Driver Code Ends