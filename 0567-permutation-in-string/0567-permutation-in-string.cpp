class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //OPTIMAL APPROACH USING SLIDING WINDOW AND VECTOR FOR STORING FREQUENCY
        int n1=s1.length(),n2=s2.length();
        if(n1>n2)return false;
        vector<int>v1(26,0);
        vector<int>v2(26,0);

        //taking the frequncy of the s1 and the window of s2
        for(int i=0;i<s1.length();i++){
            v1[s1[i]-'a']++;
            v2[s2[i]-'a']++;            //first window fre pushed
        }
        if(v1==v2)return true;

        //using sliding window concept to store the fre of the char 
        // in the window into the vector2 and comparing with the vector1;

        for(int i=n1;i<n2;i++){             
            v2[s2[i]-'a']++;             //adding the next ele fre
            v2[s2[i-n1]-'a']--;          //removing the first ele fre as to maintain the window
            if(v1==v2)return true;
        }
        return false;
    }
};