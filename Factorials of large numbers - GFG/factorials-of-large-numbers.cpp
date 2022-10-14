//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};

class Solution {
public:
   void insert(Node*head,int i){
       Node*curr=head,*prev=NULL;
       int carry=0;
       while(curr){
           int val=(curr->data*i)+carry;
           curr->data=val%10;
           carry=val/10;
           prev=curr;
           curr=curr->next;
       }
       
        while(carry!=0){
           prev->next=new Node(carry%10);
           carry=carry/10;
           prev=prev->next;
       }
       
   }
   
   
   void place(Node*head,vector<int>&ans){
       while(head){
           ans.push_back(head->data);
           head=head->next;
       }
       reverse(ans.begin(),ans.end());
   }
    vector<int> factorial(int N){
        // code here
        Node*head=new Node(1);
        for(int i=2;i<=N;i++){
            insert(head,i);    
        }
        vector<int>ans;
        place(head,ans);
        return ans;
    }
};

//{ Driver Code Starts.

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
}
// } Driver Code Ends