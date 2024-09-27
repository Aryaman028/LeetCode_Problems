class MyCalendar {
public:
    vector<pair<int,int>>v;   //storing as pairs
    MyCalendar() {
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if(max(v[i].first,start)<min(v[i].second,end)){
                return false;
            }
        }
        v.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */