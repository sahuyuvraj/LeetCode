// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return the sorted array.
    vector <int> nearlySorted(int arr[], int num, int k){
        // Your code here
        priority_queue<int,vector<int>,greater<int>>minn;
        int i;
        for(i=0;i<=k;i++){
            minn.push(arr[i]);
        }
        
        vector<int>ans;
        ans.push_back(minn.top());minn.pop();
        for(i;i<num;i++){
            minn.push(arr[i]);
            ans.push_back(minn.top());
            minn.pop();
        }
        while(!minn.empty()){
            ans.push_back(minn.top());
            minn.pop();
        }
        return ans;
    }
};

// { Driver Code Starts.

int main()
 {
	int T;
	cin>> T;
	
	while (T--)
	{
	    int num, K;
	    cin>>num>>K;
	    
	    int arr[num];
	    for(int i = 0; i<num; ++i){
	        cin>>arr[i];
	    }
	    Solution ob;
	    vector <int> res = ob.nearlySorted(arr, num, K);
	    for (int i = 0; i < res.size (); i++)
	        cout << res[i] << " ";
	        
	    cout<<endl;
	}
	
	return 0;
}
  // } Driver Code Ends