class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        // vector<vector<int>>res;
        sort(skill.begin(),skill.end());
        int start = 0;
        long end = skill.size()-1;
        long sum=skill[start]+skill[end];
        long long p=0;
        while(start<end){
            // vector<int>v;
            if(sum!=skill[start]+skill[end]){
                return -1;
            }
            p+=skill[start]*skill[end];
            start++;
            end--;
        }
        return p;
        
    }
};