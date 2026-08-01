class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string word = q.front().first;
            int len = q.front().second;
            if(word == endWord) {
                return len;
            }
            q.pop();
            for(int i = 0; i < word.size(); i++){
                char ch = word[i];
                for(char j = 'a'; j <= 'z'; j++){
                    word[i] = j;
                    if(st.find(word) != st.end()){
                        q.push({word,len + 1});
                        st.erase(word);
                    }
                }
                word[i] = ch;
            }
        }
        return 0;
    }
};