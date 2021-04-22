
#include "common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int len = 1;
        while(true) {
            bool great = true;
            for (const auto &item : strs) {
                if (item.size() < len || item[len - 1] != strs[0][len - 1]) {
                    great = false; break;
                }
            }
            if (!great) {
                len--; break;
            } else len++;
        }
        return strs[0].substr(0, len);
    }
};

int main() {
    Solution s;
}
