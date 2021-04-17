
#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> c_set;
        size_t max_len = 0;
        size_t pst = 0, pend = 0, end = s.size();
        while(pend != end) {
            while(c_set.count(s[pend]) != 0)
                c_set.erase(s[pst++]);
            c_set.insert(s[pend++]);
            max_len = max(max_len, pend - pst);
        }
        return max_len;
    }
};

int main() {
    Solution s;
}
