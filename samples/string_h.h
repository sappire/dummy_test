#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

class String {
public:
    void reverse(string &S);
    void print_dups_of_str(string &S);
    void reverse_words(string &S);
    string long_sub_non_repeat_char(string &S);
    string LPS(const string &S);
    string decode(const string &S);
    string multiply_numbers(const string &S1, const string &S2);
    int unique_sub_strings(const string &S);
    string min_substr_length_containing_all_chars_of_another_str(const string &S, const string &T);
    int max_substr_length_containing_chars_atleast_ktimes(const string &S, int k);
    void print_all_ips_of_subnet(const string &S);
    vector<vector<string>> palindrome_partition(const string &A);
private:
    void check_and_insert(char c, string &res);
    string _expand_around_center(const string &S, int i, int j);
    void _correct_string(stack<char> &s);
    int _get_number(stack<char> &s);
    int __get_base_prefix_current_octet(const string &S, const int &fixed_octets);
    string __get_fixed_prefix(const string &S, const int &fixed_octets);
    int __get_total_fixed_chars(const string &S, const int &fixed_octets);
    int __get_netmask(const string &S);
    int __to_integer(const string &S, const int &start_idx, int final_idx=0);
    void _palindrome_partition(vector<vector<string>> &res, vector<string> &curr, const string &A,
                               int s, int e);
    bool _is_palindrome(const string &A);
};
