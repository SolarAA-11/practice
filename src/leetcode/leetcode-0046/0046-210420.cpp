
#include "common.h"

class Solution {
private:
    vector<bool> used;
    vector<vector<int>> result;
    vector<int> board;
    void dfs(int pos, vector<int>& nums) {
        if (pos == nums.size())
            result.push_back(board);
        else {
            for (int i = 0; i < nums.size(); ++i) {
                if (!used[i]) {
                    used[i] = true;
                    board[pos] = nums[i];
                    dfs(pos + 1, nums);
                    used[i] = false;
                }
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        used.assign(nums.size(), false);
        board.assign(nums.size(), 0);
        dfs(0, nums);
        return move(result);
    }
};

int main() {
    Solution s;
}
