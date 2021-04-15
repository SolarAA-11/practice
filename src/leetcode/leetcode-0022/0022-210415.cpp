
#include "common.h"

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string  temp(n * 2, ' ');
        dfs(0, n * 2, 0, 0, temp, result);
        return result;
    }
    void dfs(int pos, const int len, int count, int count2, string& temp, vector<string>& result) {
        if (pos == len) result.push_back(temp);
        else {
            if (count < len / 2) {
                temp[pos] = '(';
                dfs(pos + 1, len, count + 1, count2 + 1, temp, result);
            }
            if (count2 > 0) {
                temp[pos] = ')';
                dfs(pos + 1, len, count, count2 - 1, temp, result);
            }
        }
    }
};