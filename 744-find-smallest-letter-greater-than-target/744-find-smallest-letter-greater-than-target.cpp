class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int low=0,high=letters.size()-1,mid,ans=0;
        while(low<=high){
            mid=low+(high-low)/2;
            if(letters[mid]>target)ans=mid,high=mid-1;
            else low=mid+1;
        }
        return letters[ans];
    }
};