
#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[25][35] = {false};
        auto len1 = s.size(), len2 = p.size();
        dp[0][0] = true;
        for (int i = 0; i <= len1; ++i) {
            for (int j = 1; j <= len2; ++j) {
                int ii = i - 1, jj = j - 1;
                if (p[jj] == '.') {
                    if (i > 0)
                        dp[i][j] = dp[i - 1][j - 1];
                } else if (p[jj] == '*') {
                    if (j >= 2 && p[jj - 1] != '*') {
                        dp[i][j] = dp[i][j - 2];
                        char c = p[jj - 1];
                        if (c == '.') {
                            for (int k = 0; k < i && !dp[i][j]; ++k)
                                dp[i][j] = dp[k][j - 2];
                        } else if (c != '*') {
                            for (int k = ii; k >= 0 && s[k] == c && !dp[i][j]; --k) {
                                dp[i][j] = dp[k][j - 2];
                            }
                        }
                    }
                } else {
                    dp[i][j] = i >= 1 && s[ii] == p[jj] && dp[i - 1][j - 1];
                }
            }
        }
        return dp[len1][len2];
    }
};

int main() {
    Solution s;
    s.isMatch("aa", "a");
}
