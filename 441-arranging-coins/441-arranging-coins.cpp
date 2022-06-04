class Solution {
public:
    int arrangeCoins(int n) {
        long long i=1,j=1;
        int cnt=0;
        while(j<=n){
            cnt++;
            i++;
            j+=i;
        }
        return cnt;
    }
};