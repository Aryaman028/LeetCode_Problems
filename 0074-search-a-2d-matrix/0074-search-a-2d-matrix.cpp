class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = n*m-1;
        while(left<=right){
            int mid = left + (right - left)/2;
            int ele = matrix[mid/m][mid%m];
            if(ele==target){
                return true;
            }else if(ele<target){
                left=mid+1;
            }else right=mid-1;
        }
        return false;
    }
};