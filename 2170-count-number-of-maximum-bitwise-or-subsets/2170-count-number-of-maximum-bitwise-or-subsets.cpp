class Solution {
public:
     int bt(vector<int>nums,int i,int curOr,int maxVal){
        if(i==nums.size()){
            if(curOr==maxVal)return 1;
            return 0;
        }
        //not take
        int takeing = bt(nums,i+1,curOr,maxVal);

        //take
        int nottaking = bt(nums,i+1,curOr|nums[i],maxVal);
        return takeing + nottaking;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        vector<int>pre(nums.size());
        int num =nums[0];
        int max_val;
        //firstly finding the max possible bitwise or
        for(int i=0;i<nums.size();i++){
            num = num | nums[i];
            pre[i]=num;
            max_val=pre[i];
        }
        //using backtracking finding the subsets and comapring all the final vectors with the max_val
        int count = bt(nums,0,0,max_val);
        return count;
      
    }
};