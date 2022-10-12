class Solution {
public:
    string minWindow(string s, string t) {
        int n1=s.size();
        int n2=t.size();
        unordered_map<char,int>mp1,mp2;
        for(char c:t)mp2[c]++;
        
        int start=0,ans=0,mini=INT_MAX,count=0;
        for(int i=0;i<n1;i++){
            
            //acquire
            mp1[s[i]]++;
            if(mp2[s[i]]>=mp1[s[i]])count++;
            
            //release
            while(count==n2){
                if(mini>(i-start+1)){
                    mini=i-start+1;
                    ans=start;
                }
                
                mp1[s[start]]--;
                if(mp2[s[start]]>mp1[s[start]])count--;
                start++;
            }
        }
        return mini==INT_MAX?"":s.substr(ans,mini);
    }
};