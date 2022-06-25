// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Node{
  public:
  int data;
  Node*left;
  Node*right;
  Node(int val){
      data=val;
      left=NULL;
      right=NULL;
  }
};
class Solution {
public:

    Node*BST(vector<int>&nums,int start,int end){
        if(start>end)return NULL;
        int mid=start+(end-start)/2;
        Node*root=new Node(nums[mid]);
        root->left=BST(nums,start,mid-1);
        root->right=BST(nums,mid+1,end);
        return root;
    }
    
    void preorder(Node*root,vector<int>&ans){
        if(!root)return;
        ans.push_back(root->data);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    vector<int> sortedArrayToBST(vector<int>& nums) {
        // Code here
        Node*root=BST(nums,0,nums.size()-1);
        vector<int>ans;
        preorder(root,ans);
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // } Driver Code Ends