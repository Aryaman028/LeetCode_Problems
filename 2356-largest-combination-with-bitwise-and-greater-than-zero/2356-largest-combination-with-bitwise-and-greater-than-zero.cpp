class Solution {
public:
    void toBinaryAndCount(int num,vector<int>&res){
        string a="";
        int c=0;
        while(num>0){
            int d = num%2;
            if(d==1)res[c]++;
            c++;
            // a += to_string(d);
            num/=2;
        }
        // for(int i=0;i<a.length();i++){
        //     if(a[i]=="1")res[i]++;
        // }
    }

    int largestCombination(vector<int>& candidates) {
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