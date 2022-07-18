class Solution {
public:
    void backtrack(string digits,string combination[],int n,int i,vector<string>&ans,string temp){
        if(i>n) return;
        if(i==n){
            ans.push_back(temp);
            return;
        }
        for(char c:combination[digits[i]-'0'])
            backtrack(digits,combination,n,i+1,ans,temp+c);
    }
    vector<string> letterCombinations(string digits) {
        vector<string>ans;
        int n=digits.size();
        if(n==0)
            return ans;
        string combination[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        backtrack(digits,combination,n,0,ans,"");
        return ans;
    }
};