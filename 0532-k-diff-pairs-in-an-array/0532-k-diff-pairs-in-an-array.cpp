class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        //we chould have used 2 pointer approach but the array is not sorted
        //thus we will use hashmap
        // set<int>m;

        // int count=0;

        // for(auto ele:nums){
        //     // if(m.find(ele)==m.end()){    //to eliminate the duplicates pair
        //         if(m.find(k+ele)!=m.end()  || m.find(ele-k)!=m.end()){    //a-b=k then a = k+b b=a-k;
        //             count++;
        //         }
        //     // }
        //     m.insert(ele);
        // }
        // return count;
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = 1;
        set<pair<int,int>>s;
        while(end!=nums.size()){

            int diff = abs(nums[start]-nums[end]);
            
            if(diff==k){
                s.insert(make_pair(nums[start],nums[end]));
                end++;
            }
            else if(diff>k)start++;
            else if(diff<k)end++;

            if(start==end)end++;
        }
        return s.size();
    }
};