class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& M, int k) {
       
        
        int n=M.size(), m=M[0].size();
        int DP[n][m];
        memset(DP,0,sizeof(DP));
        
        DP[0][0]=M[0][0];
        
        for(int i=1;i<m;i++) DP[0][i]=DP[0][i-1] + M[0][i];
        for(int i=1;i<n;i++) DP[i][0]=DP[i-1][0] + M[i][0];
        
        for(int i=1;i<n;i++)
            for(int j=1;j<m;j++)
            {
                DP[i][j]=DP[i-1][j]+DP[i][j-1]-DP[i-1][j-1] + M[i][j];
            }
        
        int ret=INT_MIN, cur;
        
        int M1, M2, M3, M4;
        
        for(int x1=0;x1<n;x1++)
            for(int x2=x1;x2<n;x2++)
                for(int y1=0;y1<m;y1++)
                    for(int y2=y1;y2<m;y2++)
                    {
                        M1=0; M2=0; M3=0; M4=0;
                        
                        if(x1>0&&y1>0) M1=DP[x1-1][y1-1];
                        if(x1>0) M2=DP[x1-1][y2];
                        if(y1>0) M3=DP[x2][y1-1];
                        
                        M4=DP[x2][y2];
                        
                         cur=M4-M3-M2+M1;
               
                         if(cur<=k) ret=max(ret,cur);
                        
                        
                    } 
        return(ret);
        
    }
};