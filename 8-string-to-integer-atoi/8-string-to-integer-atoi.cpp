class Solution {
public:
    int myAtoi(string s) {
        if(s.size()==0)return 0;
        int i=0;
        while(i<s.size() and s[i]==' ')i++;
        s=s.substr(i);
        
        int sign=+1;
        long long ans=0;
        
        if(s[0]=='-')sign=-1;
        
        //if(!isdigit(s[0]))i++;
        i=(s[0]=='+' or s[0]=='-')?1:0;
        
        while(i<s.size()){
         if(s[i]==' ' or !isdigit(s[i]))break;
         
            ans=ans*10+s[i]-'0';
            if(sign==-1 and sign*ans<INT_MIN)return INT_MIN;
            if(sign==1 and sign*ans>INT_MAX)return INT_MAX;
            i++;
        }
        return (int)(ans*sign);
    }
};