
#include "common.h"

bool comp(const int& i1, const int& i2) {
    return i1 > i2;
}

int main() {
    set<int> ints = {
            1,2,3,4,5,6,7,8,9,6,6,6,6,7
    };
    auto it_pair = ints.equal_range(6);
    cout << *it_pair.first << " " << *it_pair.second << endl;
}