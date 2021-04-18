
#include "common.h"

using vec_int = vector<int>;

shared_ptr<vec_int> vector_factory() {
    return make_shared<vec_int>();
}

void read_from_stdin(shared_ptr<vec_int> vec) {
    istream_iterator<int> in_iter(cin), end_iter;
    vec->assign(in_iter, end_iter);
}

void output_vec_int(shared_ptr<vec_int> vec) {
    ostream_iterator<int> out_iter(cout, " ");
    copy(vec->begin(), vec->end(), out_iter);
}

int main() {
    auto vec = vector_factory();
    read_from_stdin(vec);
    output_vec_int(vec);

    int f = 10;
    {
        shared_ptr<int> ptr(&f);
    }
    cout << "OK" << endl;

}