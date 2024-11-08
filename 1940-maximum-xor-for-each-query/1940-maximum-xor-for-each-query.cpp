class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n = nums.size();
        vector<int>pre(n);
        pre[0]=nums[0];
        //Finding the prefix sum of the nums
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] ^ nums[i];
        }
        vector<int>res;
        int bit = pow(2,maximumBit)-1;
        
        //we want the maximum value so cosidering 
        // pre = [0,1,0,3]  to make 0 the maximum XOR we want k=3 thus only 0^3 will be 3. Now to make 1 the maximum XOR we want k=2 thus 2^1 will be 3 now think in reverse order what if we XOR 1 with the 3 it will give 2 that is the k value.

        for(int i=n-1;i>=0;i--){
            res.push_back(bit^pre[i]);
        }

        return res;
    }
};