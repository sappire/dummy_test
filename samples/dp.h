#include <iostream>
#include <vector>

using namespace std;

class DP{
private:
    bool _is_palindrome(string s, int l, int h);
    bool _regex_match_dot_star(const string &A, int A_idx, const string &P, int P_idx);
public:
    int min_num_palin_split(string s);
    bool can_reach_final_idx(const vector<int> &A);
    int min_idxs_to_reach_final_idx(const vector<int> &A);
    int max_sum_2n_grid(const vector<vector<int>> &A);
    int min_steps_to_transform_A_to_B(const string &A, const string &B);
    int LIS(vector<int> &A);
    bool RSS(const string &A);
    bool regex_match_dot_star(const string &A, const string &P);
    int unique_BST(int A);
    int maxProfit(vector<int>& prices);
    int distinct_subsequences(string &S, string &T);
};
