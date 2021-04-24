
#include "common.h"

class Solution {
private:
    int64_t vis = 0;
    int len;
    vector<string> board;
    vector<vector<string>> ans;
    void dfs(int x) {
        if (x == board.size()) ans.emplace_back(board);
        else {
            for (int y = 0; y < len; ++y) {
                int64_t state = (1l << y) + (1l << (x + y + 9)) + (1l << (x - y + len + 27));
                if (vis & state) continue;
                char& c = board[x][y];
                vis |= state;
                c = 'Q';
                dfs(x + 1);
                vis ^= state;
                c = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        board.assign(len = n, string(n, '.'));
        dfs(0);
        return move(ans);
    }
};

int main() {
    Solution s;
}
