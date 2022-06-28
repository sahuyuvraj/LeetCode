class Solution {
public:
    int minDeletions(string s) {
         
        vector<int>v(26);
        
        for(char c:s)v[c-'a']++;
        
        sort(v.begin(),v.end(),greater<int>());
        
        int f=v[0];
        int ans=0;
        
        for(int cnt:v){
            if(cnt>f){
                if(f>0)ans+=(cnt-f);
                else ans+=cnt;
            }
            
            f=min(f-1,cnt-1);
        }
        return ans;
    }
};