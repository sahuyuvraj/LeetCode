class Solution {
public:
    int countPrimes(int n) {
        bool primes[n+1];
        memset(primes,true,sizeof(primes));
        
        // primes[0]=false;
        // primes[1]=false;
        for(int i=2;i*i<n;i++){
            if(primes[i]){
                for(int j=i*i;j<=n;j+=i){
                    primes[j]=false;
                }
            }
        }
        int cnt=0;
        for(int i=2;i<n;i++)if(primes[i])cnt++;
        return cnt;
    }
};