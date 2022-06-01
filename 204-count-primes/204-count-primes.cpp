class Solution {
public:
    int countPrimes(int n) {
        bool prime[n+1];
       // if(n==0 or n==1)return 0;
        memset(prime,true,sizeof(prime));
        for(int i=2;i*i<n;i++){
            if(prime[i]==true){
                for(int j=i*i;j<=n;j+=i){
                    prime[j]=false;
                }
            }
        }
        
        int cnt=0;
        for(int i=2;i<n;i++)
            if(prime[i])cnt++;
        return cnt;
    }
};