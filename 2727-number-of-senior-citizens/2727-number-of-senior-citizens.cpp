class Solution {
public:
    int countSeniors(vector<string>& details) {
        int result = INT_MIN;
        int c=0;
        for(auto val:details){
            for(int i=0;i<val.length();i++){
                if(isalpha(val[i])){
                    int age = (val[i+1]-'0')*10 + val[i+2]-'0';  //char to int and then making it 2 digit number
                    if(age>60)c++;
                }
            }
        }
        return c;
    }
};