
#include "common.h"

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 0; i < s.size() + 1; ++i) {
            for (int j = 1; j < p.size() + 1; ++j) {
                int ii = i - 1, jj = j - 1;
                if (p[jj] == '.') {
                    if (i > 0) dp[i][j] = dp[i - 1][j - 1];
                } else if (p[jj] == '*') {
                    if (j >= 2) {
                        char c = p[jj - 1];
                        if (c == '.') {
                            dp[i][j] = dp[i][j - 2];
                            int pos = ii;
                            while (pos >= 0 && !dp[i][j])
                                dp[i][j] = dp[pos--][j - 2];
                        } else if (c != '*') {
                            dp[i][j] = dp[i][j - 2];
                            int pos = ii;
                            while (pos >= 0 && s[pos] == c && !dp[i][j])
                                dp[i][j] = dp[pos--][j - 2];
                        }
                    }
                } else {
                    if (i > 0 && s[ii] == p[jj])
                        dp[i][j] = dp[i - 1][j - 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};

int main() {
    Solution s;
}
