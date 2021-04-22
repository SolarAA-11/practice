
#include "common.h"

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char,int>, vector<string>> m;
        for (const auto &str : strs) {
            map<char,int> counter;
            for (const auto &c : str)
                counter[c]++;
            m[counter].emplace_back(str);
        }
        vector<vector<string>> result;
        result.reserve(m.size());
        for (auto &item : m) {
            result.emplace_back(move(item.second));
        }
        return result;
    }
};

int main() {
    Solution s;
}
