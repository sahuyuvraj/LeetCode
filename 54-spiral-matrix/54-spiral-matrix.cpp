class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
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