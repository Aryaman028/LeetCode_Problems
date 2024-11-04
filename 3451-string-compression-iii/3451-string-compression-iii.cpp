class Solution {
public:
    string compressedString(string word) {
        string comp ="";
        int count=1;
        char val=word[0];
        for(int i=1;i<word.length();i++){
            if(word[i]==val){
                count++;
                if(count>9){
                    comp+=to_string(9);
                    comp+=val;
                    count=1;
                }
            }else{
                comp+=to_string(count);
                comp+=val;
                val=word[i];
                count=1;
            }
        }
        comp+=to_string(count);
        comp+=val;
        return comp;
    }
};