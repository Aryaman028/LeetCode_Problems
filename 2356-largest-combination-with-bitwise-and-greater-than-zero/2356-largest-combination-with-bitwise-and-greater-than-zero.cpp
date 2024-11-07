class Solution {
public:
    void toBinaryAndCount(int num,vector<int>&res){
        string a="";
        int c=0;
        while(num>0){
            int d = num%2;
            if(d==1)res[c]++;
            c++;
            num/=2;
        }
    }

    int largestCombination(vector<int>& candidates) {
        //Brute force - 
        //taking the vector of 24 size to store all the indexes of the binary number and then we will increment the ele inside the index where the 1 is present in the 
        // binary number like 100 1 is present at 2nd posi from left thus we will increment the 2nd index value hence we will 
        // get at which position we are getting most number of 1s
        vector<int>res(24,0);
        for(int i=0;i<candidates.size();i++){
            toBinaryAndCount(candidates[i],res);
        }
        int max_val = INT_MIN;
        for(auto ele: res){
            max_val = max(max_val,ele);
        }
        return max_val;
    }
};
