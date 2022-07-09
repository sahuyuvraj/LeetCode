// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        //Write your code here
        
        sort(X.begin(),X.end(),greater<>());
        sort(Y.begin(),Y.end(),greater<>());
        
        int ans=0;
        int hr=1,vr=1;
        int i=0,j=0;
        while(i<M and j<N){
            if(X[i]>Y[j]){
                ans+=(X[i]*hr);
                vr++;
                i++;
            }else{
                ans+=(Y[j]*vr);
                hr++;
                j++;
            }
        }
        
        while(i<M){
            ans+=(X[i]*hr);
                vr++;
                i++;
          }
        
        while(j<N){
            ans+=(Y[j]*vr);
                hr++;
                j++;
        }
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
	    int m, n;
	    cin >> m >> n;
	    vector<int>X(m - 1), Y(n - 1);
	    for(int i = 0; i < m - 1; i++){
	        cin >> X[i];
	    }
	    for(int i = 0; i < n - 1; i++){
	        cin >> Y[i];
	    }
	    Solution ob;
	    int ans = ob.minimumCostOfBreaking(X, Y, m - 1, n - 1);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends