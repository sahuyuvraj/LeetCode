// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here 
        int s_row=0,s_col=0;
        vector<int>ans;
        while(s_row<r and s_col<c){
            
            //for upper row
            for(int i=s_col;i<c;i++)ans.push_back(matrix[s_row][i]);
            s_row++;
            
            //for right col
            for(int i=s_row;i<r;i++)ans.push_back(matrix[i][c-1]);
            c--;
            
            //for lower row
            if(s_row<r)
            for(int i=c-1;i>=s_col;i--)ans.push_back(matrix[r-1][i]);
            r--;
            
            //for left col
            if(s_col<c)
            for(int i=r-1;i>=s_row;i--)ans.push_back(matrix[i][s_col]);
            s_col++;
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends