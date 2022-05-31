class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n=arr.size();
        int l=0,h=n-1,mid;
        while(l<h){
            mid=l+(h-l)/2;
            if(arr[mid]<arr[mid+1])l=mid+1;
            else h=mid;
        }
        return h;
       
        
        // int n=arr.size();
        // int low=0,high=n-1,mid,ans=INT_MIN,ind=-1;
        // while(low<high){
        //     mid=low+(high-low)/2;
        //     if(arr[mid]>ans){
        //         ans=arr[mid];
        //         ind=mid;
        //     }
        //     if(arr[mid]<arr[mid+1])low=mid+1;
        //     else high=mid;
        // }
        // return ind;
       // return max_element(arr.begin(),arr.end())-arr.begin();
    }
};