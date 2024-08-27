class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int val = 0 - nums[i];
            int left = i+1;
            int right = n-1; 
            while(left<right){
                int sum = nums[i] + nums[left] + nums[right];
                if(sum==0){
                    res.push_back({nums[i],nums[left],nums[right]});
                
                    while(left<right && nums[left]==nums[left+1])left++;
                    while(left<right && nums[right-1]==nums[right])right--;

                    left++;
                    right--;
                }else if(sum<0){
                    left++;
                }else right--;
            }
        }
        return res;
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        //THIS APPROACH IS GIVING TIME EXCEEDED AS IT IS NOT AVOIDING THE DUPLICATE ELEMENTS
        
        // int n = nums.size();
        // vector<vector<int>>final;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<n;i++){
        //     int val1 = -1*nums[i];
        //     multimap<int,int>m;
        //     for(int j=i+1;j<n;j++){
        //         int val2 = val1 - nums[j];
        //         if(m.find(val2)!=m.end()){
        //             vector<int>res;
        //             res.push_back(nums[i]);    
        //             int val3 = m.find(val2)->first;
        //             res.push_back(val3);
        //             res.push_back(nums[j]);
        //             if(!res.empty()) final.push_back(res);
        //         }else{
        //             m.insert(make_pair(nums[j],1));
        //         }
        //     }
        // }
        // set<vector<int>> s(final.begin(), final.end());  //assigning vector to the set to remove duplicates
        // final.assign(s.begin(), s.end());      //assigning set again to the vector
        // return final;
    }
};