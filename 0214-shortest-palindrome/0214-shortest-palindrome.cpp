class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        int n=s.size();
        int index=0;
        reverse(rev.begin(),rev.end());
        for(int i=0;i<n;i++){
            // if(s.substr(0,n-i)==rev.substr(i)){     //this will cause TLE as substr have TC-O(n)
            //     index=i;
            //     break;
            // }
            if(!memcmp(s.c_str(),rev.c_str()+i,n-i)){
                index=i;
                break;
            }
        }
        return rev.substr(0,index)+s;
    }
};