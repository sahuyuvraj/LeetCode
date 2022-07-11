// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node*buildTree(int in[],int pre[],int start,int end,int &index){
        if(start>end)return NULL;
        
        Node*root=new Node(pre[index++]);
        
        int ind;
        for(int i=start;i<=end;i++){
            if(in[i]==root->data){
                ind=i;
                break;
            }
        }
        
        root->left=buildTree(in,pre,start,ind-1,index);
        root->right=buildTree(in,pre,ind+1,end,index);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int index=0;
        return buildTree(in,pre,0,n-1,index);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends