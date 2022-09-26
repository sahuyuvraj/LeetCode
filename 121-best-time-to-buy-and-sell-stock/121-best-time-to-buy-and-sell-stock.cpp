class Solution {
public:
    int maxProfit(vector<int>& prices) {
     int n=prices.size();
        int ans=0,buy_day=prices[0];
        for(int i=1;i<n;i++){
            if(buy_day>prices[i])buy_day=prices[i];
            if(ans<prices[i]-buy_day)ans=prices[i]-buy_day;
        }
        return ans;
    }
};