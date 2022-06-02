class Solution {
public:
    int mySqrt(int x) {
      if (x <= 1)return x;
      if (x < 0)return INT_MAX;
        int low=1,high=x/2,mid,ans=1;
        while(low<=high){
           mid=low+(high-low)/2;
            if(mid<=x/mid)ans=mid,low=mid+1;
            else high=mid-1;
        }
        return ans;
    }
};