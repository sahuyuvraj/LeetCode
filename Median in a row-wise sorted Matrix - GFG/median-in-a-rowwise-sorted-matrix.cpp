// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    // int upper_bound(vector<int> nums, int target){
    //     int l = 0, r = nums.size()-1, m = 0;
    //     while(l < r) {
    //         m = (l+r)/2;
    //         if(nums[m] <= target)
    //             l = m+1;
    //         else 
    //             r = m;
    //     }
    //     return r;
    // }
    
    
    int median(vector<vector<int>> &matrix, int r, int c){
        // code here
       int high=2000;
        int low=1;
        int median=(r*c)/2;
        while(low<=high)
        {
            int cnt=0;
            int mid=(high+low)/2;
            for(int i=0;i<r;i++)
            {
                cnt+=(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());  //solve(matrix[i],mid);
            }
            if(cnt<=median)
            {
                low=mid+1;
            }
            else
            {
                high=mid-1;
            }
        }
        return low;
    }
    //1 1 2 8 8 12 13 14 15 17 18
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends