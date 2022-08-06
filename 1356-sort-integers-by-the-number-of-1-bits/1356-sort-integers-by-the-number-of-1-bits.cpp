class Solution {
public:
  vector<int> sortByBits(vector<int>& arr) {
        int count=0;
        vector<pair<int,int>> v;
        for(int i=0;i<arr.size();i++){
            count=__builtin_popcount(arr[i]);
            v.push_back(make_pair(count,arr[i]));
        }
        sort(v.begin(),v.end());
        vector<int>res;
        for(auto i:v){
            res.push_back(i.second);
        }
        return res;
    }
};