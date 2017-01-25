#include <iostream>
#include <vector>

using namespace std;

class DP{
private:
    bool _is_palindrome(string s, int l, int h);
public:
    int min_num_palin_split(string s);
    bool can_reach_final_idx(const vector<int> &A);
    int min_idxs_to_reach_final_idx(const vector<int> &A);
    int max_sum_2n_grid(const vector<vector<int>> &A);
    int min_steps_to_transform_A_to_B(const string &A, const string &B);
    int LIS(vector<int> &A);
};
