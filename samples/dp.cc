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
//Keep populating the DP with LIS including current index. update max.
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

//abab
//ab*bab
bool 
DP::_regex_match_dot_star(const string &A, int A_idx, const string &P, int P_idx) {
    int A_sz = A.size();
    int P_sz = P.size();

    if ((A_sz-A_idx) <=0 && (P_sz-P_idx) <=0) return true;
    if ((P_sz-P_idx) <= 0) return (A_sz-A_idx <=0 );
    if ((A_sz-A_idx) <=0 || (P_sz-P_idx) <=0) return false;

    //next char is not *
    if ((A_sz-A_idx) > 1 && (P_sz-P_idx) > 1) {
        if(P[P_idx+1] != '*') {
            if(P[P_idx] == A[A_idx] || (P[P_idx] == '.' && A_sz-A_idx != 0)) {
                return _regex_match_dot_star(A,A_idx+1,P,P_idx+1);
            } else {
                return false;
            }
        }
    }

    //next char is *
    while((P_idx < P_sz && A_idx < P_sz) &&
          (P[P_idx] == A[A_idx]) || (P[P_idx] == '.' && (A_sz-A_idx != 0))) {
        if ((P_idx + 2) < P_sz) {
            if(_regex_match_dot_star(A,A_idx,P,P_idx+2)) return true;
        }
        A_idx++;
    }
    
    return _regex_match_dot_star(A,A_idx,P,P_idx+2);
}

bool
DP::regex_match_dot_star(const string &A, const string &P) {
    return _regex_match_dot_star(A,0,P,0);
}

/*1,2,3

 (1)     (2)     (3)   (4)    (5)     (6)
  1       1       2     2      3       3
   2       3     1 3     3    2       1
    3     2             1    1         2

 Note answer is "5" as the (4) is not structurally unique as it is as same as (2)

*/
int
DP::unique_BST(int A) {
    if (A==1) return 1;
    if (A==2) return 2;

    vector<int> dp(A+1,0);
    dp[0] = 1;
    dp[1] = 1;
    for (int i=2; i<=A; i++) {
        for(int k=1; k <= i; k++) {
            dp[i] += dp[k-1]*dp[i-k];
        }
    }
    return dp[A];
}

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.

Example 1:
Input: [7, 1, 5, 3, 6, 4]
Output: 5

max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
Example 2:
Input: [7, 6, 4, 3, 1]
Output: 0

In this case, no transaction is done, i.e. max profit = 0.
*/
int 
DP::maxProfit(vector<int>& prices) {
    if (prices.size() < 2) return 0;
    int low_price = prices[0];
    int max_profit = 0;
    for(int i=1; i < prices.size(); i++) {
        if (prices[i] < low_price) low_price = prices[i];
        max_profit = max(max_profit, prices[i] - low_price);
    }
    return max_profit;
}

/* Distinct Subsequences that can be formed by deleting the original characters in string S, without changing the position to look alike as string T 
   S = "rabbbit",  T = "rabbit"
   if S[j] == T[i]      // We need to count subsequences without current S[j] +   subsequences without current S[j] and T[i]
   if S[j] != T[i]      // We need to count subsequences without current S[j] 
 
*/ 

int
DP::distinct_subsequences(string &S, string &T) {
    if (S.size() < T.size()) return 0;
    vector<vector<int>> map(T.size()+1, vector<int>(S.size()+1, 0));

    for(int j=0; j < map[0].size(); j++) {
        map[0][j] = 1;
    }

    for(int i=1; i < map.size(); i++) {
        map[i][0] = 0;
    }

    for(int i=0; i < map.size()-1; i++) {
        for(int j=0; j < map[0].size()-1; j++) {
            if (T[i] == S[j]) map[i+1][j+1] = map[i][j];
            map[i+1][j+1] += map[i+1][j];
        }
    }
    return map[T.size()][S.size()];
}



