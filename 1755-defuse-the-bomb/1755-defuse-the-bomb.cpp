class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int>res(code.size());
        if(k>0){
            for(int i=0;i<code.size();i++){
                for(int j=i+1;j<i+1+k;j++){
                    res[i]+=code[j%code.size()];
                }
            }
        }else if(k==0){
            for(int i=0;i<code.size();i++){
                res[i]=0;
            }
        }else{
            k = abs(k);
            reverse(code.begin(),code.end());
             for(int i=0;i<code.size();i++){
                for(int j=i+1;j<i+1+k;j++){
                    res[i]+=code[j%code.size()];
                }
            }
            reverse(res.begin(),res.end());
        }
        return res;
    }
};