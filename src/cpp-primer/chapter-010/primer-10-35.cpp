
#include "common.h"

int main() {
    vector<int> vec{1,2,3,4,5,6,7};
    ostream_iterator<int> o_iter(cout, " ");
    auto it = vec.begin(), end_it = vec.end();
    do {
        if (it == end_it) break;

        end_it--;
        cout << *end_it << " ";
    } while(it != end_it);
}
