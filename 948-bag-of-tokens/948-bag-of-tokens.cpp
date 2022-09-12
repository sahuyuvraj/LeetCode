class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));
        
        int i=0,j=tokens.size()-1;
        int score=0;
        int ans=0;
        while(i<=j){
           while(i<=j and tokens[i]<=power){
                score++;
                power-=tokens[i];
                i++;
            }
            if(i>=j or score<=0) break;
            score--;
            power+=tokens[j];
            j--;
        }
        return score;
    }
};