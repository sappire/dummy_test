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
