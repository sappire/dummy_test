#include "sort.h"

using namespace std;

void 
Sort::print_sort(const vector<int> A) {
    for (int i=0; i < A.size(); i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

void 
Sort::merge(vector<int> &A, const vector<int> L, const vector<int> R) {
    int i=0;
    int j=0;
    int k=0;

    for ( ; k < A.size(); k++) {
        if ((i < L.size()) && (j < R.size())) {
            if (L[i] <= R[j]) {
                A[k] = L[i];
                i++;
            } else {
                A[k] = R[j];
                j++;
            }
            continue;
        }

        if (i < L.size()) {
            A[k] = L[i];
            i++;
        }
        if (j < R.size()) {
            A[k] = R[j];
            j++;
        }

    }
}

void  
Sort::merge_sort(vector<int> &A, int s, int h) {
    if (A.size() < 2) return;
//    if (s == h) return;
  
    int mid = h - ((h - s) / 2);

    vector<int> L;
    vector<int> R;
    for (int i=s; i < mid; i++) {
        L.push_back(A[i]);
    }
    for (int i=mid; i <= h; i++) {
        R.push_back(A[i]);
    }
    merge_sort(L, 0, L.size()-1);
    merge_sort(R, 0, R.size()-1);
    merge(A, L, R);
    return;
}
