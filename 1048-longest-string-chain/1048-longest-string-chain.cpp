struct myCmp {
    bool operator()(string &s1,string &s2) {
        return s1.length() < s2.length();
    }
};

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(),words.end(),myCmp());
        
        int dp[words.size()], res = 1;
        for(int i=0;i<words.size();i++)
            dp[i] = 1;

        for(int i=1;i<words.size();i++) {
            
            for(int j=0;j<i;j++) {
                
                if(words[i].length() == words[j].length()+1) {
                    
                    int ii = 0, jj = 0, cnt = 0, eq = 1;
                    
                    while(ii < words[i].length() && jj < words[j].length()) {
                        
                        if(words[i][ii] == words[j][jj])
                        { ii++;jj++; }
                        else {
                            if(cnt == 0) {
                                cnt++;
                                ii++;
                            }
                            else {
                                eq = 0;
                                break;
                            }
                        }
                        
                    }
                    if(eq) {
                        
                        dp[i] = max(dp[i],dp[j]+1);
                        res = max(dp[i],res);
                        
                    }
                }
            }
        }
        return res;
    }
};