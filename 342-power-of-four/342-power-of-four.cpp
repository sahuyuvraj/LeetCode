class Solution {
public:
    bool isPowerOfFour(int n1) {
       // n=abs(n);
        long long n=n1;
        if(n&(n-1))return false;
        while(n>0){
            if(n==1)return true;
            n>>=2;
        }
        return false;
    }
};