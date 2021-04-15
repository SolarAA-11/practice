//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[25][35];
        auto s_len = s.size(), p_len = p.size();

        memset(dp, 0, sizeof(dp));
        dp[0][0] = true;
        for(unsigned i = 0; i <= s_len;++i) {
            for(unsigned j = 1;j <= p_len;++j) {
                if (p[j - 1] == '.') {
                    if (i == 0) dp[i][j] = false;
                    else dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j - 1] == '*') {
                    if (j == 1) dp[i][j] = false;
                    else {
                        if (i > 0) {
                            if (p[j - 2] == '*') continue;

                            dp[i][j] = dp[i][j - 2];
                            if (s[i - 1] == p[j - 2]) {
                                int tmp_i = i - 1;
                                while(tmp_i >= 0 && s[tmp_i] == s[i - 1]) {
                                    if (dp[tmp_i][j - 2]) {
                                        dp[i][j] = true;
                                        break;
                                    }
                                    tmp_i--;
                                }
                            } else if (p[j - 2] == '.') {
                                int tmp_i = i - 1;
                                while(tmp_i >= 0) {
                                    if (dp[tmp_i][j - 2]) {
                                        dp[i][j] = true;
                                        break;
                                    }
                                    tmp_i--;
                                }
                            }
                        }
                        if (dp[i][j - 2]) dp[i][j] = true;
                    }
                } else {
                    if (i == 0) dp[i][j] = false;
                    else dp[i][j] = s[i - 1] == p[j - 1] && dp[i - 1][j - 1];
                }
            }
        }
        return dp[s_len][p_len];
    }
};

int main() {
    Solution s;
    auto result = s.isMatch("aa", "a*");
    cout << result;
}