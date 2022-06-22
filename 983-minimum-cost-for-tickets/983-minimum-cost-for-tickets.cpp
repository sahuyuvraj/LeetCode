class Solution {
public:
    
    int min_cost(vector<int>&days,vector<int>&costs,int curr_day,vector<int>&memo){
        
        auto it=lower_bound(days.begin(),days.end(),curr_day);
        if(it==days.end())return 0;
        int dist=distance(days.begin(),it);
        if(memo[dist]!=-1)return memo[dist];
        
        int start=*it;
        int min_dist=INT_MAX;
        
        min_dist=min(min_dist,costs[2]+min_cost(days,costs,start+30,memo));
        min_dist=min(min_dist,costs[1]+min_cost(days,costs,start+7,memo));
        min_dist=min(min_dist,costs[0]+min_cost(days,costs,start+1,memo));
        memo[dist]=min_dist;
        return min_dist;
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int>memo(days.size(),-1);
        return min_cost(days,costs,0,memo);
    }
};