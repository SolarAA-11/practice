
#include "common.h"

int main() {
    string  file_name("./primer-10-main.cpp");
    ifstream  in(file_name);
    istream_iterator<string> in_iter(in), eof;
    vector<string> text_vector;
    copy(in_iter, eof, back_inserter(text_vector));

    ostream_iterator<string> out_iter(cout, " ");
    copy(text_vector.begin(), text_vector.end(), out_iter);
    cout << endl;
}