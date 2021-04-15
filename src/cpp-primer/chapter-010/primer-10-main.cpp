//
// Created by SolarDomo on 2021/4/15.
//

#include "common.h"

int main() {
    vector<int> vec{1,2,3,4,5,6,7};
    auto r_it = vec.rbegin() + 1;
    cout << *r_it << " " << *(r_it.base()) << endl;
}