#include "string_h.h"

void
stest1(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("hello world");
    cout << "Original String: " << str << endl;
    s.reverse(str);
    cout << "Reversed String: " << str << endl;
    s.reverse(str);
    cout << "Print duplicates of the string--\""<< str << "\": ";
    s.print_dups_of_str(str);
}

void
stest2(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("Reverse the String words");
    s.reverse_words(str);
}

void
stest3(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("abcbde");
    cout << "Longest substring with no repeating characters is " 
         << s.long_sub_non_repeat_char(str) << endl;
}

void
stest4(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("ababba");
    cout << "Longest palindromic substring is "  << s.LPS(str) << endl;
}

void
stest5(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string str("a2[b10[c]]");
    cout << "String decoded to " << s.decode(str) << endl;
}

void
stest6(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string S1("33");
    std::string S2("89");
    cout << "Product of " << S1 << " and " << S2 << " is " << s.multiply_numbers(S1,S2) << endl;
}

void
stest7(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string S("zxyza");
    cout << "Number of Unique substrings from qiven substring \"" << S << "\" are "
         << s.unique_sub_strings(S) << endl;
}

void
stest8(void) {
    cout << "Started string test: " << __func__ << endl;
    String s;
    std::string S("helloworld");
    std::string T("ew");
    cout << "Minimum length substring of the string \"" << S << "\" that contains " 
         << "all characters of another string \"" << T << "\" is \"" 
         << s.min_substr_length_containing_all_chars_of_another_str(S,T) << "\"" << endl;
}

int main() {
    stest1();
    stest2();
    stest3();
    stest4();
    stest5();
    stest6();
    stest7();
    stest8();
    return 0;
}
