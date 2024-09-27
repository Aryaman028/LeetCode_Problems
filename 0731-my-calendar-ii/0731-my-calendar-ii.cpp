class MyCalendarTwo {
public:
    vector<pair<int,int>>v;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        for(int i=0;i<v.size();i++){
            if(max(v[i].first,start)<min(v[i].second,end)){
                pair<int,int>p = make_pair(max(v[i].first,start),min(v[i].second,end));
                for(int j=0;j<v.size();j++){
                    if(i!=j && max(v[j].first,p.first)<min(v[j].second,p.second)){
                        return false;
                    }
                }

            }
        }
        v.push_back(make_pair(start,end));
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */