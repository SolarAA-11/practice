
#include "common.h"

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
        vector<int> ans(s.size(), 0);
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == '(') continue;

            if (s[i - 1] == '(')
                ans[i] = i == 1 ? 2 : (2 + ans[i - 2]);
            else {
                int p = i - ans[i - 1] - 1;
                if (p >= 0 && s[p] == '(')
                    ans[i] = ans[i - 1] + 2 + (p >= 1 ? ans[p - 1] : 0);
            }
            result = max(result, ans[i]);
        }
        return result;
    }
};

int main() {
    Solution s;
}
