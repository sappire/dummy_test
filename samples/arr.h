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
    int median_two_sorted_arrays_same_size(int A[] , int B[], int n);
    void rotate_matrix_clockwise(vector<vector<int>> &A);
    int find_sing_occur_with_others_rep_3_times(const vector<int> &A);
    int missing_number_among_sorted_numbers_increasing_by_one(const vector<int> &A);
private:
    int _find_median(int A[], int n);
    int _next_element_clockwise(const vector<vector<int>> &A, int max_dist,
                                int &i, int &j, int &dir);
};
