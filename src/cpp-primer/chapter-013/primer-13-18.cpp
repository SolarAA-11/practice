
#include "common.h"

class MyEmployee {
public:
    MyEmployee() : name(), id(++id_counter) {}
    MyEmployee(const string& name) : name(name), id(++id_counter) {}
    MyEmployee(const MyEmployee& obj) : name(obj.name), id(obj.id) {}

private:
    static int id_counter;
    string name;
    int id;
};

int MyEmployee::id_counter = 0;

int main() {

}