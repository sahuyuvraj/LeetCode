class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total=0,curr=0;
        int j=0;
        
        for(int i=0;i<gas.size();i++){
            
            total+=(gas[i]-cost[i]);
            curr+=(gas[i]-cost[i]);
            if(curr<0)j=i+1,curr=0;
        }
        
        return total<0?-1:j;
    }
};