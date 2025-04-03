class Solution {
public:
    int characterReplacement(string s, int k) {
        //BRUTE FORCE APPROACH USING N SQUARE


        // int len = 0;
        // for(int i = 0; i < s.length(); i++){
        //     unordered_map<char,int>m;
        //     int maxFreq = 0;

        //     for(int j = i; j < s.length(); j++){
        //         // storing freq of char in map to get the maxiimu freq char
        //         m[s[j]]++;   
        //         maxFreq = max(maxFreq,m[s[j]]);   //count of the maximum freq

        //         int window = j - i + 1;
        //         int change = window - maxFreq;     //if we subtract from the window then we get to know how many chars are different from the maxFreq char which should be less than k

        //         if(change <= k){
        //             len = max(len , window);
        //         }
        //     }
        // }
        // return len;



        //SLIDIING WINDOW

        int i = 0, j = 0;
        unordered_map<char,int>m;
        int maxFreq = 0;
        int maxi = 0;
        int n = s.length();
        while(j < n){
            m[s[j]]++;   
            maxFreq = max(maxFreq,m[s[j]]);   //count of the maximum freq

            int window = j - i + 1;
            int change = window - maxFreq;     

            if(change > k){
                m[s[i]]--;   //shrink when there is changeChar larger than k
                i++;
            }
            //when we did i++ then window size got changed thus cant use window variable
            maxi = max(maxi, j - i + 1);
            j++;
            
        }
        return maxi;
    }
};