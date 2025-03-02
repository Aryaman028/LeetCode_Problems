class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        vector<vector<int>>res;
        map<int,int>m;

        for(int i = 0; i < nums1.size(); i++){
            m[nums1[i][0]] += nums1[i][1];
        }

        for(int i = 0; i < nums2.size(); i++){
            m[nums2[i][0]] += nums2[i][1];
        }
        int index = 1;
        for(auto ele: m){
            // if(index == ele.first){
                res.push_back({ele.first,ele.second});
            // }else{
                // res.push_back({index,0});
            // }
            // index++;
        }
        return res;
    }
};