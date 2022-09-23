class Solution {
public:
        int concatenatedBinary(int n) {
        
        long ans = 0, modulo = 1e9+7;
        int numOfBits = 0;
    
        for(int i = 1; i <= n; i++){
            numOfBits += pow2(i);
            ans = (ans << numOfBits) % modulo + i;
        }
        
        return ans;
    }
    
    bool pow2(int n){
        return !(n & (n-1));
    }
};