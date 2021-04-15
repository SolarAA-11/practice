
#include "common.h"

int main() {
    vector<int> vec{0,1,2,3,4,5,6,7,8,9};
    auto it = vec.rbegin() + 3;
    list<int> li;
    copy(it, it + 5, back_inserter(li));

    ostream_iterator<int> out_iter(cout, " ");
    copy(li.begin(), li.end(), out_iter);
    cout << endl;

    list<int> li2;
    copy(vec.cbegin() + 2, vec.cbegin() + 6, front_inserter(li2));
    copy(li.begin(), li.end(), out_iter);
    cout << endl;
}
