class Solution {
public:
    string rev(string s){
        int i=0,j=s.size()-1;
        while(i<j)swap(s[i++],s[j--]);
        return s;
    }
    string reverseWords(string s) {
        string ans="";
        stringstream ss(s);
        string buff;
        while(ss >> buff)
            ans+=" "+rev(buff);
        return ans.substr(1);
    }
};