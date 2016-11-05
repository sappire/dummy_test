#include "stack.h"

void test1(void) {
    cout << "------Stack Test1-Insert an element------------" << endl;
    Stack<int> s;
    int var = 10;
    s.push(&var);
    pair<int,int> res;
    res = s.pop();
    if (res.first == 0) {
        cout << "element popped is " << res.second << endl;
        return;
    } 
    cout << "POP failed" << res.first << endl;
}

int main(int argc, char *argv[]) {
    test1();
    return 0;
}
