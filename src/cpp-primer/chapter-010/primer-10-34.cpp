
#include "common.h"

int main() {
    vector<int> vec{1,2,3,4,5,6,7};
    ostream_iterator<int> o_iter(cout, " ");
    copy(vec.rbegin(), vec.rend(), o_iter);
}