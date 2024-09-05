class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {

        int l = rolls.size();
        int sum=0;
        for(int i=0;i<l;i++){
            sum+=rolls[i];
        }
        int required_sum = (n + l)*mean - sum;
        int mod_value = required_sum%n;
        int divide_value = required_sum/n;
        if(divide_value>6 || divide_value<1)return {};
        vector<int>res(n,divide_value);
        int i=0;
        while(mod_value!=0){
            res[i]++;
            if(res[i]>6)return {};
            mod_value--;
            i++;
        }
        return res;
    }
};