
#include "common.h"


class Solution {
public:
    int longestValidParentheses(string s) {
        int *dp = new int[s.size()], ans = 0;
        memset(dp, 0, s.size() * sizeof(int));
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') dp[i] = 0;
            else {
                if (s[i - 1] == '(') {
                    if (i - 2 >= 0) dp[i] = dp[i - 2] + 2;
                    else dp[i] = 2;
                }
                else {
                    int pos = i - dp[i - 1] - 1;
                    if (pos >= 0 && s[pos] == '(') {
                        dp[i] = 2 + dp[i - 1] + (pos >= 1 ? dp[pos - 1] : 0);
                    } else dp[i] = 0;
                }
            }
            ans = max(ans, dp[i]);
        }
        delete []dp;
        return ans;
    }
};

int main() {
    Solution s;
    cout << s.longestValidParentheses("()(())");
}
