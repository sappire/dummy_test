#include "arr.h"

void test1() {
    cout << "-------------Executing Test: " << __func__ << endl;
    Arr arr_obj;
    int b1[] = {3, 5, 7, 23};
    int b2[] = {1, 2, 10};
    vector<vector<int>> A;
    A.push_back(vector<int> (b1, b1 + 4));
    A.push_back(vector<int> (b2, b2 + 3));
    arr_obj.merge_k_sorted_arrays(A);
}

void test2() {
    cout << "-------------Executing Test: " << __func__ << endl;
    Arr arr_obj;
    int b1[] = {1, 2, 3, 4};
    int b2[] = {5, 6, 7, 8};
    int b3[] = {9, 10, 11, 12};
    int b4[] = {13, 14, 15, 16};
    vector<vector<int>> A;
    A.push_back(vector<int> (b1, b1 + 4));
    A.push_back(vector<int> (b2, b2 + 4));
    A.push_back(vector<int> (b3, b3 + 4));
    A.push_back(vector<int> (b4, b4 + 4));
    arr_obj.anti_diagonal_sqr_matrix(A);
}

int main() {
    test1();
    test2();
    return 0;
}
