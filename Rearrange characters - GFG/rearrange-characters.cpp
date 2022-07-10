// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string str)
    {
        //code here
        priority_queue<pair<int,char>>pq;
        int n=(str.size()+1)/2;
        unordered_map<char,int>mp;
        for(char c:str){
            mp[c]++;
            if(mp[c]>n)return "-1";
        }
        
        string ans=" ";
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
        
        while(pq.size()){
            if(pq.size()==1){ans+=pq.top().second;break;}
            auto prev=pq.top();pq.pop();
            if(ans[ans.size()-1]==prev.second){
                auto curr=pq.top();pq.pop();
                pq.push(prev);
                prev=curr;
            }
            ans+=prev.second;
            prev.first--;
           // cout<<prev.second<<" ";
            if(prev.first)pq.push(prev);
        }
        return ans.substr(1);
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends