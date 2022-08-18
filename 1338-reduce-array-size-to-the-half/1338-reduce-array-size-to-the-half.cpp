class Solution {
public:
    int minSetSize(vector<int>& arr) {
       int n=arr.size();
        
        unordered_map<int,int>mp;
        for(int i:arr)mp[i]++;
        
        priority_queue<int>pq;
        for(auto it:mp)pq.push(it.second);
        
        int ans=0;
        int sum=0;
        while(!pq.empty()){
            sum+=pq.top();pq.pop();
            ans++;
            if(sum>=n/2) return ans;
            
        }
        return 0;
    }
};