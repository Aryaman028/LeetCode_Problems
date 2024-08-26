class Solution {
public:
    bool isvowel(char x){
        if(x=='a' || x=='e' || x=='i' || x=='o' || x=='u' || x=='A' || x=='E' || x=='I' || x=='O' || x=='U' ){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {
        int left=0;
        int right=s.length()-1;
        while(left<right){
            if(isvowel(s[left]) && isvowel(s[right])){
                swap(s[left],s[right]);
                left++;
                right--;
            }else if(!isvowel(s[left])){
                left++;
            }else if(!isvowel(s[right])){
                right--;
            }else{
                left++;
                right--;
            }
        }
        return s;
    }
};