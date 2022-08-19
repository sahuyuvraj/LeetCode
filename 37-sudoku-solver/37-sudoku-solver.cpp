class Solution {
public:
    
    bool isvalid(vector<vector<char>>& board,int x,int y,char val){
        for(int i=0;i<9;i++)
            if(board[i][y]==val or board[x][i]==val)return false;
            
            int xi=(x/3)*3;
            int yj=(y/3)*3;
            
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(board[xi+i][yj+j]==val)return false;
                }
            }
            
        return true;
        
    }
    
    bool solve(vector<vector<char>>& board,int i,int j){
        if(i==9)return true;
        
        int ni=0,nj=0;
        if(j==8){
            ni=i+1;
            nj=0;
        }else{
            ni=i;
            nj=j+1;
        }
        
       if(board[i][j]!='.'){
           if(solve(board,ni,nj))return true;
       }else{
           for(char po='1';po<='9';po++){
               if(isvalid(board,i,j,po)){
                   board[i][j]=po;
                  if(solve(board,ni,nj))return true;
                   board[i][j]='.';
               }
           }
       }
        return false;
    }
     
//     bool doSolve(vector<vector<char>>& board) {
//         for(int i=0; i<9; i++)
//         {
//             for(int j=0; j<9; j++)
//             {
//                 if(board[i][j] == '.')
//                 {                
//                     for(char c='1'; c<='9'; c++)
//                     {
//                         if(isvalid(board, i, j, c))
//                         {
//                             board[i][j] = c;
//                             if(doSolve(board))
//                                 return true;
//                             board[i][j] = '.';
//                         }
//                     }
//                     return false;
//                 }
//             }
//         }
        
//         return true;
//     }
   

    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};