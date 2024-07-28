class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>s;
        vector<int>v;
        map<int,int>m;
        for(int i=0;i<nums2.size();i++){
            while(!s.empty() && nums2[s.top()]<nums2[i]){
                m[nums2[s.top()]]=nums2[i];
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()){
            m[nums2[s.top()]]=-1;
            s.pop();
        }
        for(int i=0;i<nums1.size();i++){
            v.push_back(m.at(nums1[i]));
        }
        return v;
    }
};