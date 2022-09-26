class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>curr(2,0);
        vector<int>pre1(2,0);
        vector<int>pre2(2,0);
        for(int i=n-1;i>=0;i--){
            curr[1]=max(-prices[i]+pre1[0],pre1[1]);
            curr[0]=max( prices[i]+pre2[1],pre1[0]);
            pre2=pre1;
            pre1=curr;
        }
         return pre1[1];
    }
};