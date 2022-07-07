// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

	struct Node{
	  char c;
	  int freq;
	  Node*left,*right;
	  
	  Node(char j,int f){
	      c=j;
	      freq=f;
	      left=NULL;
	      right=NULL;
	  }
	  
	};
	
 struct cmp{
     bool operator()(Node*l,Node*r){
     return l->freq>r->freq;
 }
 };
 
class Solution
{
	public:
	

 
 void preorder(Node*root,string s,vector<string>&v){
     if(root->left==NULL and root->right==NULL){
         v.push_back(s);
         return;
     }
     preorder(root->left,s+'0',v);
     preorder(root->right,s+'1',v);
 }
	
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    // Code here
		    Node*root=NULL;
		    priority_queue<Node*,vector<Node*>,cmp>q;
		    
		    for(int i=0;i<N;i++){
		        Node*t=new Node(S[i],f[i]);
		        q.push(t);
		    }
		    
		    vector<string>v;
		    while(q.size()>1){
		        Node*n;
		        
		        Node*l=q.top();
		        q.pop();
		        
		        Node*r=q.top();
		        q.pop();
		        
		        n=new Node('*',l->freq+r->freq);
		        
		        if(l->freq<=r->freq){
		            n->left=l;
		            n->right=r;
		        }else{
		            n->left=r;
		            n->right=l;
		        }
		        q.push(n);
		    }
		    
		    Node*rt=q.top();
		    string s;
		    preorder(rt,s,v);
		    return v;
		}
};

// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
}  // } Driver Code Ends