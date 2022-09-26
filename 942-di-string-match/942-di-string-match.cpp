class Solution {
public:
    vector<int> diStringMatch(string s) {
        vector<int> b;
        
        int k=0,j=s.size();
        for(int i=0;i<s.size();i++){
                
            if(s[i]=='I'){
                b.push_back(k);
                k++;
            }
            else if(s[i]=='D'){
                b.push_back(j);
                j--;
            }
            if(j==k) b.push_back(k);
          }
        return b;
    }
};