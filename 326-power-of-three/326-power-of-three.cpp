class Solution {
public:
    bool isPowerOfThree(int n) {
        int max = 1162261467;
        return n > 0 && max % n == 0; 
    }
};