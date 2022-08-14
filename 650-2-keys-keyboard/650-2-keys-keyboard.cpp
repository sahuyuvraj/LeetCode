class Solution {
public:
    int minSteps(int n) {
        if(n==1)return 0;
        
        
        int ans=n;
        for(int i=2;i<n;i++){
            if(n%i==0){
                ans = minSteps(i)+n/i;
            }
        }
        return ans;
    }
};