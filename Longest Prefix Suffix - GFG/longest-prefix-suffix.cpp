// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    // Your code goes here
	    int n=s.length();
	    int lps[n];
	    memset(lps,0,sizeof(lps));
	    
	    lps[0]=0;
	    
	    int i=1,j=0;
	    
	    while(i<n){
	        if(s[i]==s[j]){
	            j++;
	            lps[i]=j;
	            i++;
	        }else{
	            if(j!=0){
	                j=lps[j-1];
	            }else{
	                lps[i]=0;
	                i++;
	            }
	        }
	    }
	    return lps[n-1];
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends