class Solution {
public:
    vector<pair<int,int>>directions = {{1,0} , {0,1} , {-1,0} , {0,-1}};
    void dfs(vector<vector<int>>& image, int sr, int sc, int color, int sColor){
        if(sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != sColor){
            return;
        }
        image[sr][sc] = color;

        for(auto [r,c] : directions){
            dfs(image, sr + r, sc + c, color, sColor);
        }
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        //we can apply dfs in this as on the cell if it is not of the same color it has to be changed then it will perform dfs and color all the cells which are of the color in the start

        int sColor = image[sr][sc];
        //as there will be no change
        if(sColor == color)return image;

        dfs(image,sr,sc,color, sColor);
        return image;
    }
};