#include "dp.h"
using namespace std;

void dptest1(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    string S("hehbeb");
    cout << "Minimum number of splits for which each half is a palindrome of \"" << S << "\" is " 
         << d.min_num_palin_split(S) << endl;
}     

void dptest2(void) {
    cout << "--------------Started test " << __func__ << endl;
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
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    int arr[] = {3,2,2,0,4};
    vector<int> A(arr, arr+sizeof(arr)/sizeof(arr[0]));
    cout << "Min jumps to reach final index with the array {"; 
    for(int i=0; i<A.size(); i++) {
        cout << A[i] << ",";
    }
    cout << "} is " << d.min_idxs_to_reach_final_idx(A) << endl;
}
     
void dptest4(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    int R1[] = {3,2,1,9};
    int R2[] = {6,3,0,9};
    vector<vector<int>> A;
    A.push_back(vector<int> (R1, R1+sizeof(R1)/sizeof(R1[0])));
    A.push_back(vector<int> (R2, R2+sizeof(R2)/sizeof(R2[0])));
    cout << "Max sum in 2N grid {<";
    for(int i=0; i<A[0].size(); i++) {
        cout << R1[i] << ",";
    }
    cout << ">, <"; 
    for(int i=0; i<A[0].size(); i++) {
        cout << R2[i] << ",";
    }
    cout << ">} without considering adjacent nodes of dist of 1 is " << d.max_sum_2n_grid(A) << endl;
}

void dptest5(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    string A("hello");
    string B("helloworld");
    cout << "Min operations to convert string \"" << A << "\" to \"" << B << "\" are "  
         << d.min_steps_to_transform_A_to_B(A, B) << endl;
}

void dptest6(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    int R1[] = {0,6,7,8,9,5,6,7,8,11};
    vector<int> A(R1, R1+sizeof(R1)/sizeof(R1[0]));
    cout << "LIS of {";
    for(int i=0; i<A.size(); i++) {
        cout << R1[i] << ",";
    }
    cout << "} is " << d.LIS(A) << endl;
}

void dptest7(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    string A("ab");
    string P("ab*b");
    cout << "Regex match of \"" << A << "\" with \"" << P << "\" is " << d.regex_match_dot_star(A,P) << endl;
}
 
void dptest8(void) {
    cout << "--------------Started test " << __func__ << endl;
    DP d;
    int A = 3;
    cout << "Structurally unique BST's with \"" <<  A << "\" elements is " << d.unique_BST(A) << endl;
}
 
int main() {
    dptest1();
    dptest2();
    dptest3();
    dptest4();
    dptest5();
    dptest6();
    dptest7();
    dptest8();
    return 0;
}
