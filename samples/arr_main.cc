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

void test3() {
    cout << "-------------Executing Test: " << __func__ << endl;
    Arr arr_obj;
    int A[] = {1 ,3, 3, 4, 5, 7, 22, 23};
    int B[] = {1, 2, 6, 10, 11, 17, 19, 20};
    cout << " Median of two same sized sorted arrays is : "
         << arr_obj.median_two_sorted_arrays_same_size(A, B, 8) << endl;
}

void test4() {
    cout << "-------------Executing Test: " << __func__ << endl;
    Arr arr_obj;
    int Ar[] = {1, 6, 10, 11, 11, 6, 6, 10, 10, 11};
    vector<int> A(Ar, Ar+(sizeof(Ar)/sizeof(Ar[0])));
    cout << " single occurrence of the array element is : "
         << arr_obj.find_sing_occur_with_others_rep_3_times(A) << endl;
}

int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}
