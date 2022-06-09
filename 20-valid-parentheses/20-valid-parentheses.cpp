class Solution {
public:
    bool isValid(string str) {
        stack<char>s;
        for(int i=0;i<str.size();i++){
            if(s.empty() and (str[i]==']' or str[i]=='}' or str[i]==')'))return false;
            if(str[i]=='[' or str[i]=='{' or str[i]=='(' )s.push(str[i]);
            else if(str[i]==']' and s.top()=='[')s.pop();
            else if(str[i]=='}' and s.top()=='{')s.pop();
            else if(str[i]==')' and s.top()=='(')s.pop();
            else return false;
        }
        return s.empty();
    }
};