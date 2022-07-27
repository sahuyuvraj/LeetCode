class Solution {
public:
    double myPow(double x, int n) {
        //if(x==1.0)return x;
        double ans=1;
        n<0?x=1/x,n=abs(n):1;
        
        while(n){
            double temp=ans;
            if(n&1){
                ans*=x;
                if(ans==temp)return ans;
            } 
            x*=x;
            n>>=1;
        }
        return ans;
    }
};