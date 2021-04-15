//
// Created by SolarDomo on 2021/4/14.
//


#include "common.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> char_set;
        decltype(s.size()) begin = 0, end = 0, length = s.size(), ans = 0;
        while(begin != length) {
            if (char_set.count(s[end]) != 0 || end == length) {
                char_set.erase(s[begin++]);
            } else {
                char_set.insert(s[end++]);
                ans = max(ans, end - begin);
            }
        }
        return ans;
    }
};
