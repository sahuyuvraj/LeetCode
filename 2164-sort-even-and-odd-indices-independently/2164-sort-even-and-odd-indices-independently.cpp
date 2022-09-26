class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        int size = nums.size();
        vector<int> even; vector<int> odd;
        for(int i = 0; i < size; i++)
        {
            (i % 2 == 0)? even.push_back(nums[i]) : odd.push_back(nums[i]); 
        }
        sort(even.begin(), even.end()); 
        sort(odd.begin(), odd.end());
        reverse(odd.begin(), odd.end());
        int a = 0, b = 0;
        for(int i = 0; i < size; i++)
        {
            (i % 2 == 0)? (swap(nums[i], even[a++])) : (swap(nums[i], odd[b++]));
        }
        return nums;
    }
};