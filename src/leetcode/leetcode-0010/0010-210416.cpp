
#include "common.h"


class Solution {
public:
    bool isMatch(string s, string p) {
        bool dp[25][35] = {true};
        auto l1 = s.size(), l2 = p.size();
        for (int i = 0; i <= l1; ++i) {
            for (int j = 1; j <= l2; ++j) {
                // normal char
                if (i >= 1 && s[i - 1] == p[j - 1])
                    dp[i][j] |= dp[i - 1][j - 1];
                // star and dot
                if (p[j - 1] == '*' && j >= 2) {
                    if (p[j - 2] != '*')
                        dp[i][j] |= dp[i][j - 2];
                    if (i >= 1 && (p[j - 2] == '.' || p[j - 2] == s[i - 1]))
                        dp[i][j] |= dp[i - 1][j - 2] | dp[i - 1][j];
                } else if (p[j - 1] == '.' && i >= 1)
                    dp[i][j] |= dp[i - 1][j - 1];
            }
        }
        return dp[l1][l2];
    }
};

int main() {
    vector<vector<int>> input = {
            {"aa", "a*"},

    };

}

