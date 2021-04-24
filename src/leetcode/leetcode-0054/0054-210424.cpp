
#include "common.h"

#define BAD_BLOCK -10000

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int direction = 0, direction_increment[4][2] = {
                {0,1},{1,0},{0,-1},{-1,0}
        };
        auto next_position = [&](pair<int, int>& pos) {
            for (int i = 0;i < 4;++i) {
                int nx = pos.first + direction_increment[direction][0];
                int ny = pos.second + direction_increment[direction][1];

                if (nx >= 0 && nx < matrix.size() && ny >= 0 && ny < matrix[0].size() && matrix[nx][ny] != BAD_BLOCK) {
                    pos.first = nx, pos.second = ny;
                    return;
                } else {
                    direction++;
                    if (direction == 4) direction = 0;
                }
            }
            pos = {-1,-1};
        };
        vector<int> ret;
        ret.reserve(matrix.size() * matrix[0].size());
        auto pos = make_pair(0,0);
        while(pos.first != -1) {
            int& val = matrix[pos.first][pos.second];
            ret.emplace_back(val);
            val = BAD_BLOCK;
            next_position(pos);
        }
        return ret;
    }
};

int main() {
    Solution s;
}
