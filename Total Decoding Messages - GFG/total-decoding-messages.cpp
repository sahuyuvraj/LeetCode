// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int n=str.size();
		    const int mod=1e9+7;
		    
		    //table to store results of subproblems
		   int count[n+1];
		   count[0]=1;
		   count[1]=1;
		   
		   //for base condition "0123" return 0
		  if(str[0]=='0')return 0;
		  
		  for(int i=2;i<=n;i++){
		      count[i]=0;
		      
		      if(str[i-1]>'0')count[i]=count[i-1]%mod;
		      
		      if(str[i-2]=='1' or str[i-2]=='2' and str[i-1]<'7')
		      count[i]=(count[i]+count[i-2])%mod;
		  }
		  return count[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends