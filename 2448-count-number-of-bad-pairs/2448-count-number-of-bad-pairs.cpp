class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        //We can write nums[i] - i == nums[j] - j as a good pair
        // thus we can store it in the map and then we will subtract it from the total pairs formed by the vector of n size which is n(n-1)/2

        unordered_map<int,int>m;
        long long c=0;
        long long n=nums.size();
        for(int i=0;i<nums.size();i++){
            c+=m[nums[i]-i];
            m[nums[i]-i]++;
        }
        cout<<c;
        return n*(n-1)/2 - c;
    }
};