#include "arr.h"

int main() {
    Arr arr_obj;
    int b1[] = {3, 5, 7};
    int b2[] = {1, 2, 10};
    vector<vector<int>> A;
    A.push_back(vector<int> (b1, b1 + 3));
    A.push_back(vector<int> (b2, b2 + 3));
    arr_obj.merge_k_sorted_arrays(A);
    return 0;
}
