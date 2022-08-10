class Solution {
public:
    int check(vector<int>&weights,int mid){
        int ans=1;
        int sum=0,i=0;
        while(i<size(weights)){
            sum+=weights[i];
            
            if(sum>mid)sum=0,ans++;
            else i++;
        }
        return ans;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end()),
        high=accumulate(weights.begin(),weights.end(),0),mid,ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(check(weights,mid)<=days)ans=mid,high=mid-1;
            else low=mid+1;
        }
        return ans;
    }
};