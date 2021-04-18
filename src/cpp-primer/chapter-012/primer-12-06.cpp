
#include "common.h"

using vec_int = vector<int>;

vec_int *vector_factory() {
    return new vec_int();
}

void read_from_stdin(vec_int* vec) {
    istream_iterator<int> in_iter(cin), end_iter;
    vec->assign(in_iter, end_iter);
}

void output_vec_int(vec_int* vec) {
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec->begin(), vec->end(), out_iter);
}

int main() {
    auto vec = vector_factory();
    read_from_stdin(vec);
    output_vec_int(vec);
    delete vec;
}