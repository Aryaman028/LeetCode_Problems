class Solution {
public:

    string frequencySort(string s) {
        unordered_map<char,int>mp;

        for(auto ch:s){
            mp[ch]++;
        }
        priority_queue<pair<int,char>>pq;

        for(auto ele:mp){
            pq.push({ele.second,ele.first});
        }
        
        string res ="";
        while(!pq.empty()){
            //Inbuilt function to assign the string with number of frequency
            res += string(pq.top().first,pq.top().second);
            pq.pop();
        }
        return res;
        
        
    }
};