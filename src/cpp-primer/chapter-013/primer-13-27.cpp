
#include "common.h"

class HasPtr {
public:
    explicit HasPtr(const string& str = string()) :
        ps(new string(str)), pos(0), use(new int (0)) {}
    HasPtr(const HasPtr& obj) :
        ps(obj.ps), pos(obj.pos), use(obj.use) {
        ++*use;
    }
    HasPtr& operator=(const HasPtr&);
    ~HasPtr();
private:
    string* ps;
    size_t pos;
    int* use;
};

HasPtr& HasPtr::operator=(const HasPtr& obj) {
    ++*obj.use;
    if (--*use == 0) {
        delete use;
        delete ps;
    }
    ps = obj.ps;
    use = obj.use;
    pos = obj.pos;
    return *this;
}

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete use;
        delete ps;
    }
}


int main() {

}