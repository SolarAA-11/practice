
#include "common.h"

class HasPtr {
    friend void swap(HasPtr&, HasPtr&);

public:
    using size_t = string::size_type;
    HasPtr(const string& s = string()) :
        ps(new string (s)), pos(0) {}
    HasPtr(const HasPtr& obj) :
        ps(new string(*obj.ps)), pos(obj.pos) {}
    ~HasPtr();
    HasPtr& operator=(HasPtr);

private:
    string* ps;
    size_t pos;
};

inline
void swap(HasPtr &obj1, HasPtr &obj2) {

}


int main() {

}
