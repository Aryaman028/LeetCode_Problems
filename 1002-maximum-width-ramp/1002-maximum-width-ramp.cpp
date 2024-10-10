class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        //BRUTE FORCE 
        //USED NESTED LOOP ONE FROM START AND SECOND FROM THE END 
        //AND WHENEVER WE ACCOUNTER OUR CONDITION THEN BREAK TC->O(N*N)  WHICH CAUSED TLE

        //OPTIMAL APPROACH
        //USED STACK WHICH WILL BE MIN STACK WHICH STORES THE MIN ELEMENT 
        //INDEX ALWAYS ON THE TOP AND THEN TRAVERSING FROM THE BACK WE WILL 
        //CHECK THE GIVEN CONDITION AND POP THE MIN INDEX

        stack<int>st;
        int res=0;
        for(int i=0;i<nums.size();i++){
            //pushing all the indexs of the min ele
            if(st.empty() || nums[st.top()]>nums[i]){
                st.push(i);
            }
        }
        for(int j=nums.size()-1;j>=0;j--){
            while(!st.empty() && nums[st.top()]<=nums[j]){
                res=max(res,j-st.top());
                st.pop();
            }
        }
        return res;

        
    }
};
