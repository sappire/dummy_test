#include "sort.h"

void stest1() {
    cout << "Started test: " << __func__ << endl;
    Sort s;
    vector<int> A;
    A.push_back(3);
    A.push_back(4);
    A.push_back(1);
    A.push_back(6);
    A.push_back(-1);
    s.merge_sort(A, 0, A.size()-1);
    cout << "MERGE SORT: ";
    s.print_sort(A);
}

int main() {
    stest1();
    return 1;
}
