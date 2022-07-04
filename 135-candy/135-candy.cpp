class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        vector<int>left(n,1);
        vector<int>right(n,1);
        
        //finding from left side
        for(int i=1;i<n;i++)if(ratings[i-1]<ratings[i])left[i]=left[i-1]+1;
        
        //finding from right side
        for(int i=n-1;i>0;i--)if(ratings[i-1]>ratings[i])right[i-1]=right[i]+1;
        
        //finding max from both
        int ans=0;
        for(int i=0;i<n;i++)ans+=(max(left[i],right[i]));
        return ans;
    }
};