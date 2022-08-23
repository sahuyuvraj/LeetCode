class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        
        if(s1.size()<s2.size()) swap(s1,s2);
        // if(count(s2.begin(),s2.end(),' ')==0){
        //     return s1.find(s2)==0;
        // }
       
        vector<string>v1,v2;
        
        stringstream curr1(s1);
        string temp;
        while(curr1>>temp)v1.push_back(temp);
        stringstream curr2(s2);
        while(curr2>>temp)v2.push_back(temp);
        
        int l=0;
        int n1=v1.size()-1,n2=v2.size()-1;
        
        while(l<v2.size() and v1[l]==v2[l])l++;
        
        while(n2>=0 and v1[n1]==v2[n2])n1-=1,n2-=1;
        
        return l>n2;
    }
};