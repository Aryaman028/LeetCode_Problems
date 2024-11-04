class Solution {
public:
    string compressedString(string word) {
        //Whenever a diff char occurrs add the count and the string into the comp but if last char occurs more than one time then we have to add it to the comp at last also and considering the 9 whenever the count goes above 9 add it to the comp and made the count to 1
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
