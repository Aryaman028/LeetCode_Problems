class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>>res;
        int i=0;
        int n=intervals.size();
        while(i<intervals.size()-1){
            //overlaping condition
            vector<int> a = intervals[i];
            vector<int> b = intervals[i+1];
            vector<int>v;
            if(max(a[0],b[0])<=min(a[1],b[1])){
                // a[0]=a[0];
                // a[1]=b[1];
                v.push_back(min(a[0],b[0]));
                v.push_back(max(a[1],b[1]));
                intervals[i]=v;
                intervals.erase(intervals.begin()+i+1);
            }else{
                i++;
            }
        }
        return intervals;
        
    }
};