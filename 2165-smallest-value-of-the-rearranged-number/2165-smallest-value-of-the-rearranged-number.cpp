class Solution {
public:
    long long smallestNumber(long long num) {
        
       string s=to_string(num);
        if(s[0]=='-'){
            sort(s.begin()+1,s.end(),greater<>());
        }else{
            sort(s.begin(),s.end());
            int i=0;
            for(int j=0;j<s.size();j++){
                if(s[j]!='0'){
                    swap(s[i],s[j]);
                    break;
                }
            }
        }
        
        long long ans=stol(s);
        return ans;
    }
};