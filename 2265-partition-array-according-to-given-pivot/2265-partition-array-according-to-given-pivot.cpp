class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int>v1;
        vector<int>v2;
        int countPivot = 0;
        for(int ele:nums){
            if(ele < pivot){
                v1.push_back(ele);
            }else if(ele > pivot) v2.push_back(ele);
            else countPivot++;
        }
        int j=0;
        for(int i=0;i<v1.size();i++){
            nums[j++] = v1[i];
        }
        for(int i=0;i<countPivot;i++){
            nums[j++] = pivot;
        }
        for(int i=0;i<v2.size();i++){
            nums[j++] = v2[i];
        }
        return nums;
    }
};