class MyCalendar {
public:
    map<int,int>mp;
    
    MyCalendar() {
        mp.clear();
    }
    
    bool book(int start, int end) {
    auto itr=mp.upper_bound(start);
        if(itr==mp.end() or itr->second>=end){
            mp[end]=start;
            return true;
        }
        
    return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */