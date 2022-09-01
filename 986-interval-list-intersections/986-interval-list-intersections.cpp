class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i=0,j=0;
        vector<vector<int>>ans;
        
        while(i<firstList.size() and j<secondList.size()){
            int a=firstList[i][0];
            int b=firstList[i][1];
            int c=secondList[j][0];
            int d=secondList[j][1];
            
            int x=max(a,c);
            int y=min(b,d);
            
            if(x<=y)ans.push_back({x,y});
            if(b<d)i++;
            else j++;
        }
        return ans;
    }
};