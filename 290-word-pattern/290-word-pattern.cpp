class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string>v;
        string temp="";
        //creating word vector
        for(int i=0;i<s.size();i++){
            if(s[i]==' '){
                v.push_back(temp);
                temp="";
            }else{
                temp+=s[i];
            }
        }
        v.push_back(temp);
        
        if(v.size()!=pattern.size())return false;
        
        unordered_map<char,string>mp;
        unordered_set<string>st;
        for(int start=0;start<v.size();start++){
            if(mp[pattern[start]]!=""){
                if(mp[pattern[start]]!=v[start])
                    return false;
            }else{
                if(st.count(v[start])>0)return false;
                mp[pattern[start]]=v[start];
                st.insert(v[start]);
            }
        }
        return true;
    }
};