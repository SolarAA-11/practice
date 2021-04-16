
#include "common.h"

class Solution {
private:
    // 暴力算法
    int solve1(string haystack, string needle) {
        auto l1 = haystack.size(), l2 = needle.size();
        for (int i = 0; i + l2 <= l1; ++i) {
            bool ok = true;
            for (int j = 0; j < l2; ++j) {
                if (haystack[i + j] != needle[j]) {
                    ok = false; break;
                }
            }
            if (ok) return i;
        }
        return -1;
    }
    // Rabin Karp 滑动窗口 Hash 算法
    int solve2(string haystack, string needle) {
        using LL = long long;

        if (haystack.size() < needle.size()) return -1;

        vector<int> v1, v2;
        transform(haystack.begin(), haystack.end(), back_inserter(v1), [](char c) {return (int)c - (int)'a';});
        transform(needle.begin(), needle.end(), back_inserter(v2), [](char c) {return (int)c - (int)'a';});

        const LL mod = (1ll << 31) - 1;
        auto hash = [=](decltype(v1.begin()) it, unsigned len) -> LL {
            LL result = 0;
            for (int i = 0; i < len; ++i)
                result = (result * 26 + *it++) % mod;
            return result;
        };
        auto l1 = v1.size(), l2 = v2.size();
        LL s1_hash = hash(v1.begin(), l2),
            s2_hash = hash(v2.begin(), l2);
        if (s1_hash == s2_hash) return 0;
        LL power_26 = 1;
        for (int i = 0; i < l2; ++i)
            power_26 = power_26 * 26 % mod;
        for (int i = 0; i + l2 < l1; ++i) {
            s1_hash = (s1_hash * 26 - v1[i] * power_26 + v1[i + l2]) % mod;
            if (s1_hash == s2_hash) return i + 1;
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return solve2(haystack, needle);
    }
};

int main() {
    Solution s;
    s.strStr("baaaaaaaa",
             "bagytisyy");
}