
#include "common.h"

class Solution {
private:
    unordered_set<char> vis[3][9];
    bool set_vis(char c, int x, int y, vector<vector<char>>& board) {
        int block_index = x / 3 * 3 + y / 3;
        if (board[x][y] != '.' || vis[0][x].count(c) || vis[1][y].count(c) || vis[2][block_index].count(c)) return false;
        else {
            vis[0][x].insert(c);
            vis[1][y].insert(c);
            vis[2][block_index].insert(c);
            board[x][y] = c;
            return true;
        }
    }
    void remove_vis(char c, int x, int y, vector<vector<char>>& board) {
        int block_index = x / 3 * 3 + y / 3;
        vis[0][x].erase(c);
        vis[1][y].erase(c);
        vis[2][block_index].erase(c);
        board[x][y] = '.';
    }
    bool dfs(int x, int y, vector<vector<char>>& board) {
        if (y >= 9) return dfs(x + 1, 0, board);
        if (x >= 9) return true;
        if (board[x][y] != '.') return dfs(x, y + 1, board);
        else {
            for (int i = 1; i <= 9; ++i) {
                if ( set_vis(i + '0',x,y,board)) {
                    if (dfs(x, y + 1, board)) return true;
                    else remove_vis(i + '0', x,y, board);
                }
            }
            return false;
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                if (board[i][j] != '.')  {
                    char c = board[i][j];
                    board[i][j] = '.';
                    set_vis(c, i,j,board);
                }
        dfs(0,0,board);
    }
};

int main() {
    Solution s;
}
