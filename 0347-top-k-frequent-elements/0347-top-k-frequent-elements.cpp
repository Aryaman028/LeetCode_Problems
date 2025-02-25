class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 2ND APPROACH USING PRIORITY QUEUE WHICH WILL AUTOMATICALLY SET THE HIGHEST FREQUENCY AT THE TOP IF WE INSERT THE FREQUENCY IN THE FIRST POSITION OF PAIR
      
        unordered_map<int,int>m;
        vector<int>res;
        for(auto ele:nums){
            m[ele]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto ele:m){
            pq.push({ele.second,ele.first});
        }

        for(int i=0;i<k;i++){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};