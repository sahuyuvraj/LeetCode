class Solution {
public:
    int calculate(string s) {
        stack<int>st;
        long n=0;
        char sgn='+';
        
        for(int i=0;i<s.size();i++){
            
            if(isdigit(s[i]))n=n*10+s[i]-'0';
            
            if(!isdigit(s[i]) and !isspace(s[i]) or i==s.size()-1){
                if(sgn=='+')st.push(n);
                else if(sgn=='-')st.push(-n);
                else if(sgn=='*'){
                    n=st.top()*n;
                    st.pop();
                    st.push(n);
                }else{
                    n=st.top()/n;
                    st.pop();
                    st.push(n);
                }
                
                sgn=s[i];
                n=0;
            }
        }
        
        while(!st.empty()){
            n+=st.top();st.pop();
        }
        return n;
    }
};