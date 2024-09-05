class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int top=0;
        int bottom=matrix.size()-1;
        int left = 0;
        int right = matrix[0].size()-1;
        vector<int> num;

        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                num.push_back(matrix[top][i]);
            }
            top++;
            for(int i=top;i<=bottom;i++){
                num.push_back(matrix[i][right]);
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    num.push_back(matrix[bottom][i]);
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    num.push_back(matrix[i][left]);
                }
            }
            left++;
        }
        return num;
    }
};