class Solution {
public:
        void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        for(int i=0;i<n;i++){
            int start=0,end=n-1;
            while(start<end)swap(matrix[i][start++],matrix[i][end--]);
        }
    }
    
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat==target)return true;
        rotate(mat);
        if(mat==target)return true;
        rotate(mat);
        if(mat==target)return true;
        rotate(mat);
        if(mat==target)return true;
        return false;
    }
};