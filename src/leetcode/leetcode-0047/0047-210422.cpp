
#include "common.h"

class Solution {
private:
    map<int,int> counter;
    vector<vector<int>> result;
    vector<int> board;
    void f(int pos) {
        if (pos == board.size()) result.emplace_back(board);
        else {
            for (auto &item : counter) {
                if (item.second != 0) {
                    board[pos] = item.first;
                    item.second--;
                    f(pos + 1);
                    item.second++;
                }
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (const auto &item : nums) counter[item]++;
        board.assign(nums.size(), 0);
        f(0);
        return result;
    }
};

int main() {
    Solution s;
}
