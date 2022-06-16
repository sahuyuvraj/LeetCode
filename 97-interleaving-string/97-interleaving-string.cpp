class Solution {
public:
    bool find(string s1, int i1, string s2, int i2, string s3, int i3,unordered_map<string,bool> &memo)
    {
        string pos = to_string(i1)+','+to_string(i2)+','+to_string(i3);
        if(memo.count(pos))
            return memo[pos];
        if(i1==s1.size() and  i2==s2.size() and i3==s3.size())
            return true;
        bool a = false,b = false;
        
        if(i1<s1.size() and i3<s3.size() and s1[i1]==s3[i3])
            a = find(s1,i1+1,s2,i2,s3,i3+1,memo);
        if(i2<s2.size() and i3<s3.size() and s2[i2]==s3[i3] )
            b = find(s1,i1,s2,i2+1,s3,i3+1,memo);
        
        memo[pos] = a or b;
        return memo[pos];
            
    }
    
    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string,bool> memo;
        return find(s1,0,s2,0,s3,0,memo);
    }
};