class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b){
    return a[0] == b[0] ? a[1] < b[1] : a[0] > b[0];
}

int numberOfWeakCharacters(vector<vector<int>>& properties) {
    sort(properties.begin(), properties.end(), comp);
    
	//mx will store the maximum defence.
    int mx = 0, cnt = 0;
    
    for(auto &p: properties){
        if(p[1] < mx) cnt++;
        mx = max(mx, p[1]);
    }
    
    return cnt;
}
};