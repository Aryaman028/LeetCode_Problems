class Solution {
public:
    int maxPower(string s) {
        int  l = 0, r = 0, ans = 0;
        int n = s.length();
        while(r < n){
            if(s[l] != s[r]){
                l = r;
            }

            ans = max(ans, r - l + 1);
            r++;
        }
        return ans;
    }
};