class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        if(minutes>=customers.size())return accumulate(customers.begin(),customers.end(),0);
        
        int sum=0,ans=0;
        int mxsum=0;
        int i=0,j=0;
        while(j<customers.size()){
            if(grumpy[j]==0)ans+=customers[j];
            if(grumpy[j]==1)sum+=customers[j];
            
            int min=j-i+1;
            if(min>minutes){
                if(grumpy[i]==1)sum-=customers[i];
                i++;
            }
           j++;
            mxsum=max(mxsum,sum);
        }
        return ans+mxsum;
    }
};