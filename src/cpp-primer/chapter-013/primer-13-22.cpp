
#include "common.h"

class HasPtr {
public:
    HasPtr() : pos(0), p_str(new string()) {}
    HasPtr(const HasPtr& obj) :
            pos(obj.pos),
            p_str(obj.p_str != nullptr ? new string(*obj.p_str) : nullptr) {

    }
    HasPtr& operator=(const HasPtr& obj) {
        pos = obj.pos;

//        下面代码 有问题
//        delete p_str;
//        if (obj.p_str != nullptr) {
//            p_str = new string (*obj.p_str);
//        }  else p_str = nullptr;
//        return *this;

        auto temp_s = new string (*obj.p_str);
        delete p_str;
        p_str = temp_s;
        return *this;
    }
    ~HasPtr() {
        delete p_str;
    }

private:
    int pos;
    string* p_str;
};

int main() {

}