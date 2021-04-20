
#include "common.h"

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> m{{'(', ')'}, {'[',']'}, {'{','}'}};
        for (const auto &item : s) {
            if (m.count(item)) st.push(item);
            else {
                if (st.empty()) return false;
                char c = st.top();st.pop();
                if (m[c] != item) return false;
            }
        }
        return st.empty();
    }
};

int main() {
    Solution s;
}
