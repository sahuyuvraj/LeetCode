class Solution {
public:
    bool canMeasureWater(int j1, int j2, int t) {
        if(t>j1+j2)return false;
        return (t%(__gcd(j1,j2))==0);
    }
};