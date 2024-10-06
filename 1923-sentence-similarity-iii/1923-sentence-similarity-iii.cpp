class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        stringstream ss(sentence1);
        stringstream ab(sentence2);
        vector<string>v1;
        vector<string>v2;
        string ele;
        while(ss>>ele){
            v1.push_back(ele);
        }
        while(ab>>ele){
            v2.push_back(ele);
        }
        int start=0;
        int end1=v1.size()-1;
        int end2=v2.size()-1;
        // checking from front
        while(start<end1+1 && start<end2+1 && v1[start]==v2[start]){
                start++;
                cout<<start<<" ";
        }
        while(end1>=0 && end2>=0 && v1[end1]==v2[end2]){
                end1--;
                end2--;
                cout<<end1<<" "<<end2;
            
        }
        return start>end1 || start>end2;
    }
};