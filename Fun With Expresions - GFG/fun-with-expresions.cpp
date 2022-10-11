//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:
    int calculate(string s) {
        // Code here
        stack<int>st;
        char sgn='+';
        int n=0;
        for(int i=0;i<s.size();i++){
            if(isdigit(s[i]))n=n*10+s[i]-'0';
            if(!isdigit(s[i]) and !isspace(s[i]) or i==s.size()-1){
                
                if(sgn=='+')st.push(n);
                else if(sgn=='-')st.push(-n);
                else if(sgn=='*'){
                    n=st.top()*n;st.pop();st.push(n);
                }else{
                    n=st.top()/n;st.pop();st.push(n);
                }
                
                sgn=s[i];
                n=0;
            }
        }
        
        while(!st.empty()){
            n+=st.top();st.pop();
        }
        return n;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution obj;
		int ans = obj.calculate(s);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends