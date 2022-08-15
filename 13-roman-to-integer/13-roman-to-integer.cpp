class Solution {
public:
    int romanToInt(string s) {
     
        unordered_map<char,int>mp;
        mp['I']=1,mp['V']=5,mp['X']=10,mp['L']=50,mp['C']=100,mp['D']=500,mp['M']=1000;
        
        int n=s.size();
        int sum=mp[s[n-1]];
        
        for(int i=n-2;i>=0;i--){
            if(mp[s[i]]<mp[s[i+1]]) sum-=mp[s[i]];
            else sum+=mp[s[i]];
        }
         return sum;
    }
};