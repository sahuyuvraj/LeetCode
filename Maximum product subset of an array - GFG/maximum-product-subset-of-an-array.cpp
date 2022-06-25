// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    long long int findMaxProduct(vector<int>&a, int n){
        //Write your code here
        if(n==1)return a[0];
        int neg=0,zero=0,max_neg=INT_MIN;
        long long int ans=1;
        
        for(int i=0;i<n;i++){
            if(a[i]==0){
                zero++;
                continue;
            }else if(a[i]<0){
                neg++;
                max_neg=max(max_neg,a[i]);
            }
            ans=(ans*a[i])%1000000007;
        }
        if(zero==n)return 0;
        if(neg==1 and zero>0 and zero+neg==n)return 0;
        if(neg%2!=0)ans/=max_neg;
        return ans;
    }
};



// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>arr(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    long long int ans = ob.findMaxProduct(arr, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends