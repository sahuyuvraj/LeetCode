class Solution {
public:
    int numRescueBoats(vector<int>& p, int limit) {
        
        int ans=0;
        int n=p.size();
        sort(p.begin(),p.end());
        int l=0,r=n-1;
        while(l<=r){
            if(p[l]+p[r]<=limit){
                l++;r--;
            }else{
                r--;
            }
            ans++;
        }
        return ans;
    }
};