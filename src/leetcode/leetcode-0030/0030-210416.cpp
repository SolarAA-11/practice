
#include "common.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        unordered_map<string, unsigned> counter1, counter2;
        for (string& str: words) counter2[str]++;
        unsigned word_len = words.front().size(), word_count = words.size();
        for (int i = 0; i + word_len * word_count <= s.size(); ++i) {
            counter1.clear();
            bool ok = true;
            for (int j = 0; j < word_count; ++j) {
                string  sub_str = s.substr(i + j * word_len, word_len);
                counter1[sub_str]++;
                if (counter1[sub_str] > counter2[sub_str]) {
                    ok = false; break;
                }
            }
            if (ok) result.push_back(i);
        }
        return result;
    }
};