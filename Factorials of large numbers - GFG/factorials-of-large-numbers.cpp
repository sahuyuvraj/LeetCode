// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++
class Node{
    public:
  int data;
  Node*prev;
  Node(int val){
      data=val;
      prev=NULL;
  }
};

void mul(Node*tail,int i){
    Node*curr=tail,*prev=tail;
    
    int carry=0;
    
    while(curr!=NULL){
        int data=curr->data*i+carry;
        curr->data=data%10;
        carry=data/10;
        prev=curr;
        curr=curr->prev;
    }
    
    while(carry!=0){
        prev->prev=new Node(carry%10);
        carry=carry/10;
        prev=prev->prev;
    }
}

void place(Node* tail,vector<int>&ans){
    if(!tail)return;
    place(tail->prev,ans);
    ans.push_back(tail->data);
}

class Solution {
public:
    vector<int> factorial(int N){
        // code here
        vector<int>ans;
        Node*tail=new Node(1);
        for(int i=2;i<=N;i++){
            mul(tail,i);
        }
        
        place(tail,ans);
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        vector<int> result = ob.factorial(N);
        for (int i = 0; i < result.size(); ++i){
            cout<< result[i];
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends