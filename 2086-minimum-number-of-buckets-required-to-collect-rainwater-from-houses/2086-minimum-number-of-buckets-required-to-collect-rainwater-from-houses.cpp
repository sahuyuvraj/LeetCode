class Solution {
public:
    int minimumBuckets(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='H'){
                
                if(i-1>=0 and s[i-1]=='B')continue;
                if(i+1<n and s[i+1]!='H') s[i+1]='B',ans++;
                else if(i-1>=0 and s[i-1]!='H')ans++;
                else return -1;
                
            }
        }
        return ans;
    }
};

