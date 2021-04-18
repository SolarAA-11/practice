//
// Created by SolarDomo on 2021/4/15.
//

#include "common.h"

int main() {
    vector<int> v = {
            1,2,3,4,5,6,7,8,9
    };
    ostream_iterator<int> out_iter(cout, " ");
    copy(v.begin(), v.end(), out_iter);
}