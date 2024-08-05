class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        // unordered_map<string,int>m;
        // for(string i :arr)
        // {
        //     m[i]++;
        // }
        // int j=0;
        // for(auto val : m){
        //     if(val.second==1){
        //         j++;
        //     }
        //     if(k==j){
        //         return val.first;
        //     }
        // }
        // return "";
        vector<int>fre(arr.size());
        for(int i=0;i<arr.size();i++){
            int c=1;
            for(int j=i+1;j<arr.size();j++){
                if(arr[i]==arr[j]){
                    c++;
                    arr[j]="";
                }
            }
            fre[i]=c;
        }
        int i=0;
        while(true){
            if(i==arr.size()){
                return "";
            }
            if(fre[i]==1 && arr[i]!=""){
                k--;
            }
            if(k==0)return arr[i];
            i++;
        }
        return "";
    }
};