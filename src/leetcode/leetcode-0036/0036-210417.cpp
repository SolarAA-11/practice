
#include "common.h"

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> char_set;
        auto is_legal = [&](const vector<char>& chars) -> bool {
            char_set.clear();
            size_t c_count = count_if(chars.begin(), chars.end(), [](char c){return c != '.';});
            copy_if(chars.begin(), chars.end(), inserter(char_set, char_set.begin()), [](char c){return c != '.';});
            return c_count == char_set.size();
        };
        if (!all_of(board.begin(), board.end(), is_legal)) return false;
        vector<char> chars[18];
        for (int i = 0; i < 9; ++i)
            for (int j = 0; j < 9; ++j)
                chars[i / 3 * 3 + j / 3].push_back(board[i][j]),
                chars[9 + j].push_back(board[i][j]);
        return all_of(begin(chars), end(chars), is_legal);
    }
};

int main() {
    Solution s;
    set<char> cs;
}