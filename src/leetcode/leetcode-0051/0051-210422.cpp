
#include "common.h"

class Solution {
private:
    int board_size;
    int vis[54];
    vector<string> board;
    vector<vector<string>> ans;
    void dfs(int x, int y,int n) {
//        cout << x << " " << y << " " << n;
        if (n == 0)
            ans.emplace_back(board);
        else if (x == board_size) return;
        else if (y == board_size) dfs(x + 1,0,n);
        else {
            int p1 = x,
            p2 = y + board_size,
            p3 = x + y + board_size * 2,
            p4 = board_size + x - y + board_size * 4 - 1;
            if (vis[p1] || vis[p2] || vis[p3] || vis[p4])
                dfs(x,y + 1, n);
            else {
                vis[p1] = vis[p2] = vis[p3] = vis[p4] = true;
                board[x][y] = 'Q';
                dfs(x, y + 1,n - 1);
                vis[p1] = vis[p2] = vis[p3] = vis[p4] = false;
                board[x][y] = '.';
                dfs(x,y + 1, n);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        memset(vis, 0, sizeof vis);
        board.assign(n, string(n, '.'));
        dfs(0,0,board_size = n);
        return move(ans);
    }
};

int main() {
    Solution s;
    s.solveNQueens(4);
}
