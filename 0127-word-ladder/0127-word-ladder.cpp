class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>s(wordList.begin(),wordList.end());

        queue<pair<string,int>>q;

        q.push({beginWord,1});

        while(!q.empty()){
            int n = q.size();

            while(n--){
                auto cur = q.front();
                string word = cur.first;
                int val = cur.second;

                if(word == endWord){
                    return val;
                }
                q.pop();
                for(int i = 0; i < word.size(); i++){
                    string ori = word;
                    for(int j = 'a'; j <='z'; j++){
                        ori[i] = (char)j;

                        if(s.count(ori) > 0){
                            q.push({ori,val + 1});
                            s.erase(ori);
                        }
                    }
                }
            }
        }
        return 0;
    }
};