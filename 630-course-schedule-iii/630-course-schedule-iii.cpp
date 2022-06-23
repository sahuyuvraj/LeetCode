class Solution {
public:
    bool static cmp(vector<int> &a,vector<int> &b)
    {
        if(a[1]==b[1])
        {
            return a[0]<b[0];
        }
        return a[1]<b[1];
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),cmp);        
        int prev=0,n=courses.size();
        priority_queue<int>pq;
        
        for(int i=0;i<n;i++){
            if(prev+courses[i][0]<=courses[i][1]){
                prev+=courses[i][0];
                pq.push(courses[i][0]);
            }else if(pq.size() and courses[i][0]<pq.top()){
                int ele=pq.top();pq.pop();
                prev-=ele;
                pq.push(courses[i][0]);
                prev+=courses[i][0];
            }
        }
        return pq.size();
    }
};