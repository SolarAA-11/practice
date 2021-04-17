
#include "common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        else if (strs.size() == 1) return strs.front();
        size_t pos = 0;
        while(true) {
            if (pos >= strs.front().size()) break;
            char c = strs.front()[pos];
            bool all_same = true;
            for (int i = 1; i < strs.size(); ++i) {
                if (pos >= strs[i].size() || strs[i][pos] != c) {
                    all_same = false;
                    break;
                }
            }
            if (!all_same) break;
            else pos++;
        }
        return strs.front().substr(0, pos);
    }
};

int main() {
    Solution s;
}
