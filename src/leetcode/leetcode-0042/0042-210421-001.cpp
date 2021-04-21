
#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0;
        stack<pair<int,int>> st;
        for (int i = 0; i < height.size(); ++i) {
            if (st.empty()) st.push({height[i], i});
            else {
                auto prev = make_pair(0,i);
                int sum = 0;
                while (!st.empty() && st.top().first <= height[i]) {
                    auto cur = st.top(); st.pop();
                    sum += (cur.first - prev.first) * (i - cur.second - 1);
                    prev = cur;
                }
                if (!st.empty())
                    sum += (height[i] - prev.first) * (i - st.top().second - 1);
                st.push({height[i], i});
                result += sum;
            }
        }
        return result;
    }
};

int main() {
    Solution s;
}
