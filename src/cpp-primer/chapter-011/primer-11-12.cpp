
#include "common.h"

int main() {
    string str;
    int val;
    vector<pair<string, int>> pairs;
    while(cin >> str >> val) {
        pairs.emplace_back(str, val);
    }
}
