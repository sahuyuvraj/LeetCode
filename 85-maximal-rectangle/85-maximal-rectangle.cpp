class Solution {
public:
        void nsl(vector<int>&left,vector<int>&heights,int n){
        
        stack<pair<int,int>>st;
        
        for(int i=0;i<n;i++){
            
            while(!st.empty() and st.top().first>=heights[i]) st.pop();
            
            if(st.empty())left.push_back(-1);
            else left.push_back(st.top().second);
            
            st.push({heights[i],i});
        }
        
    }
    
    void nsr(vector<int>&right,vector<int>&heights,int n){
        
        stack<pair<int,int>>st;
        
        for(int i=n-1;i>=0;i--){
            
            while(!st.empty() and st.top().first>=heights[i]) st.pop();
            
            if(st.empty())right.push_back(n);
            else right.push_back(st.top().second);
            
            st.push({heights[i],i});
        }
        reverse(right.begin(),right.end());
        
    }
    
    int MAH(vector<int>& heights) {
        
        int n=heights.size();
        vector<int>left,right;
        nsl(left,heights,n);
        nsr(right,heights,n);
        
        int ans=INT_MIN,width;
        for(int i=0;i<n;i++){
            width=right[i]-left[i]-1;
            ans=max(ans,width*heights[i]);
        }
        return ans;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
         int ans=INT_MIN;
        int n=matrix.size(),m=matrix[0].size();
        vector<int>heights(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='0')heights[j]=0;
                else heights[j]+=1;
            }
            ans=max(ans,MAH(heights));
        }
        return ans;
    }
};