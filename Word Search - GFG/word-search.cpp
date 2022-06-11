// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool solve(vector<vector<char>>& board, string word,int i,int j,int k,int r,int c){
        if(k==word.size())return true;
        if(i<0 or j<0 or i>=r or j>=c or word[k]!=board[i][j])return false;
        board[i][j]='*';
        
        bool ans=solve(board,word,i+1,j,k+1,r,c) 
            or solve(board,word,i-1,j,k+1,r,c)
            or solve(board,word,i,j+1,k+1,r,c)
            or solve(board,word,i,j-1,k+1,r,c);
            board[i][j]=word[k];
            return ans;
    }
    
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        int r=board.size();
        int c=board[0].size();
        int num=0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(word[num]==board[i][j])
                  if(solve(board,word,i,j,num,r,c))return true;
            }
        }
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends