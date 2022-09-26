class Solution {
public:
    int mem[26]; 
    int find(int x) {
        return x == mem[x] ? x : mem[x] = find(mem[x]);
    }
    
public:
    bool equationsPossible(vector<string>& equations) {
        for(int i = 0; i <26; i++)
            mem[i] = i;
        for(auto s: equations) 
            if(s[1] == '=')
                mem[find(s[0]-'a')] = find(s[3]-'a');
        for(auto s: equations)
            if(s[1] == '!' and find(s[0]-'a') == find(s[3]-'a'))
                return false;
        return true;
    }
};