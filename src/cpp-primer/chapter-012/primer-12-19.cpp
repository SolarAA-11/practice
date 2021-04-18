
#include "common.h"

class StrBlob {
public:
    StrBlob();
    StrBlob(initializer_list<string> li);
private:

    shared_ptr<vector<string>> data;

};

int main() {

}