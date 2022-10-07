class Solution {
public:
    string countAndSay(int n) {
        if(n==1)return "1";
        if(n==2)return "11";
        
        string s="11";
      
       
        for(int j=3;j<=n;j++){
         string t="";
            s+="#";     
            int cnt=1;
            for(int i=1;i<s.size();i++){
                if(s[i-1]!=s[i]){
                    t+=to_string(cnt);
                    t+=s[i-1];
                    cnt=1;
                }else{
                    cnt++;
                }
            }
            s=t;
        }
        
        return s;
    }
};