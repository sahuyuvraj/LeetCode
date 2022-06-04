class Solution {
    vector<vector<string>>res;
    
    bool isValid(vector<string>&Q,int n,int row,int col){
        //check if the column had a queen before.
        for(int i=0;i<row;i++)if(Q[i][col]=='Q')return false;
        //check if the 45° diagonal had a queen before.
        for(int i=row-1,j=col-1;i>=0 && j>=0; i--,j--)if(Q[i][j]=='Q')return false;
        //check if the 135° diagonal had a queen before.
        for(int i=row-1,j=col+1;i>=0&& j<n;i--,j++)if(Q[i][j]=='Q')return false;
        return true;
    }
    
    void backtrack(vector<string>&Q,int x,int n){
        
        if(x==n){
            res.push_back(Q);
            return;
        }
        
        for(int i=0;i<n;i++){
            if(isValid(Q,n,x,i)){
                Q[x][i]='Q';
                backtrack(Q,x+1,n);
                Q[x][i]='.';
            }
        }
    }
    
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string>ans(n,string(n,'.'));
        backtrack(ans,0,n);
        return res;
    }
};