class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int zero_cnt=0;
        unordered_set<int>s;
        for(int i:arr){
            if(i==0)zero_cnt++;
            if(zero_cnt==2)return true;
            //if(s.find(i*2)!=s.end())return true;
            s.insert(i);
        }
        
        for(int i:arr)
            if(i!=0 and s.find(i*2)!=s.end())return true;
        
        return false;
    }
};