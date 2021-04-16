
#include "common.h"

int main() {
    string str;
    int val;
    vector<pair<string, int>> pairs;
    while(cin >> str >> val) {
        pair<string, int> p(str, val);
        pair<string, int> p1{str, val};
        auto p2 = make_pair(str, val);
        pairs.emplace_back(str, val);
    }
}
