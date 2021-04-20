
#include "common.h"

class Solution {
private:
    using vvc = vector<vector<char>>;
    int vis[27];
    bool try_vis(int x, int y, int val, vvc& b) {
        int p1 = x, p2 = y + 9, p3 = x / 3 * 3 + y / 3 + 18;
        int flag = 1 << val;
        if (b[x][y] != '.' ||
            vis[p1] & flag ||
            vis[p2] & flag ||
            vis[p3] & flag
        )
            return false;
        b[x][y] = val + '0';
        vis[p1] |= flag;
        vis[p2] |= flag;
        vis[p3] |= flag;
        return true;
    }
    void remove_vis(int x,int y,vvc& b) {
        if (b[x][y] == '.') return;
        int val = b[x][y] - '0';
        int p1 = x, p2 = y + 9, p3 = x / 3 * 3 + y / 3 + 18;
        int flag = 1 << val;
        b[x][y] = '.';
        vis[p1] ^= flag;
        vis[p2] ^= flag;
        vis[p3] ^= flag;
    }
    bool dfs(int x, int y, vvc& b) {
        if (x == 9) return true;
        else if (y == 9) return dfs(x + 1, 0, b);
        else {
            if (b[x][y] != '.') return dfs(x, y + 1, b);

            for (int i = 1; i <= 9; ++i) {
                if (try_vis(x,y,i,b) && dfs(x,y + 1,b))
                    return true;
                remove_vis(x, y, b);
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        memset(vis,0,sizeof vis);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    int val = board[i][j] - '0';
                    board[i][j] = '.';
                    try_vis(i,j,val,board);
                }
            }
        }
        dfs(0,0,board);
    }
};

int main() {
    Solution s;
}
