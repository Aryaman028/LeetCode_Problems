class Solution {
public:
    static bool comp(pair<int,int>a,pair<int,int>b){
        return a.second > b.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        vector<int>res;
        for(auto ele:nums){
            m[ele]++;
        }
        vector<pair<int,int>>v;
        for(auto ele:m){
            v.push_back(make_pair(ele.first,ele.second));
        }
        sort(v.begin(),v.end(),comp);

        for(int i=0;i<k;i++){
            res.push_back(v[i].first);
        }
        return res;

    }
};