class Solution {
public:
    bool canweplace(vector<vector<char>>& board,int row,int col, char num){
        for(int i=0;i<board.size();i++){
            if(board[i][col]==num)return false;
        }
        for(int i=0;i<board[0].size();i++){
            if(board[row][i]==num)return false;
        }
        int a=row/3 * 3;
        int b=col/3 * 3;
        for(int i=a;i<a+3;i++){
            for(int j=b;j<b+3;j++){
                if(board[i][j]==num)return false;
            }
        }
        return true;

    }
    bool helper(vector<vector<char>>&board,int row,int col){
        if(col==9){  //go to the next row and make the col zero
            return helper(board,row+1,0);
        }
        if(row==board.size()){   //sudoku solved
            return true;   
        }
        if(board[row][col]!='.'){      //If any number is there then move to col+1
            return helper(board,row,col+1);
        }
        if(board[row][col]=='.'){
            for(int k=1;k<=9;k++){
                char val = k + '0';
                if(canweplace(board,row,col,val)){
                    board[row][col] = val;
                    if(helper(board,row,col+1))return true;
                    board[row][col] = '.';
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        int row=0;
        int col=0;
        helper(board,row,col);

    }
};