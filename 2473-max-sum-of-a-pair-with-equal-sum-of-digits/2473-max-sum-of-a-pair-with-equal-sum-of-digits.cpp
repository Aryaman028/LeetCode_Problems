class Solution {
public:
    int convert(int a){
        string b = to_string(a);
        int i,n=0;
        while(i<b.length()){
            n+=b[i++]- '0';
        }
        return n;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,int>m;
        int max_val =-1;
        for(int i=0;i<nums.size();i++){
            int a = convert(nums[i]);

            if(m.find(a)!=m.end()){
                max_val = max(max_val,nums[i] + m[a]);
                if(nums[i]>m[a]){
                    m[a]=nums[i];
                }
            }else m[a]=nums[i];
        }
        return max_val;
    }
};