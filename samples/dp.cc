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

//sd
//con
/*
1 + rep(d,on)--> 1 + (1 + rep(,n)) = 3
                 1 + (1 + in(d,n)) = 2 + (1 + rep(,)) = 3   = 3
                                     2 + (1 + in(d,)) = 4
                                     2 + (1 + del(,n)) = 4
                 1 + (1 + del(,on)) = 4
1 + in(sd,on)---> 3
1 + del(d,con)
*/
int
DP::min_steps_to_transform_A_to_B(const string &A, const string &B) {
    vector<vector<int>> dp(A.size()+1 , vector<int>(B.size()+1,0));
    for(int i=0 ; i < dp.size(); i++) {
        for(int j=0; j < dp[0].size(); j++) {
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
        }
    }

    for(int i=1 ; i < dp.size(); i++) {
        for(int j=1; j < dp[0].size(); j++) {
            if (A[i-1] == B[j-1])
                dp[i][j] = dp[i-1][j-1];
            else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j]));
        }
    }
    return dp[A.size()][B.size()];
}

//0, 6, 7 ,8, 9, 5, 6, 7, 8 11
int
DP::LIS(vector<int> &A) {
    vector<int> dp(A.size(), 0);
    dp[0] = 1;
    int res = 0;;
    for(int i=1; i < A.size(); i++) {
        dp[i] = 1;
        for(int j = 0; j < i; j++) {
            if (A[i] > A[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}
