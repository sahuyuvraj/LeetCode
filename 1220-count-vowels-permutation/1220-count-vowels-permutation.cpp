class Solution {
public:
    int countVowelPermutation(int n) {
        int mod=1e9+7;
        int a=1,e=1,i=1,o=1,u=1;
        int A,E,I,O,U;
        for(int j=1;j<n;j++){
            
            A=a,E=e,I=i,O=o,U=u;
            
            a=((E+I)%mod+U)%mod;
            e=(A+I)%mod;
            i=(E+O)%mod;
            o=I;
            u=(I+O)%mod;
            
        }
        return ((((a+e)%mod+i)%mod+o)%mod+u)%mod;
    }
};