class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int l =0,h =arr.size(),m,p;
        while(l<h){
            m = (l+h)>>1;
            p = arr[m]-m-1;
            if(p<k) l=m+1;
            else h =m;
        }
        return l+k;
    }
};