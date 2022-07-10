// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        
        int n=nums.size();
        if(n%2)return false;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            nums[i]=nums[i]%k;
            mp[nums[i]]++;
        }
        
        if(mp[0]%2)return false;
        
        for(int i=0;i<n;i++){
            if(nums[i]){
                if(mp[nums[i]]!=mp[k-nums[i]]){
                    return false;
                }
            }
        }
        
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends