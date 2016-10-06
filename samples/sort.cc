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
Sort::print_sort(int A[], int n) {
    for (int i=0; i < n; i++) {
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
  
    int mid = h + ((s - h) / 2);
//    int mid = h - ((h - s) / 2);

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

void 
Sort::insertion_sort(int A[], int n) {
    for (int i=1; i < n; i++) {
        int key = A[i];
        int j = i-1;
        while (j >= 0) {
            if (A[j] > key) {
                A[j+1] = A[j];
                j--;
            } else {
                break;
            }
        }
        A[j+1] = key;
    }
}

void 
Sort::selection_sort(vector<int> &A) {
    int min_idx = -1;
    for (int i=0; i < A.size() - 1; i++) {
        min_idx = i;
        for(int j=i+1; j < A.size(); j++) {
            if (A[j] < A[min_idx]) {
                min_idx = j;
            }
        }
        int tmp = A[i];
        A[i] = A[min_idx];
        A[min_idx] = tmp;
    }
}

void
Sort::bubble_sort(vector<int> &A) {
    for(int i=0; i < A.size() -1 ; i++) {
        bool swapped = false;
        for(int j=0 ; j < A.size() - i - 1 ; j++) {
            if (A[j] > A[j+1]) {
                int tmp = A[j+1];
                A[j+1] = A[j];
                A[j] = tmp;
                swapped = true;
            }
        }
        if (!swapped) return;
    }
    
}

int 
Sort::partition(vector<int> &A, int s, int h) {
    int pivot = A[h];
    int i = s-1;
    for (int j=s; j < h; j++) {
        if (A[j] <= pivot) {
            int tmp = A[++i];
            A[i] = A[j];
            A[j] = tmp;
        }
    }
    A[h] = A[++i];
    A[i] = pivot;
    return i;
}

void 
Sort::quick_sort(vector<int> &A, int s, int h) {
    if (s>=h) return;
    cout << "s is" << s << " h is " << h << endl;
    int p = partition(A,s,h);
    quick_sort(A,s,p-1);
    quick_sort(A,p+1,h);
}
