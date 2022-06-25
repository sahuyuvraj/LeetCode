// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size())return false;
        int n=str1.size();
        
        string start="";
        start+=str1[0];
        start+=str1[1];
        
        string end="";
        end+=str1[n-2];
        end+=str1[n-1];
        
        string middle=str1.substr(2,n-4);
        return middle+end+start==str2 or end+start+middle==str2;
    }

};


// { Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}
  // } Driver Code Ends