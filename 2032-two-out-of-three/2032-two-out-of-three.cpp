class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        unordered_map<int,int>mp1,mp2,mp3;
        
        for(int i:nums1)mp1[i]++;
        
        unordered_set<int>st;
        
        for(int i:nums2){
            if(mp1[i]){
                st.insert(i);
            }
            mp2[i]++;
        }
        
      for(int i:nums3){
            if(mp1[i] or mp2[i]){
                  st.insert(i);
            }
        }
        
        vector<int>ans;
        for(auto it:st)ans.push_back(it);
        return ans;
    }
};