class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
    
        sort(boxTypes.begin(),boxTypes.end(), [](auto &a, auto &b){return a[1] > b[1];});
        int i=0,sum=0;
        for(int i=0;i<boxTypes.size();i++){
                int n=min(truckSize,boxTypes[i][0]);
                sum+=(n*boxTypes[i][1]);
            truckSize-=n;
            if(truckSize==0)break;
        }
        return sum;
    }
};