class Solution {
public:
    int findingMax(vector<int>v,int start){
        //It will find the max in the rest of the vector excluding the index it has to swap
        int val = v[start];
        int index=start;
        for(int i=start+1;i<v.size();i++){
            if(val<=v[i]){
                index=i;
                val=v[i];
            }
        }
        return index;
    }
    int convertToNum(vector<int>v,int i,int j){
        //swaping is done here as we dont want to hinder the original vector elements
        swap(v[i],v[j]);
        long res=0;                     //causing error bcz of int
        int n=v.size();
        for(int i=0;i<v.size();i++){
            res = res*10 + v[i];
        } 
        return res;
    }

    int maximumSwap(int num) {
        //Converting the num into vector then At each ele we are finding the next greater ele by the 
        // function [findingMax] and then swaping the elements and 
        // converting the vector into number again and comparing with the original num 

        //TC -> O(N^2)  SC -> O(NUM.LENGTH)

        vector<int>v;
        int temp =num;
        while(temp>0){
            int d = temp%10;
            temp/=10;
            v.push_back(d);
        }
        reverse(v.begin(),v.end());
        int res;
        for(int i=0;i<v.size();i++){
            int j = findingMax(v,i);
            res = convertToNum(v,i,j);
            num = max(res,num);
        }
        return num;
    }
};
