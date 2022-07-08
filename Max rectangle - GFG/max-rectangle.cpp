// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX 1000


 // } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
  
  vector<int>NSR(int arr[],int n){
      vector<int>ans;
      stack<pair<int,int>>st;
      
      for(int i=n-1;i>=0;i--){
          if(st.empty()){
              ans.push_back(n);
              st.push({arr[i],i});
          }else{
              while(!st.empty() and st.top().first>=arr[i]){
                  st.pop();
              }
              
              if(st.empty()){
                  ans.push_back(n);
              }else{
                  ans.push_back(st.top().second);
              }
              st.push({arr[i],i});
          }
      }
      reverse(ans.begin(),ans.end());
      return ans;
  }
  
    vector<int>NSL(int arr[],int n){
      vector<int>ans;
      stack<pair<int,int>>st;
      
      for(int i=0;i<n;i++){
          if(st.empty()){
              ans.push_back(-1);
              st.push({arr[i],i});
          }else{
              while(!st.empty() and st.top().first>=arr[i]){
                  st.pop();
              }
              
              if(st.empty()){
                  ans.push_back(-1);
              }else{
                  ans.push_back(st.top().second);
              }
              st.push({arr[i],i});
          }
      }
      //reverse(ans.begin(),ans.end());
      return ans;
  }
  
  
  int MAH(int arr[],int n){

      int max_area=0;
      
      vector<int>width(n,0);
      
      vector<int>v1=NSR(arr,n);  //nearest smallest right
      
      vector<int>v2=NSL(arr,n);  //nearest smallest left
      
      for(int i=0;i<n;i++){
          width[i]=abs(v1[i]-v2[i])-1;
      }
      
      for(int i=0;i<n;i++){
          int area=width[i]*arr[i];
          max_area=max(max_area,area);
      }
      
      return max_area;

  }
  
    int maxArea(int M[MAX][MAX], int n, int m) {
        // Your code here
        
        //maximum aera of histogram
        int max_area=MAH(M[0],m);
        
        for(int i=1;i<n;i++){
            
            for(int j=0;j<m;j++){
                M[i][j]+=(M[i][j]==0)?0:M[i-1][j];
            }
            
            max_area=max(max_area,MAH(M[i],m));
        }
        return max_area;
    }
};


// { Driver Code Starts.
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        Solution obj;
        cout << obj.maxArea(M, n, m) << endl;
    }
}
  // } Driver Code Ends