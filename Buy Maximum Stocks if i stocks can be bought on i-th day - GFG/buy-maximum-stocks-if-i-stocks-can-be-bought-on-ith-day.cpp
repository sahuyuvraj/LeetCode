// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        //Write your code here
        
        vector<pair<int,int>>market;
        
        for(int i=0;i<n;i++){
            market.push_back({price[i],i+1});
        }
        
        sort(market.begin(),market.end());
        
        int ans=0;
        for(int i=0;i<n;i++){
            int prs=market[i].first;
            int qnt=market[i].second;
            if(prs*qnt<=k){
                ans+=qnt;
                k-=(prs*qnt);
            }else{
                ans+=(k/prs);
                k-=(prs*(k/prs));
            }
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
	    int n, k;
	    cin >> n >> k;
	    int price[n];
	    for(int i = 0 ; i < n; i++){
	        cin >> price[i];
	    }
	    Solution ob;
	    int ans = ob.buyMaximumProducts(n, k, price);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends