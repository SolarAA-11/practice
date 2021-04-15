
#include "common.h"

class Solution {
private:
    map<char, char> m {
            {')', '(' },
            {']','[' },
            {'}','{' },
    };
public:
    bool isValid(string s) {
        stack<char> st;
        for(char c: s) {
            if (m.find(c) != m.end()) {
                if (st.empty() || st.top() != m[c]) return false;
                else st.pop();
            } else st.push(c);
        }
        return st.empty();
    }
};
