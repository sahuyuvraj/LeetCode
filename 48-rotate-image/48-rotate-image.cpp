class Solution {
public:
    void rotate(vector<vector<int>>& m) {
        for(int s=0,e=m.size()-1;s<m.size();s++,e--)
    {
        for(int i=s,j=e;i<e;i++,j--)
        {
            int temp=m[s][i];
            
                m[s][i]=m[j][s];
                m[j][s]=m[e][j];
                m[e][j]=m[i][e];
                m[i][e]=temp;
        }
    }
    }
};