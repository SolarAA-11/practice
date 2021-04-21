
#include "common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        multimap<map<char,int>, string> m;
        for (const auto &item : strs) {
            map<char,int> mm;
            for (const auto &item2 : item) mm[item2]++;
            m.insert({mm, item});
        }
        vector<vector<string>> ret;
        map<char, int> prev = {{'#', 1}};
        for (const auto &item : m) {
            if (item.first != prev) {
                ret.emplace_back();
                prev = item.first;
            }
            ret.back().emplace_back(item.second);
        }
        return ret;
    }
};
int main() {
    Solution s;
}
