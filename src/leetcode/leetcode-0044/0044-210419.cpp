
#include "common.h"

class Solution {
private:
    vector<vector<int>> match;
    string s,p;
    bool dfs(int p1, int p2) {
        if (p1 == -1 && p2 == -1) return true;
        else if (p1 == -1) return all_of(p.begin(), p.begin() + p2 + 1, [](char c){return c == '*';});
        else if (p2 == -1) return false;
        if (match[p1][p2] != -1) return match[p1][p2];


        if (p[p2] == '?') {
            return match[p1][p2] = dfs(p1 - 1, p2 - 1);
        } else if (p[p2] == '*') {
            for (int i = -1; i <= p1; ++i) {
                if (dfs(i, p2 - 1)) {
                    return match[p1][p2] = true;
                }
            }
        } else {
            return match[p1][p2] = (s[p1] == p[p2] && dfs(p1 - 1, p2 - 1));
        }
        return match[p1][p2] = false;
    }
public:
    bool isMatch(string s, string p) {
        this->s = s, this->p = p;
        match = vector<vector<int>>(s.size(), vector<int>(p.size(), -1));
        return dfs(s.size() - 1, p.size() - 1);
    }
};

int main() {
    Solution s;
    cout << s.isMatch("acdcb", "a*c?b");
}
