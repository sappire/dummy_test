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

//4,15,1,4,2,2,3,2,2,2,1,4
//2,3,1,4,2,4,3,6,1,2,2,2,1,4
bool
DP::can_reach_final_idx(const vector<int> &A) {
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

//3.2.1.0,4
int 
DP::min_idxs_to_reach_final_idx(const vector<int> &A) {
    vector<int> dp(A.size(), -1);
    dp[0] = 0;
    int maxpos = A[0];
    int currmaxpos = A[0];
    int jumps = 1;
    for(int i=1; i <= maxpos; i++) {
        if (i == A.size()-1) return jumps;
        currmaxpos = max(currmaxpos, i+A[i]);
        if (i==maxpos) {
            maxpos = currmaxpos;
            jumps++;
        }
    }
    return -1;
}

//3 4 1 2
//2 5 3 6
//3 4 1 2
//2 5 3 6

int
DP::max_sum_2n_grid(const vector<vector<int>> &A) {
    int max_sum = INT_MIN;
    int elem = 0;
    int curr_i = 0;
    int curr_j = 0;
  
    for(int a = 0; a < A.size() * A[0].size(); a++) {
        curr_i = a / A[0].size();
        curr_j = a % A[0].size();
        elem = A[curr_i][curr_j];
        for(int i=curr_i; i < A.size(); i++) {
            for(int j=0; j < A[i].size(); j++) {
                if ((abs(i-curr_i) < 2) && (abs(j-curr_j) < 2)) continue;
                max_sum = max(max_sum,elem+A[i][j]);
            }
        }
    }
    return max_sum;
}
