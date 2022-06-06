class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int>mp,mp2;
        vector<string>ans;
        
        for(int i=0;i<list1.size();i++)mp[list1[i]]=i;
        for(int i=0;i<list2.size();i++){
            if(mp.find(list2[i])!=mp.end()){
                mp2[list2[i]]=i+mp[list2[i]];
            }
        }
        
        vector<pair<int,string>>v;
        for(auto i:mp2)v.push_back({i.second,i.first});
        sort(v.begin(),v.end());
        int x=v[0].first;
        for(auto i:v)
            if(i.first==x)ans.push_back(i.second);
            else break;
        return ans;
    }
};