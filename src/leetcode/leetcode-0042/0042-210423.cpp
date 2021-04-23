
#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, index = 0;
        stack<pair<int, int>> st;
        auto it = height.begin();
        while (it != height.end()) {
            if (st.empty()) st.push({*it, index});
            else {
                auto prev = make_pair(0, index);
                while (!st.empty() && st.top().first <= *it) {
                    auto cur = st.top(); st.pop();
                    result += (cur.first - prev.first) * (index - cur.second - 1);
                    prev = cur;
                }
                if (!st.empty())
                    result += (*it - prev.first) * (index - st.top().second - 1);
                st.push({*it, index});
            }
            it++, index++;
        }
        return result;
    }
};

int main() {
    Solution s;
}
