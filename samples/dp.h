#include <iostream>
#include <vector>

using namespace std;

class DP{
private:
    bool _is_palindrome(string s, int l, int h);
public:
    int min_num_palin_split(string s);
    bool can_reach_final_idx(vector<int> &A);
};
