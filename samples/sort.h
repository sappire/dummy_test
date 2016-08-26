#include <iostream>
#include <vector>

using namespace std;

class Sort {
public:
    void merge_sort(vector<int> &A, int s, int h);  
    void insertion_sort(int A[], int n); 
    void selection_sort(vector<int> &A); 
    void bubble_sort(vector<int> &A); 
    void print_sort(const vector<int> A);
    void print_sort(int A[],int n);
private:
    void merge(vector<int> &A, const vector<int> L, const vector<int> R);
};
