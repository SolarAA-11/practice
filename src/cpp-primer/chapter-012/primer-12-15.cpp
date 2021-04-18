
#include "common.h"

struct destination {};
struct connection {};
connection connect(destination* dest) { return connection{}; }
void disconnect(connection conn) {cout << "Disconnected" << endl;}
void f(destination &d, bool excep) {
    auto conn = connect(&d);
    shared_ptr<connection> p_conn(&conn, [](connection* p_conn){
        disconnect(*p_conn);
    });
    if (excep)
        throw exception("Needed");
    cout << "Before exiting f" << endl;
}

int main() {
    destination d;
    try {
        f(d, true);
    } catch (exception& e) {
        cout << e.what() << endl;
    }
}