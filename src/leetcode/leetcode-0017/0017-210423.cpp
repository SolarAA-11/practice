
#include "common.h"

const string num_2_chars[] = {
        "",
        "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz",
};

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        queue<string> que[2];
        int index = 0;
        for (const auto &digit : digits) {
            auto& q = que[index];
            auto& chars = num_2_chars[digit - '0'];
            if (chars.empty()) continue;
            if (q.empty()) {
                for (const auto &c : chars)
                    que[1 - index].emplace(1, c);
            } else {
                while (!q.empty()) {
                    auto s = q.front();q.pop();
                    for (const auto &c : chars) {
                        que[1 - index].emplace(s);
                        que[1 - index].back().push_back(c);
                    }
                }
            }
            index = 1 - index;
        }
        auto& q = que[index];
        vector<string> result;
        result.reserve(q.size());
        while (!q.empty()) {
            result.emplace_back(q.front());q.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    s.letterCombinations("999");
}
