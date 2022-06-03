class NumMatrix {
public:
    vector<vector<int>>sum;
    NumMatrix(vector<vector<int>>& matrix) {
        sum=matrix;
        //row sum
        for(int i=0;i<sum.size();i++){
            for(int j=1;j<sum[0].size();j++){
                sum[i][j]+=sum[i][j-1];
            }
        }
        
        //column sum
        for(int i=1;i<sum.size();i++){
            for(int j=0;j<sum[0].size();j++){
                sum[i][j]+=sum[i-1][j];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int total=sum[row2][col2];
        int extra=(col1!=0?sum[row2][col1-1]:0)+(row1!=0?sum[row1-1][col2]:0)-((row1!=0 and col1!=0)?sum[row1-1][col1-1]:0);
        return total-extra;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */