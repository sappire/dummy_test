#include <iostream>
#include <string>
using namespace std;

class String {
public:
    void reverse(string &S);
    void print_dups_of_str(string &S);
    void reverse_words(string &S);
private:
    void check_and_insert(char c, string &res);
};
