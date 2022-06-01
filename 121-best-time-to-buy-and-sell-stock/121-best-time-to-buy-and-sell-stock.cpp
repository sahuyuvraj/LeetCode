class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int sum=0,bd=prices[0];
        for(int i=1;i<n;i++){
            if(bd>prices[i]){
                bd=prices[i];
            }
            if(sum<prices[i]-bd)sum=prices[i]-bd;
        }
        return sum;
    }
};