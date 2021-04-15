//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    string longestPalindrome(string s) {
        bool dp[1001][1001];
        memset(dp, 0, sizeof(dp));
        auto len = s.size();
        auto ans = make_pair(0,1);
        for(int i = 0;i < len;++i){
            dp[i][1] = true;
            if (i + 2 <= len && s[i] == s[i + 1])
                dp[i][2] = true, ans = make_pair(i, 2);
        }
        for(int substr_len = 3;substr_len <= len;++substr_len) {
            for(int p = 0;p + substr_len <= len;++p) {
                if (s[p] == s[p + substr_len - 1] && dp[p + 1][substr_len - 2]) {
                    dp[p][substr_len] = true;
                    if (substr_len > ans.second)
                        ans = make_pair(p, substr_len);
                }
            }
        }
        return s.substr(ans.first, ans.second);
    }
};

