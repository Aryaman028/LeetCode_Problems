class Solution {
public:
    void order(int n,vector<int>&v,int i){
        if(i>n)return;
        v.push_back(i);
        for(int append=0;append<=9;append++){
            int new_num = i*10+append;
            if(new_num<=n)order(n,v,new_num);
            else break;
        }
        
    }
    vector<int> lexicalOrder(int n) {
        //Brute force
        // vector<string>v;
        // for(int i=1;i<=n;i++){
        //     v.push_back(to_string(i));
        // }
        // sort(v.begin(),v.end());    //O(nlogn)
        // vector<int>res;
        // for(int i=0;i<n;i++){
        //     res.push_back(stoi(v[i]));
        // }
        // return res;
        //Optimal approach cant be done bcz i haven't studied trie till now
        vector<int>v;
        for(int i=1;i<=9;i++){
            order(n,v,i);
        }
        // order(n,v,1);
        return v;
        
    }
};