
#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int sum = 0;
        stack<pair<int,int>> st;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty()) {
                st.push({height[i], i});
            } else if (height[i] != 0){
                int val = 0;
                auto prev = make_pair(0, i);
                while (!st.empty() && st.top().first <= height[i]) {
                    auto cur = st.top(); st.pop();
                    val += (cur.first - prev.first) * (i - cur.second - 1);
                    prev = cur;
                }
                if (!st.empty())
                    val += (height[i] - prev.first) * (i - st.top().second - 1);
                st.push({height[i], i});
                sum += val;
            }
        }
        return sum;
    }
};

int main() {
    Solution s;
}
