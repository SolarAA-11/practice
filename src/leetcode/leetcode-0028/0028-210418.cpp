
#include "common.h"

class Solution {
private:
    // 暴力匹配
    int solve(const string& s, const string& p) {
        if (p.empty()) return 0;
        else if (s.size() < p.size()) return -1;

        auto it = s.begin(), end = s.end();
        while(end - it >= p.size()) {
            if (equal(p.begin(), p.end(), it))
                return it - s.begin();
            it++;
        }
        return -1;
    }

    // 哈希算法
    int solve2(const string& s, const string& p) {
        if (p.empty()) return 0;
        else if (s.size() < p.size()) return -1;

        using LL = long long;
        LL mod = (1ll << 31) - 1;
        auto hash_str = [=](const string& s) -> LL {
            LL result = 0;
            for (char c : s)
                result = (result * 26 + c - 'a') % mod;
            return result;
        };
        LL hash_s = hash_str(s.substr(0, p.size())),
           hash_p = hash_str(p);
        if (hash_s == hash_p) return 0;
        LL top_char_factor = 1;
        for (int i = 0; i < p.size(); ++i)
            top_char_factor = top_char_factor * 26 % mod;
        auto it = s.begin() + p.size();
        while(it != s.end()) {
            hash_s = hash_s * 26 - top_char_factor * (*(it - p.size()) - 'a') + *it - 'a';
            hash_s %= mod;
            if (hash_s == hash_p)
                return it - s.begin() - p.size() + 1;
            it++;
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return solve(haystack, needle);
        return solve2(haystack, needle);
    }
};

int main() {
    Solution s;
}
