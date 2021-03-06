
#include "common.h"

class StrBlob {
public:
    typedef vector<string>::size_type size_type;
    StrBlob():data(make_shared<vector<string>>()) {}
    StrBlob(initializer_list<string> li) :
        data (make_shared<vector<string>>(li)) {}
    size_type size() const { return data->size(); }
    bool empty() const { return data->empty(); }
    void push_back(const string& str) { data->push_back(str); }
    void pop_back();
    string& front() ;
    const string& front()const;
    string& back();
    const string& back()const;

private:
    shared_ptr<vector<string>> data;
    void check(size_type i, const string& msg) const;
};

string &StrBlob::front() {
    check(0, "front on empty StrBlob");
    return data->front();
}

const string &StrBlob::front() const {
    check(0, "front on empty StrBlob.");
    return data->front();
}

string &StrBlob::back() {
    check(0, "back on empty StrBlob.");
    return data->front();
}

const string &StrBlob::back() const {
    check(0, "back on empty StrBlob.");
    return data->front();
}

void StrBlob::pop_back() {
    check(0, "pop_back on empty StrBlob.");
    data->pop_back();
}

void StrBlob::check(StrBlob::size_type i, const string &msg) const {
    if (i >= data->size())
        throw out_of_range(msg);
}



class my_class {
public:
    int x;
    ~my_class() {
        cout << "Destructed: " << x << endl;
    }
};

void func() {
    auto pa = new my_class[10];
    for (int i = 0; i < 10; ++i) {
        pa[i].x = i;
    }
    delete []pa;
}

int main() {
    allocator<string> alloc;
    auto const p = alloc.allocate(10);
    auto q = p;
}
