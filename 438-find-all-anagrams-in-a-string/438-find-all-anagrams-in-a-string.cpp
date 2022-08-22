class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;

        int pn=p.size();
        int sn=s.size();
        
        if(pn>sn)return ans;

        unordered_map<char,int>mp1,mp2;
        for(char c:p)mp1[c]++;
         
        int i;
        for(i=0;i<pn;i++){
            mp2[s[i]]++;
        }
        
        if(mp1==mp2)ans.push_back(0);
        
        
         int prev=0;
        for(;i<sn;i++){
         
            mp2[s[prev]]--;
            if(mp2[s[prev]]==0)mp2.erase(s[prev]);
            prev++;
            mp2[s[i]]++;
            if(mp1==mp2)ans.push_back(i-pn+1);
            
        }
        return ans;
    }
};