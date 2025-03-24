class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        // int m = meetings.size();

        // BRUTE FORCE

        // vector<bool>freeDays(days + 1,true);

        // // as 0 index value will not be considered
        // freeDays[0] = false;

        // for(int i = 0; i < m; i++){
        //     int start = meetings[i][0];
        //     int end = meetings[i][1];

        //     while(start <= end){
        //         freeDays[start++] = false;
        //         busyDays++;
        //     }
        // }
        // int count = 0;
        // for(auto ele : freeDays){
        //     if(ele)count++;
        // }
        // return count;

        // OPTIMAL APPROACH USING MERGINF OF THE 2 OVERLAPING MEETINGS AND THEN SORTING IT. AND THEN SUBTRACTING THE START AND END OF THE ADJASCENT VALUES;

        //overlapping
        vector<vector<int>>lap;
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());

        // for(int i = 1; i < m; i++){
        //     int a1 = meetings[i][0];
        //     int a2 = meetings[i][1];
        //     int b1 = meetings[i-1][0];
        //     int b2 = meetings[i-1][1];

        //     if(max(a1,b1) <= min(a2,b2)){
        //         lap.push_back(min(a1,b1), max(a2,b2));
        //     }
        // }

        // sort(lap.begin(),lap.end());

        int prevEnd = 0;
        int free= 0;

        for(int i = 0; i < meetings.size(); i++){
            int start = meetings[i][0];
            int end = meetings[i][1];
            //no overlapping
            if(prevEnd < start){
                free += start - prevEnd - 1;
            }
            prevEnd = max(prevEnd,end);  
        }
        if (prevEnd < days) {
            free += days - prevEnd;
        }

        // free += days - prevEnd - 1;
        return free;
    }
};