#include <iostream>
#include <vector>

using namespace std;

class Sort {
public:
    void merge_sort(vector<int> &A, int s, int h);   
    void print_sort(const vector<int> A);
private:
    void merge(vector<int> &A, const vector<int> L, const vector<int> R);
};
