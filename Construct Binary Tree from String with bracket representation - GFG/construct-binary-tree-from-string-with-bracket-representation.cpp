// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left
child and a pointer to right child */
class Node
{
public:
    int data;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        this->left = this->right = NULL;
    }
};

/* This function is to print the inorder of the tree  */
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}



 // } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    // function to construct tree from string
    Node *treeFromString(string str)
    {
        // code here
        if(!str.size())return NULL;
       //if(str.size()==1)return new Node(str[0]-'0');
       string num="";
       int i=0;
       while(i<str.size() and str[i]!='('){
           num+=to_string(str[i]-'0');
           i++;
       }
       
       Node* root=new Node(stoi(num));
       
       string s1="";
       string s2="";
       
       i=i+1;
       int cnt1=1;
       while(i<str.size()){
           if(cnt1==0)break;
           if(str[i]=='('){
               cnt1++;
               s1+=str[i];
           }else if(str[i]==')'){
               cnt1--;
               if(cnt1)s1+=str[i];
           }else{
               s1+=str[i];
           }
           i++;
       }
       
       i=i+1,cnt1=1;
       while(i<str.size()){
           if(cnt1==0)break;
           if(str[i]=='('){
               cnt1++;
               s2+=str[i];
           }else if(str[i]==')'){
               cnt1--;
               if(cnt1)s2+=str[i];
           }else{
               s2+=str[i];
           }
           i++;
       }
       
      // cout<<s1<<" "<<s2<<endl;
       root->left=treeFromString(s1);
       root->right=treeFromString(s2);
     return root;  
    }
};

// { Driver Code Starts.

// Driver Code
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;
        Solution obj;
        Node *root = obj.treeFromString(str);
        inorder(root);
        cout << "\n";
    }
    return 0;
}
  // } Driver Code Ends