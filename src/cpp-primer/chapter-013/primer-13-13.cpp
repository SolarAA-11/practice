
#include "common.h"

class X {
public:
    X() {
        cout << "Default Constructor" << endl;
    }
    X(const X& x) {
        cout << "Copy Constructor" << endl;
    }
    X& operator= (const X&) {
        cout << "Copy-Assignment Operator" << endl;
        return *this;
    }
    ~X() {
        cout << "Destructor" << endl;
    }
};

X func_return_val(X x_val, X& x_ref) {
    X x_default_cons;
    X x_copy_cons(x_val);
    X x_copy_init = x_ref;

}

int main() {

}