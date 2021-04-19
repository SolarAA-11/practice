
#include "common.h"

class Solution {
private:
    static const int LEN = 1000 + 5;
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";

        bool dp[LEN][LEN];
        memset(dp, 0, sizeof dp);
        size_t len = s.size();
        auto sub_str_pair = make_pair(0,1);
        for (int i = 0; i < len; ++i)
            dp[i][i] = true;
        for (int sub_len = 2; sub_len <= len; ++sub_len) {
            for (int st_index = 0; st_index + sub_len <= len; ++st_index) {
                if (sub_len == 2)
                    dp[st_index][st_index + 1] = s[st_index] == s[st_index + 1];
                else dp[st_index][st_index + sub_len - 1] =
                        (dp[st_index + 1][st_index + sub_len - 2] &&
                        s[st_index] == s[st_index + sub_len - 1]);
                if (dp[st_index][st_index + sub_len - 1] && sub_str_pair.second < sub_len)
                    sub_str_pair = make_pair(st_index, sub_len);
            }
        }
        return s.substr(sub_str_pair.first, sub_str_pair.second);
    }
};

int main() {
    Solution s;
}
