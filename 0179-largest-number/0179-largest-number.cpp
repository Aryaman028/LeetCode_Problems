class Solution {
public:
    // bool cmp(string &a , string &b){
    //     if(a+b>b+a)return true;
    //     return false;
    //     // return (a + b) < (b + a);
    // }
    string largestNumber(vector<int>& nums) {
        vector<string>res;
        for(int i=0;i<nums.size();i++){
            res.push_back(to_string(nums[i]));
        }
        sort(res.begin(),res.end(),[](string &a,string &b){
            return a+b > b+a;
        });
        if(res[0]=="0")return "0";
        string fin="";
        for(int i=0;i<res.size();i++){
            fin+=res[i];
        }
        return fin;
    }
};