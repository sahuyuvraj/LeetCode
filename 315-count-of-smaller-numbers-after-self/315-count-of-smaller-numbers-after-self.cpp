class Solution {
public:
      void countAndMerge(vector<int> &arr,int low, int high, int middle, vector<int> &count, vector<int> &index){
        int i = low;
        int j = middle+1;
        vector<int> out;
        int cnt = 0;
        while(i<=middle && j<=high){
            if(arr[index[i]]<=arr[index[j]]){
                out.push_back(index[i]);
                count[index[i]] += cnt;
                i++;
            }
            else{
                out.push_back(index[j]);
                cnt+=1;
                j++;
            }
        }
        while(i<=middle){
            out.push_back(index[i]);
            count[index[i]]+=cnt;
            i++;
        }
        while(j<=high){
            out.push_back(index[j++]);
        }
        for (int l = low; l <= high; ++l){
            index[l] = out[l-low];
        }
    }
    void solve(vector<int> &arr, int n, int low , int high, vector<int> &count, vector<int> &index){
        //base case
        if(low>=high){
            return ;
        }

        //recursive case	
        int middle = low + (high-low)/2;
        solve(arr, n,low, middle, count,index);
        solve(arr,n,middle+1,high,count,index);
        countAndMerge(arr,low,high,middle,count,index);
    }

    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> count(n,0),index(n,0);
        for(int i = 0 ; i < n ; i++){
            index[i] = i;
        }
        solve(nums,n,0,n-1,count,index);
        return count;
    }
};