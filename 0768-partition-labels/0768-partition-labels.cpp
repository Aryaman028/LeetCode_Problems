class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int>m;

        //storing the last occurrence
        for(int i = 0 ; i < s.length(); i++){
            m[s[i]] = i;
        }

        vector<int>v;
        for(int i = 0 ; i < s.length(); i++){
            //initilizing the lastindex till where we can have the partition
            int lastIndex = m[s[i]];
            string a = "";

            for(int j = i; j <= lastIndex; j++){
                //if the char inside the substring have the lastindex greater than the initial then update the last index as we will take till that index ,
                if(m[s[j]] > lastIndex){
                    lastIndex = m[s[j]];
                }
                a+=s[j];
            }
            i  += a.length() - 1;
            v.push_back(a.length());
        }
        return v;
    }
};