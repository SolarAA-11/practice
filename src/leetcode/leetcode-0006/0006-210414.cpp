//
// Created by SolarDomo on 2021/4/14.
//

#include "common.h"

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<string> rows(numRows);
        int now_row_index = 0, plus = 1;
        for(auto c: s) {
            rows[now_row_index].push_back(c);
            if (now_row_index == 0) plus = 1;
            else if (now_row_index == numRows - 1) plus = -1;
            now_row_index += plus;
        }
        return accumulate(rows.begin(), rows.end(), string(""));
    }
};