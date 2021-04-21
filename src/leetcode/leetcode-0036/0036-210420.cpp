
#include "common.h"

class Solution {
private:
    int vis[27];
    bool try_vis(int x, int y, int val) {
        int p1 = x, p2 = y + 9, p3 = x / 3 * 3 + y / 3 + 18;
        int flag = 1 << val;
        if (vis[p1] & flag || vis[p2] & flag || vis[p3] & flag)
            return false;
        vis[p1] |= flag;
        vis[p2] |= flag;
        vis[p3] |= flag;
        return true;
    }
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        memset(vis, 0, sizeof vis);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !try_vis(i,j,board[i][j] - '0'))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
}
