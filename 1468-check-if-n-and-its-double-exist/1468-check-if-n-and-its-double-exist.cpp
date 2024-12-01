class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int>s;
        for(auto ele:arr){
            if((s.find(ele/2)!=s.end() && ele%2==0)  || s.find(ele*2)!=s.end()){
                return true;
            }
            s.insert(ele);
        }
        return false;
    }
};