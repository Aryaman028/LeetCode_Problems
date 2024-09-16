class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        sort(timePoints.begin(),timePoints.end());
        int n = timePoints.size();
        int res= INT_MAX;
        vector<int>minutes(n);

        //count the minutes of all the elements
        for(int i=0;i<n;i++){
            int hours = stoi(timePoints[i].substr(0,2));
            int minute = stoi(timePoints[i].substr(3,2));
            minutes[i]=hours*60 + minute; 
        }
        //find the differnce of the adjacent element and min of it
        for(int i=1;i<n;i++){
            res=min(res,minutes[i]-minutes[i-1]);
        }

        //the first and last element which will cause the main error
        int fin = 1440 - minutes[n-1] + minutes[0];
        res = min(res,fin);
        return res;
        
        
    }
};