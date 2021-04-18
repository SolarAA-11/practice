
#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        string  tmp(n * 2, ' ');
        dfs(0,0,0,tmp);
        return ans;
    }

private:
    vector<string> ans;
    void dfs(int pos, int all_left, int unused_left, string& temp) {
        if (pos == temp.size() && unused_left == 0) ans.emplace_back(temp);
        else if (pos < temp.size()) {
            if (unused_left > 0) {
                temp[pos] = ')';
                dfs(pos + 1, all_left, unused_left - 1, temp);
            }
            if (all_left < temp.size() / 2) {
                temp[pos] = '(';
                dfs(pos + 1, all_left + 1, unused_left + 1,temp);
            }
        }
    }
};

int main() {
    Solution s;
}
