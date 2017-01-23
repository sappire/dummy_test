#include "dp.h"

using namespace std;

bool 
DP::_is_palindrome(string s, int l, int h) {
	while( l < h) {
		if (s[l] != s[h]) return false;
        l++;
        h--;
    }
    return true;
}

int 
DP::min_num_palin_split(string s) {
    int split[s.size()];
    for (int i=0; i < s.size(); i++) {
        split[i] = i;
    }

    for(int i=0; i < s.size(); i++) {
        if(_is_palindrome(s,0,i)) {
            split[i] = 0;
            continue;
        }
        for (int j=0; j < i; j++) {
            if(_is_palindrome(s,j+1,i) && split[i] > split[j] + 1) {
                split[i] = split[j] + 1;
            }
        }
    }
    return split[s.size()-1];
}

//3,2,2,0,4
bool
DP::can_reach_final_idx(vector<int> &A) {
    vector<bool> dp(A.size(), false);
    dp[0] = true;
    int max_left = A[0]-1;
    for(int i=1; i < A.size()-1; i++) {
        dp[i] = dp[i-1] && (max_left > 0);
        if (!dp[i]) return false;
        max_left = max(max_left-1,A[i]-1);
    }
    return true;
}
