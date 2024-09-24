class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        //BRUTE FORCE    doing the question with O(n^3)
        //1st loop for iterating 1st array 2nd loop for iterating 2nd array
        //3rd loop for comparing by the memcmp method  
        // vector<string>str1;
        // vector<string>str2;
        // for(int i=0;i<arr1.size();i++){
        //     str1.push_back(to_string(arr1[i]));
        // }
        // for(int i=0;i<arr2.size();i++){
        //     str2.push_back(to_string(arr2[i]));
        // }
        // // sort(str1.begin(),str1.begin());
        // // sort(str2.begin(),str2.begin());
        // int len = 0;
        // for(int i=str1.size()-1;i>=0;i--){
        //     for(int j=str2.size()-1;j>=0;j--){
        //         string a = str1[i];
        //         string b = str2[j];
        //         int l = min(a.length(),b.length());
        //         for(int k=l;k>=1;k--){
        //             if(!memcmp(a.c_str(),b.c_str(),k)){
        //                 len = max(len,k);
        //             }
        //         }
        //     }
        // }
        // return len;
        vector<string>str1;
        vector<string>str2;
        for(int i=0;i<arr1.size();i++){
            str1.push_back(to_string(arr1[i]));
        }
        for(int i=0;i<arr2.size();i++){
            str2.push_back(to_string(arr2[i]));
        }
        set<string>s;
        //insert all the possible prefixes of all the elements in the set
        for(int i=0;i<str1.size();i++){
            for(int j=1;j<=str1[i].size();j++){
                s.insert(str1[i].substr(0,j));
            }
        }
        //now compare with the str2
        int len = 0;
        for(int i=0;i<str2.size();i++){
            for(int j=1;j<=str2[i].size();j++){
                string a = str2[i].substr(0,j);
                if(s.find(a)!=s.end()){
                    len=max(len,j);
                }
            }
        }
        return len;        

    }
};