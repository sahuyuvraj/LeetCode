class Solution {
public:
    
    int count(vector<int>matrix,int num){
        int low=0;
        int high=matrix.size()-1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(matrix[mid]>num)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
    
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        
        int low=matrix[0][0];
        int high=matrix[n-1][m-1];
        
        while(low<=high){
            int mid=low+(high-low)/2;
            
            int cnt=0;
            for(int i=0;i<m;i++){
                // cnt+=upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin();
                cnt+=count(matrix[i],mid);
            }
            if(cnt>=k)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};