class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int start=0;
        // int end=k-1;
        // vector<int>v;
        //                                                      //brute force approach
        // for(int i=0;i<=nums.size()-k;i++){
        //     int m=INT_MIN;
        //     for(int j=i;j<i+k;j++){
        //         m=max(m,nums[j]);
        //     }
        //     v.push_back(m);
        // }
        // return v;

                                                    //optimal approach using dequeue
        deque<int>d;
        vector<int>v;
        for(int i=0;i<nums.size();i++){
            if(!d.empty() && d.front()==i-k){
                d.pop_front();        //this means front element of queue is out of boundation
            }
            while(!d.empty() && nums[d.back()]<nums[i]){
                d.pop_back();
            }
            d.push_back(i);
            if(i>=k-1)v.push_back(nums[d.front()]);   //after crossing first k-1 element u will get one ans on every element
        }
        return v;
        
        
    }
};