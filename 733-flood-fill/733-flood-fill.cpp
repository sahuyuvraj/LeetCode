class Solution {
public:
    void fill(int newColor,int currColor,vector<vector<int>>&image,int i,int j,int row,int col){
        if(i<0 or j<0 or i>=row or j>=col or image[i][j]!=currColor)return;
        image[i][j]=newColor;
        
        fill(newColor,currColor,image,i+1,j,row,col);
        fill(newColor,currColor,image,i,j+1,row,col);
        fill(newColor,currColor,image,i-1,j,row,col);
        fill(newColor,currColor,image,i,j-1,row,col);
    }
    
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldcolor=image[sr][sc];
        if(oldcolor==newColor)return image;
        fill(newColor,oldcolor,image,sr,sc,image.size(),image[0].size());
        return image;
    }
};