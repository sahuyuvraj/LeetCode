// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        // Write Your Code here
    //   sort(candies,candies+N);
        
    //     int mn=0,mx=0;
    //     int i=0,j=N-1;
    //     while(i<=j){
    //         mn+=candies[i++];
    //         int k=K;
    //         while(k--){
    //             j--;
    //         }
    //     }
        
    //      i=0,j=N-1;
    //     while(i<=j){
    //         mx+=candies[j--];
    //         int k=K;
    //         while(k--){
    //             i++;
    //         }
    //     }
    //   return {mn,mx};        
         
         
        int n = N;
        int k = K;
        sort(candies,candies+n);
        int x = (n+k)/(k+1);
        int ans1 = 0;
        for(int i=0;i<x;i++){
            ans1 += candies[i];
        }
        int ans2 = 0;
        for(int i=n-1;i>n-1-x;i--){
            ans2 += candies[i];
        }
        return {ans1,ans2};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N, K;
        cin >> N >> K;
        int candies[N];

        for (int i = 0; i < N; i++)
        {
            cin >> candies[i];
        }

        Solution ob;
        vector<int> cost = ob.candyStore(candies, N, K);
        cout << cost[0] << " " << cost[1] << endl;
    }
    return 0;
}  // } Driver Code Ends