class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        
        vector<int>ans(num_people,0);
        int j=0;
        
        while(candies>0){
            
            for(int i=0;i<num_people;i++){
                
                j++;
                candies-=j;
                
                if(candies<=0){
                    ans[i]+=candies+j;
                    break;
                }
                else ans[i]+=j;
            }
        }
        return ans;
    }
};