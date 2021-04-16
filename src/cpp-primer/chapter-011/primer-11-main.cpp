
#include "common.h"

class my_str {
public:
    my_str(): str("Hello"){}
    string  fetch_str() {
        return str;
    }
private:
    string  str;
};

int main() {
    map<int, my_str> i_s_map;
    cout << i_s_map[100].fetch_str() << endl;
}