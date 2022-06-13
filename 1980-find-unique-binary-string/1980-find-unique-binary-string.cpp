class Solution {
public:
    string ans="";
    void solve(unordered_map<string,int>&mp,int i,int n,string s){
        if(i>n)return;
        if(i==n)if(!mp[s]){ans=s;return;}
        solve(mp,i+1,n,s+'0');
        solve(mp,i+1,n,s+'1');
    }
    
    string findDifferentBinaryString(vector<string>& nums) {
        // unordered_map<string,int>mp;
        // for(string  s:nums)mp[s]++;
        // int n=nums[0].size();
        // solve(mp,0,n,"");
        // return ans;
        
        string s(nums.size() ,'0');
        for(int i=0;i<nums.size();i++){
            if(nums[i][i]=='0')
                s[i] = '1';
            else
                s[i] = '0';
        }
        return s;
    }
};