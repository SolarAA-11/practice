
#include "common.h"

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        size_t word_count = words.size(), word_size = words[0].size();
        unordered_map<string, int> word_counter;
        for_each(words.begin(), words.end(), [&](string& s){word_counter[s]++;});
        for (int st = 0; st + word_count * word_size <= s.size(); ++st) {
            unordered_map<string, int> sliding_counter;
            bool ok = true;
            for (int i = 0; i < word_count; ++i) {
                string sub_str = s.substr(st + i * word_size, word_size);
                sliding_counter[sub_str]++;
                if (sliding_counter[sub_str] > word_counter[sub_str]) {
                    ok = false; break;
                }
            }
            if (ok) result.push_back(st);
        }
        return result;
    }
};

int main() {
    Solution s;
}
