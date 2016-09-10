#include "string_h.h"

void
stest1(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("hello world");
    cout << "Original String: " << str << endl;
    s.reverse(str);
    cout << "Reversed String: " << str << endl;
    s.reverse(str);
    cout << "Print duplicates of the string--\""<< str << "\": ";
    s.print_dups_of_str(str);
}

int main() {
    stest1();
    return 1;
}
