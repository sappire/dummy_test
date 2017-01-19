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
private:
    void check_and_insert(char c, string &res);
    string _expand_around_center(const string &S, int i, int j);
    void _correct_string(stack<char> &s);
    int _get_number(stack<char> &s);
};
