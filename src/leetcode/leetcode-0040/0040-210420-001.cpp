
#include "common.h"

class Solution {
private:
    using iter = map<int, int>::iterator;
    map<int,int> m, m2;
    vector<vector<int>> ans;
    vector<int> board;
    void dfs(iter st, iter ed, int target) {
        if (target == 0) {
            ans.emplace_back();
            vector<int>& vec = ans.back();
            for (const auto &item : m2)
                vec.insert(vec.end(), item.second, item.first);
        }
        else if (st == ed || st->first > target) return;
        else {
            int& count = m2[st->first];
            for (int i = 0; i <= st->second; ++i, target -= st->first) {
                dfs(next(st), ed, target);
                count++;
            }
            count = 0;
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        for (const auto &item : candidates) m[item]++;
        dfs(m.begin(), m.end(), target);
        return move(ans);
    }
};

int main() {
    Solution s;
}
