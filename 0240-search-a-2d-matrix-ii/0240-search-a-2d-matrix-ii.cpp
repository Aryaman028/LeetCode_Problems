class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //BRUTE FORCE 
        //USING THE 2 NESTED LOOP WHICH WILL CAUSE O(N^2)

        //OPTIMAL SOLUTION 
        //STARTING FROM THE TOP RIGHT CORNER IF LESS THAN THE TARGET THEN MOVE         DOWNWARDS IF GREATER THAN TARGET MOVE TOWARDS LEFT
        //TC->O(M+N)  SC->O(1)

        int m=matrix.size();
        int n=matrix[0].size();
        int i=0;
        int j=n-1;
        while(i<m && j>=0){
            if(target==matrix[i][j])return true;
            else if(target>matrix[i][j])i++;
            else j--;
        }
        return false;


        
    }
};