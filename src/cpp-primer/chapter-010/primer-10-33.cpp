
#include "common.h"

int main(int argc, char** argv) {
    ifstream  in(argv[1]);
    ofstream out1(argv[2]), out2(argv[3]);
    istream_iterator<int> in_iter, eof_iter;
    ostream_iterator<int> out1_iter(out1, " "), out2_iter(out2, "\n");
    while(in_iter != eof_iter) {
        if (*in_iter % 2 == 0) *out2_iter++ = *in_iter++;
        else *out1_iter++ = *in_iter++;
    }
    out1 << endl;
}