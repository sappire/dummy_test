#include "arr.h"
#include <queue>

vector<int>
Arr::merge_k_sorted_arrays(vector<vector<int>> &A) {
    priority_queue<pq_node,vector<pq_node>,greater_equal<pq_node>> pq;
    int num_arrays = A.size();
    int total = 0;
    for(int i=0; i < num_arrays; i++) {
        if (A[i].size() > 0) {
            total += A[i].size();
            pq_node temp(A[i][0], i, 1);
            pq.push(temp);
        }
    }

    vector<int> res;
    while(total > 0) {
        pq_node elem(pq.top());
        res.push_back(elem.value_);
        total--;
        pq.pop();
        if (elem.next_idx_ < A[elem.arr_idx_].size()) {
            elem.value_ = A[elem.arr_idx_][elem.next_idx_];
            elem.next_idx_++;
        } else {
            elem.value_ = INT_MAX;
        }
        pq.push(elem);
    }
    cout << "Result of merging all K sorted arrays" << endl; 
    for (int i=0; i < res.size(); i++) {
        cout << res[i] << " ";
    } 
    cout << endl;
    return res;
}

vector<vector<int>>
Arr::anti_diagonal_sqr_matrix(vector<vector<int>> &A) {
    vector<vector<int>> res;
    int size = A.size();
    int start = 1;
    int iter = 0;
    int i = 0;
    int j = 0;
    bool flap = false;
    int flap_incr = 0;
    while(start <= size * size) {
         res.push_back(vector<int> ());
         while((i <= iter) && (j >= 0)) {
             res[res.size()-1].push_back(A[i++][j--]);
             start++;
         }

         if (!flap) {
             if ((iter+1) == size) {
                 flap = true;
                 i = ++flap_incr;
                 j = size-1;
             } else {
                 iter++;
                 i = 0;
                 j = iter;
             }
         } else {
             i = ++flap_incr;
             j = size-1;
         }
    }

    cout << "Result of anti-diagonal elements of square matrix is" << endl; 
    for (int i=0; i < res.size(); i++) {
        cout << "[";
        for (int j=0; j < res[i].size(); j++) {
            cout << res[i][j] << " ";
        }
        cout << "]";
    } 
    cout << endl;

    return res;
}

int
Arr::_find_median(int A[], int n) {
    if (n % 2 == 0) {
        return (A[n/2-1] + A[n/2])/2;
    }
    return A[n/2];
}

int 
Arr::median_two_sorted_arrays_same_size(int A[] , int B[], int n) {
    if (n == 0) { 
        return 0;
    } else if (n == 1) {
        return (A[0]+B[0]) / 2;
    } else if (n == 2) {
        return ((max(A[0],B[0]) + min (A[1],B[1]))/2);
    }

    int a_med = _find_median(A,n);
    int b_med = _find_median(B,n); 

    int res = 0;
    if (a_med == b_med) {
        return a_med;
    } else if (a_med > b_med) {
            res = median_two_sorted_arrays_same_size(A, B+n/2, n - n/2);
    } else {
            res = median_two_sorted_arrays_same_size(A+n/2, B, n - n/2);
    }
    return res;
}

int 
Arr::_next_element_clockwise(const vector<vector<int>> &A, int max_dist,
                             int &i, int &j, int &dir) {

    if (dir == 0) {
        if(j + max_dist > A.size() - 1) {
            dir = 1;
            i = j;
            j = max_dist;
        } else {
            j += max_dist;
        }
    } else if (dir == 1) {
        if(i + max_dist > A.size() - 1) {
            dir = 2;
            j -= i;
            i = max_dist;
        } else {
            i += max_dist;
        }
    } else if (dir == 2) {
        if(j - max_dist < 0) {
            dir = 3;
            i = j;
            j = A.size() - 1 - max_dist;
        } else {
            j -= max_dist;
        }
    } else if (dir == 3) {
        if(i - max_dist < 0) {
            dir = 0;
            j = max_dist - i;
            i = A.size() - 1 - max_dist;
        } else {
            i -= max_dist;
        }
    }
    return A[i][j];
}

void
Arr::rotate_matrix_clockwise(vector<vector<int>> &A) {
    int dir = 0;
    int start = 0;
    int max = A.size() - 1;
    int i = 0, j = 0; 
    int curr = 0;
    int next = 0;
    bool cycle = false;
    int start_outer = 0;
    while(start_outer <= (A.size()/2)) {
        start = start_outer;
        max -= start_outer;
        i = start;
        while(start < max) {
            j = start;
            next = A[i][j]; 
            while(!cycle) {
                if (dir == 0) {
                    curr = next;
                    next = _next_element_clockwise(A, max, i, j, dir);
                    A[i][j] = curr;
                    dir = 1;
                } else if (dir == 1) {
                    curr = next;
                    next = _next_element_clockwise(A, max, i, j, dir);
                    A[i][j] = curr;
                    dir = 2;
                } else if (dir == 2) {
                    curr = next;
                    next = _next_element_clockwise(A, max, i, j, dir);
                    A[i][j] = curr;
                    dir = 3;
                } else if (dir == 3) {
                    curr = next;
                    next = _next_element_clockwise(A, max, i, j, dir);
                    A[i][j] = curr;
                    dir = 0;
                    cycle = true;
                }
            }
            start++;
            cycle = false;
        }
        start_outer++;
    }
}

int
Arr::find_sing_occur_with_others_rep_3_times(const vector<int> &A) {
    int ones = 0, twos = 0;
    int threes = 0;
    for (int i=0; i < A.size(); i++) {
        twos |= (ones & A[i]);
        ones ^= A[i];
        threes = (ones & twos);
        ones &= (~threes);
        twos &= (~threes);
    } 
    return ones;
}

//5,6,8,9,10,11,12
int
Arr::missing_number_among_sorted_numbers_increasing_by_one(const vector<int> &A) {
    int s = 0;
    int h = A.size()-1;
    int mid = 0;
    while(h - s > 1) {
        mid = s + (h-s)/2;
        if (h - mid == A[h] - A[mid]) {
            h = mid;
        } else {
            s = mid;
        }
    } 
    return A[mid]+1;
}

//3,2,4,6,1,5
int
Arr::kth_largest_element(const vector<int> &A, const int &k) {
    if (k > A.size()) return -1;
    priority_queue<int> pq;
    for(int i=0; i <= A.size()-k; i++) {
        pq.push(A[i]);
    }
    if (pq.size() == 0) return -1;
    for(int i=A.size()-k+1; i < A.size(); i++) {
        if (pq.top() > A[i]) {
            pq.pop();
            pq.push(A[i]);
        }        
    } 
    return pq.top();
}
