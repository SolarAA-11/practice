
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
        for (auto it = find(digits.begin(), digits.end(), '1');
            it != digits.end();
            it = find(digits.begin(), digits.end(), '1')
        ) {
            digits.erase(it);
        }
        if (digits.empty()) return {};
        string temp(digits.size(), ' ');
        vector<string> result;
        dfs(digits, 0, temp, result);
        return result;
    }

    void dfs(const string &digits, int pos, string& temp, vector<string>& result) {
        if (pos == digits.size()) {
            result.emplace_back(temp);
        } else {
            for(auto c : num_2_chars[digits[pos] - '0']) {
                temp[pos] = c;
                dfs(digits, pos + 1, temp, result);
            }
        }
    }
};


