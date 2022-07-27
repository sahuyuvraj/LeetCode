class Solution {
public:
    int mySqrt(int x) {
        if(x==1 or x==0)return x;
        int low=1,high=x/2,ans=1,mid;
        while(low<=high){
            mid=low+(high-low)/2;
            if(mid<=x/mid)ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};