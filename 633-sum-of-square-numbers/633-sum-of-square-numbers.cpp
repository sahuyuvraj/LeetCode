class Solution {
public:

    bool binary_search(int l,int r,int target){
        while(l<=r){
            int mid=l+(r-l)/2;
            if(mid*mid==target)return true;
            if(mid*mid<target)l=mid+1;
            else r=mid-1;
        }
        return false;
    }
    bool judgeSquareSum(int c) {
        for(long i=0;i*i<=c;i++){
            int rest=c-(i*i);
            if(binary_search(0,i,rest))return true;
        }
        return false;
    }
};