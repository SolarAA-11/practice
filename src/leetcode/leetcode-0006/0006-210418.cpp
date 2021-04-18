
#include "common.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        vector<string> rows(numRows, "");
        int index = 0, add = 1;
        for (char c : s) {
            rows[index].push_back(c);
            if (index + add == -1) index = 1, add = 1;
            else if (index + add == numRows) index = numRows - 2, add = -1;
            else index += add;
        }
        return accumulate(rows.begin(), rows.end(), string(""));
    }
};

int main() {
    Solution s;
}
