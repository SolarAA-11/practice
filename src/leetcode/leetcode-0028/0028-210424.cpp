
#include "common.h"

class Solution {
private:
    int solve1(const string& s1, const string& s2) {
        if (s2.empty()) return 0;
        int len2 = s2.size();
        auto it1 = s1.begin();
        while(it1 + len2 <= s1.end()) {
            bool match = equal(s2.begin(), s2.end(), it1);
            if (match)
                return it1 - s1.begin();
            else
                it1++;
        }
        return -1;
    }
    int solve2(const string& s1, const string& s2) {
        if (s2.empty() || s1.size() < s2.size()) return 0;

        long long mod = (1 << 30) - 1;
        auto func = [=](const string& s) {
            return accumulate(s.begin(), s.end(), 0, [=](long long val, char c) {
                return (val * 26 + c) % mod;
            });
        };
        long long h1 = func(s1.substr(0, s2.size()));
        long long h2 = func(s2);
        if (h1 == h2) return 0;

        long long decrease_factor = 1;
        for (int i = 0; i < s2.size(); ++i)
            decrease_factor = decrease_factor * 26 % mod;
        auto it = s1.begin() + s2.size();
        while(it != s1.end()) {
            h1 = h1 * 26 - *(it - s2.size()) * decrease_factor + *it;
            h1 %= mod;
            if (h1 == h2) return it - s2.size() + 1 - s1.begin();
            else it++;
        }
        return -1;
    }
public:
    int strStr(string haystack, string needle) {
        return solve1(haystack, needle);
    }
};

int main() {
    Solution s;
}
