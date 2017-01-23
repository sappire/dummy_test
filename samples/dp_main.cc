#include "dp.h"
using namespace std;

void dptest1(void) {
    cout << "Started test " << __func__ << endl;
    DP d;
    string S("hehbeb");
    cout << "Minimum number of splits for which each half is a palindrome of \"" << S << "\" is " 
         << d.min_num_palin_split(S) << endl;
}     

void dptest2(void) {
    cout << "Started test " << __func__ << endl;
    DP d;
    int arr[] = {3,2,1,0,4};
    vector<int> A(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout << "Can you reach final index with {"; 
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << ",";
    }
    cout << "} is " << d.can_reach_final_idx(A) << endl;
}     

void dptest3(void) {
    cout << "Started test " << __func__ << endl;
    DP d;
    int arr[] = {3,2,2,0,4};
    vector<int> A(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout << "Min jumps to reach final index with the array {"; 
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << ",";
    }
    cout << "} is " << d.min_idxs_to_reach_final_idx(A) << endl;
}
     
int main() {
    dptest1();
    dptest2();
    dptest3();
    return 0;
}
