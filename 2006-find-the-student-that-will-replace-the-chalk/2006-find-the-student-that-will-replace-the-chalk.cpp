class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n =chalk.size();
        int i=0;
        long sum=0;
        for(int i=0;i<chalk.size();i++){
            sum+=chalk[i];
        }
        k=k%sum;
        while(i<n){
            if(k<chalk[i]){
                return i;
            }else{
                k=k-chalk[i];
            }
            i++;
        }
        return 0;
    }
};