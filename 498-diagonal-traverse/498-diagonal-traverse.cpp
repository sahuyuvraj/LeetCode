class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int r=mat.size();
        int c=mat[0].size();
        int k=r+c-1;
        
        vector<int>ans;
        
        for(int i=0;i<k;i++){
            
            if(i&1){  //for odd indexes
                                
               int x=0,y=i;
                while(x<=i and y>=0){
                    if(x<r and y<c)
                        ans.push_back(mat[x][y]);
                    x++;y--;
                }

            }else{   //for odd indexes
                
                int x=i,y=0;
                while(x>=0 and y<=i){
                    if(x<r and y<c)
                        ans.push_back(mat[x][y]);
                    x--;y++;
                }
            }
                
        }
        return ans;
        
    }
};