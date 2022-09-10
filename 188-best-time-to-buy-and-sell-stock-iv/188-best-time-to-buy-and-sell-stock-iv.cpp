class Solution {
public:
     vector<vector<vector<int>>>dp;
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        dp.resize(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return memo(prices,0,1,k);
    }
    int memo(vector<int>& prices, int ind , int buy, int cap){
        if(cap == 0) return 0;
        if(ind == prices.size()) return 0;
        if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
        int profit = 0;
        if(buy){
            profit = max(-prices[ind] + memo(prices,ind+1,0,cap),memo(prices,ind+1,1,cap));
            return dp[ind][buy][cap] = profit;
        }
        profit = max(prices[ind] + memo(prices,ind+1,1,cap-1),memo(prices,ind+1,0,cap));
        return dp[ind][buy][cap] = profit;
    }
};