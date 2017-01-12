#include <iostream>
#include <vector>

using namespace std;
class pq_node {
public:
    int value_;
    int arr_idx_;
    int next_idx_;
    pq_node() {
        value_ = 0;
        next_idx_ = -1;
    }
    pq_node(int value, int arr_idx, int next_idx) {
        value_ = value;
        arr_idx_ = arr_idx;
        next_idx_ = next_idx;
    }
    bool operator>= (const pq_node& n) const {
        return (*this).value_ >= n.value_;
    }
};

class Arr {
public:
    vector<int> merge_k_sorted_arrays(vector<vector<int>> &A);
    vector<vector<int>> anti_diagonal_sqr_matrix(vector<vector<int>> &A);
};
