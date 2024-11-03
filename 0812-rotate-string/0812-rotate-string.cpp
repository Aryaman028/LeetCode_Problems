class Solution {
public:
    bool rotateString(string s, string goal) {
        //TC -> O(N) 
        //Erasing the first ele and putting it on the last this causes one shifts and comparing at each shift with the goal
        int n = s.length();
        for(int i=0;i<n;i++){
            if(s==goal)return true;
            s+=s[0];
            s.erase(0,1);
        }
        return false;
    }
};