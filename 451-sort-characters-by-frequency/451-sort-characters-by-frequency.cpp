class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>mp;
        for(char c:s)mp[c]++;
        
        vector<pair<int,char>>v;
        for(auto x:mp){
            v.push_back({x.second,x.first});
        }
        
        sort(v.begin(),v.end(),greater<>());
        string ans="";
        for(int i=0;i<v.size();i++){
            while(v[i].first){
                ans+=v[i].second;
                v[i].first--;
            }
        }
        return ans;
    }
};