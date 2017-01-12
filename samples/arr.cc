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
