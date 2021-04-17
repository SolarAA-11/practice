
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
        if (digits.empty()) return {};
        queue<string> q[2];
        int index = 0;
        for (char c : digits) {
            int num = c - '0', side_index = 1 - index;
            if (q[index].empty()) {
                for (char nc: num_2_chars[num])
                    q[side_index].push(string() + nc);
            } else {
                while(!q[index].empty()) {
                    for (char nc: num_2_chars[num])
                        q[side_index].push(q[index].front() + nc);
                    q[index].pop();
                }
            }
            index = side_index;
        }
        vector<string> result;
        result.reserve(q[index].size());
        while(!q[index].empty()) {
            result.emplace_back(q[index].front());
            q[index].pop();
        }
        return result;
    }
};

int main() {
    Solution s;
}
