#include "common.h"

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        else if (strs.size() == 1) return strs[0];

        unsigned common_size = strs.front().size();
        for(int i = 1;i < strs.size();++i) {
            string& cur_str = strs[i];
            unsigned pos = 0, len = cur_str.size();
            while(pos < len && pos < common_size && cur_str[pos] == strs[0][pos])
                pos++;
            common_size = pos;
            if (common_size == 0) break;
        }
        return strs[0].substr(0,common_size);
    }
};

int main() {

}