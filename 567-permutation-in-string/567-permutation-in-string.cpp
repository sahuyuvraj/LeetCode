class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        int len1=s1.size(),len2=s2.size();
        
        if(len1>len2)return false;
        
        unordered_map<char,int>frq_s1,frq_s2;
        for(int i=0;i<len1;i++){
            frq_s1[s1[i]]++;
            frq_s2[s2[i]]++;
        }
        
        if(frq_s1==frq_s2)return true;
        
        for(int i=len1;i<len2;i++){
            
            char prevChar=s2[i-len1];
            frq_s2[prevChar]--;
            
            if(frq_s2[prevChar]==0 and s2[i]!=prevChar)
                frq_s2.erase(prevChar);
            frq_s2[s2[i]]++;
            if(frq_s1==frq_s2)return true;
        }
        return false;
        
    }
};