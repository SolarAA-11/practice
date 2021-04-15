
#include "common.h"

int main() {
    istream_iterator<int> in_it(cin), eof_it;
    ostream_iterator<int> out_it(cout, " ");
    vector<int> storage(in_it, eof_it);
    sort(storage.begin(), storage.end());
    unique_copy(storage.begin(), storage.end(), out_it);
}