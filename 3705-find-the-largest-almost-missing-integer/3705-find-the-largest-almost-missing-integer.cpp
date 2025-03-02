class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<set<int>> ans;
        for(int i=0; i<nums.size()-k+1; i++){
            set<int>s;
            for(int j=i; j<i+k; j++){
                s.insert(nums[j]);
                cout<<nums[j]<<" ";
            }
            cout<<endl;
            ans.push_back(s);
        }
        set<int> ss;
        for(int i=0; i<nums.size(); i++){
            ss.insert(nums[i]);
        }
        int answer = -1;
        for(auto it : ss){
            int count = 0;
            for(int i=0; i<ans.size(); i++){
                if(ans[i].find(it) != ans[i].end()){
                    count++;
                }
            }
            if(count == 1){
                answer = it;
            }
        } 


        return answer;
    }
};