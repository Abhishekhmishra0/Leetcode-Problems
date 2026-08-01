class Solution {
public:
    int ladderLength(string start, string end, vector<string>& words) {
        int n = words.size();
        queue<pair<string,int>> q;
        q.push({start, 1});
        int len = 0;
        set<string> st(words.begin(), words.end());
        while(!q.empty()) {
            auto it = q.front();
            q.pop();
            string word = it.first;
            len = it.second;
            if(word == end) {
                return len;
            }
            for(int i = 0; i < word.size(); i++) {
                char ch = word[i];
                for(char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if(st.find(word) != st.end()) {
                        q.push({word, len + 1});
                        st.erase(st.find(word));
                    }
                }
                word[i] = ch;
            }
        } 
        return 0;
    }
};