class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int>res=arr;
        sort(res.begin(),res.end());    //O(nlogn)
        map<int,int>m;
        //after sorting storing all the indices in the map with the element as key
        int i=0;
        int k=1;
        while(i<arr.size()){    
            if(m.find(res[i])==m.end()){
                m[res[i]]=k++;
            }
            i++;
        }
        vector<int>v(arr.size());
        for(int i=0;i<arr.size();i++){
            v[i]=m[arr[i]];
        }
        return v;
        
    }
};