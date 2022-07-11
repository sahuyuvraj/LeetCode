// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
  public:
  
  void inorder(vector<int>&A,vector<int>&tree,int n,int index){
      if(index>=n)return;
      inorder(A,tree,n,2*index+1);
      tree.push_back(A[index]);
      inorder(A,tree,n,2*index+2);
  }
  
  int count(vector<int>&nums){
    vector<pair<int,int>>v;
    for(int i=0;i<nums.size();i++)
      v.push_back({nums[i],i});
      
      sort(v.begin(),v.end());
      
      int cnt=0;
      for(int i=0;i<nums.size();i++){
          if(v[i].second!=i){
              swap(v[i],v[v[i].second]);
              cnt++;
              i--;
          }
      }
      return cnt;
  }
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        //inorder treversal of BST should be incresing order
        vector<int>tree;
        inorder(A,tree,n,0);
        //now we just have to find in this array what is the minimum number of streps to
        //sort this array
        return count(tree);
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
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends