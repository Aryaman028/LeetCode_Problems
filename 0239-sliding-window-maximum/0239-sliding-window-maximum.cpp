class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int>dq;
        vector<int>v;
        int n = nums.size();
        //storing first k elements in deque
        for(int i=0;i<k;i++){
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        for(int i=k;i<n;i++){
            v.push_back(nums[dq.front()]);

            // window size if exceeds then remove the front element
            while(!dq.empty() && i-dq.front()>=k){
                dq.pop_front();
            }

            //remove all ele which are less than the cur number
            while(!dq.empty() && nums[dq.back()]<=nums[i]){
                dq.pop_back();
            }
            dq.push_back(i);
        }
        //push the last window max ele
        v.push_back(nums[dq.front()]);
        return v;
    }
};