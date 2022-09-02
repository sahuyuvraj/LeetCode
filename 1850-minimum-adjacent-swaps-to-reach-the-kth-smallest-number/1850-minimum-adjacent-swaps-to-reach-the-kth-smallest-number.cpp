class Solution {
public:
    
    int min_swap(string &org,string &nums){
        int count=0;
        int i=0,j;
        while(i<nums.size()){
            j=i;
            
            while(org[i]!=nums[j]) j++;
            
            while(i<j){
                swap(nums[j],nums[j-1]);
                j--;
                count++;
            }
            i++;
        }
        return count;
    }
    
    int getMinSwaps(string num, int k) {
        
        string org=num;
        while(k--)
            next_permutation(num.begin(),num.end());
        
        return min_swap(org,num);
    }
};