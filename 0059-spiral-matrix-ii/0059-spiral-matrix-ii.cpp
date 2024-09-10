class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>v(n,vector<int>(n));
        int j=1;
        int left =0;
        int right = n-1;
        int top = 0;
        int bottom = n-1;
        while(left<=right && top<=bottom){
            for(int i=left;i<=right;i++){
                v[top][i]=j;
                j++;
            }
            top++;
            for(int i=top;i<=bottom;i++){
                v[i][right]=j;
                j++;
            }
            right--;
            if(top<=bottom){
                for(int i=right;i>=left;i--){
                    v[bottom][i]=j;
                    j++;
                }
            }
            bottom--;
            if(left<=right){
                for(int i=bottom;i>=top;i--){
                    v[i][left]=j;
                    j++;
                }
            }
            left++;
        }
        return v;
    }
};