#include <iostream>
#include <string>
#include <stack>
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
private:
    void check_and_insert(char c, string &res);
    string _expand_around_center(const string &S, int i, int j);
    void _correct_string(stack<char> &s);
    int _get_number(stack<char> &s);
};
