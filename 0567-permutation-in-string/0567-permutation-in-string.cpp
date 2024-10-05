class Solution {
public:
bool check(unordered_map<char,int>m,string &a){
    for(int i=0;i<a.length();i++){
        m[a[i]]--;
    }
    for(auto ele:m){
        if(ele.second!=0){
            return false;
        }
    }
    return true;
}
// void permutations(set<string>&s,string &a,int i){
//     int n = a.length();
//     if(i==n){
//         // v.push_back(a);
//         s.insert(a);
//         return;
//     }

//     for(int j=i;j<n;j++){
//         swap(a[i],a[j]);
//         permutations(s,a,i+1);
//         swap(a[i],a[j]);
//     }
// }
    bool checkInclusion(string s1, string s2) {
        // set<string>s;
        // permutations(s,s1,0);
        // if(s1.length()==2 && s2.length()==2){
        //     string b=s1;
        //     reverse(b.begin(),b.end());
        //     if(s2==s1 || s2==b)return true;
        //     else return false;
        // }
        unordered_map<char,int>m;
        for(int i=0;i<s1.length();i++){
            m[s1[i]]++;
        }
        int n=s1.length();
        for(int i=0;i<s2.length();i++){
            string a = s2.substr(i,n);
            if(check(m,a)){
                return true;
            }
            // if(s.find(a)!=s.end()){
            //     return true;
            // }
        }
        return false;
    }
};