class Solution {
public:
    bool isPowerOfThree(int n) {
        long temp=1;
        while(n>1 and temp<n){
            temp+=temp<<1;
        }
        return temp==n;
    }
};