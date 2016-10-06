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
    A.clear();

    int B[] = {17,22234,18,29,50,3,6};
    s.insertion_sort(B,sizeof(B)/sizeof(B[0]));
    cout << "INSERTION SORT: ";
    s.print_sort(B, sizeof(B)/sizeof(B[0]));

    int C[] = {23,22234,18,20,50,0,6};
    vector<int>s_s(C, C + sizeof(C)/sizeof(C[0]));
    s.selection_sort(s_s);
    cout << "INSERTION SORT: ";
    s.print_sort(s_s);

    int D[] = {2,22234,309,20,43,0,6};
    vector<int>b_b(D, D + sizeof(D)/sizeof(D[0]));
    s.bubble_sort(b_b);
    cout << "BUBBLE SORT: ";
    s.print_sort(b_b);

    int E[] = {33, 2,22234,309,20,43,0,6};
    vector<int>q_q(E, E + sizeof(E)/sizeof(E[0]));
    s.quick_sort(q_q, 0, q_q.size()-1);
    cout << "QUICK SORT: ";
    s.print_sort(q_q);
}

int main() {
    stest1();
    return 1;
}
