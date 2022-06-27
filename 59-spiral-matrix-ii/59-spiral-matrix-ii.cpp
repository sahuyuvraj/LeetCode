class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int cnt=1;
        vector<vector<int>>matrix(n,vector<int>(n,0));
        int r=matrix.size();
        int c=matrix[0].size();
        int s_row=0,s_col=0;
        vector<int>ans;
        while(s_row<r and s_col<c){
            
            //for upper row
            for(int i=s_col;i<c;i++)matrix[s_row][i]=cnt++;
            s_row++;
            
            //for right col
            for(int i=s_row;i<r;i++)matrix[i][c-1]=cnt++;
            c--;
            
            //for lower row
            if(s_row<r)
            for(int i=c-1;i>=s_col;i--)matrix[r-1][i]=cnt++;
            r--;
            
            //for left col
            if(s_col<c)
            for(int i=r-1;i>=s_row;i--)matrix[i][s_col]=cnt++;
            s_col++;
        }
        
        return matrix;
    }
};