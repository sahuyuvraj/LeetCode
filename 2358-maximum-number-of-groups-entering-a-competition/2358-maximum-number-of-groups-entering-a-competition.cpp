class Solution {
public:
    int maximumGroups(vector<int>& grades) {
     int n=grades.size(),j=0,i=0,cnt=0;
        for(i=0;i<n;i+=j){
            cnt++;
            j++;
        }
        return i>n?--cnt:cnt;
    }
};