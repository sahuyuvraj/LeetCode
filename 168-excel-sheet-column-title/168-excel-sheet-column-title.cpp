class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans="";
        int n=columnNumber;
        
        while(n){
            int rem=n%26;
            n/=26;
            
            if(rem==0)
                rem=26,n--;
            
            ans=char(rem+'A'-1)+ans;
        }
        return ans;
    }
};