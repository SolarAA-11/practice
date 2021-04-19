
#include "common.h"

class Solution {
public:
    int trap(vector<int>& height) {
        int result = 0, index = 0;
        stack<pair<int,int>> st;
        for (const auto &item : height) {
            if (index == 0) {
                if (item != 0) st.push({item,index});
            } else {
                if (item != 0) {
                    pair<int,int> prev = {-1,-1};
                    while(!st.empty() && st.top().first <= item) {
                        auto top = st.top();st.pop();
                        if (prev.first != -1)
                            result += (index - top.second - 1) * (top.first - prev.first);
                        else result += (index - top.second - 1) * top.first;
                        prev = top;
                    }
                    if (!st.empty()) {
                        auto top = st.top();
                        if (prev.first == -1) result += (index - top.second - 1) * item;
                        else result += (index - top.second - 1) * (item - prev.first);
                    }
                    st.push({item, index});
                }
            }
            index++;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> in = {
            4,2,0,3,2,5
    };
    cout << s.trap(in);
}
