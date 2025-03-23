class Solution {
public:
    void create(int open, int close, string res,int n, vector<string>&output){
        if(close == n){
            output.push_back(res);
            return;
        }
        if(open > n)return;

        if(open > close){
            create(open, close + 1, res + ')', n, output);
        }
        create(open + 1, close, res + '(', n, output);
    }

    vector<string> generateParenthesis(int n) {
        vector<string>output;
        create(0, 0, "", n, output);
        return output;
    }
};