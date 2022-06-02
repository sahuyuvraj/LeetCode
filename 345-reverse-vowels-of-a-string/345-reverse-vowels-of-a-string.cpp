class Solution {
public:
    bool isVowel(char c){
        c=tolower(c);
        return c=='a' or c=='e' or c=='i' or c=='o' or c=='u';
            //or c=='A' or c=='E' or c=='I' or c=='O' or c=='U';
    }
    string reverseVowels(string s) {
        int i=0,j=s.size()-1;
        while(i<j){
            while(i<s.size() and !isVowel(s[i]))i++;
            while(j>=0 and !isVowel(s[j]))j--;
            if(i<j)swap(s[i++],s[j--]);
        }
            return s;
    }
};