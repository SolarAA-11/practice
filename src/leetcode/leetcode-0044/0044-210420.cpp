
#include "common.h"

class Solution {
private:
    string s, p;
    vector<vector<int>> m;
    bool dfs(int l1, int l2) {
        if (m[l1][l2] != -1) return m[l1][l2];
        int& mc = m[l1][l2];
        if (l1 == 0 && l2 == 0) return mc = 1;
        else if (l1 == 0) return mc = p[l2 - 1] == '*' ? dfs(l1, l2 - 1) : 0;
        else if (l2 == 0) return mc = 0;
        else {
            if (p[l2 - 1] == '?') return mc = dfs(l1 - 1, l2 - 1);
            else if (p[l2 - 1] == '*') {
                for (int i = l1; i >= 0; --i)
                    if (dfs(i, l2 - 1)) return mc = 1;
                return mc = 0;
            } else return mc = s[l1 - 1] == p[l2 - 1] && dfs(l1 - 1, l2 - 1);
        }
    }
public:
    bool isMatch(string ss, string pp) {
        s = move(ss), p = move(pp);
        m.assign(s.size() + 1, vector<int>(p.size() + 1, -1));
        return dfs(s.size(), p.size());
    }
};

int main() {
    Solution s;
    cout << s.isMatch("bbbababbabbbbabbbbaabaaabbbbabbbababbbbababaabbbab",
              "a******b*");
    vector<vector<int>> vvi(10, vector<int>(10, 10));
    int& p = vvi[5][5];
    p = 10000;
    cout << vvi[5][5] << endl;
}
