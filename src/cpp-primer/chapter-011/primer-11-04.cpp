
#include "common.h"

int main() {
    istream_iterator<string> in_iter(cin), eof_iter;
    vector<string> words(in_iter, eof_iter);

    set<string> exclude;
    map<string, size_t> count;
    for (const auto& str: words) {
        count[str]++;
    }

    for (const auto& element_pair: count) {
        cout << element_pair.first << " : " << element_pair.second << endl;
    }
}
