#include "cache.h"

void test1(void) {
    cout << "===============Started test " << __func__ << endl;
    Cache C(5);
    C.set_key(1, 25);
    cout << "value of key-1 is " << C.get_key(1); 
}

int main() {
    test1();
    return 0;
}
