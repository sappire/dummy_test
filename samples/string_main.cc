#include "string_h.h"

void
stest1(void) {
    cout << "------------Started string test: " << __func__ << endl;
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
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string str("Reverse the String words");
    s.reverse_words(str);
}

void
stest3(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string str("abcbde");
    cout << "Longest substring with no repeating characters is " 
         << s.long_sub_non_repeat_char(str) << endl;
}

void
stest4(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string str("ababba");
    cout << "Longest palindromic substring is "  << s.LPS(str) << endl;
}

void
stest5(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string str("a2[b10[c]]");
    cout << "String decoded to " << s.decode(str) << endl;
}

void
stest6(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string S1("33");
    std::string S2("89");
    cout << "Product of " << S1 << " and " << S2 << " is " << s.multiply_numbers(S1,S2) << endl;
}

void
stest7(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string S("zxyza");
    cout << "Number of Unique substrings from qiven string \"" << S << "\" are "
         << s.unique_sub_strings(S) << endl;
}

void
stest8(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string S("helloworld");
    std::string T("wr");
    cout << "Minimum length substring of the string \"" << S << "\" that contains " 
         << "all characters of another string \"" << T << "\" is \"" 
         << s.min_substr_length_containing_all_chars_of_another_str(S,T) << "\"" << endl;
}

void
stest9(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string S("abbabc");
    cout << "Max length substring of \"" << S << "\" with atleast k times characters repeated are \"" 
         << s.max_substr_length_containing_chars_atleast_ktimes(S,2) << "\"" << endl;
}

void
stest10(void) {
    cout << "------------Started string test: " << __func__ << endl;
    String s;
    std::string S("10.10.10.0/24");
    s.print_all_ips_of_subnet(S);
}

void
stest11(void) {
    cout << "------------Started PALIN PARTITION test: " << __func__ << endl;
    String s;
    std::string S("aab");
    auto res = s.palindrome_partition(S);
    cout << "[" << endl;
    for (auto it = res.begin(); it != res.end(); it++) {
        cout << "\t[";
        for (auto inner_it = it->begin(); inner_it != it->end(); inner_it++) {
            cout << "\"" << *inner_it;
            if(inner_it+1 != it->end()) cout << "\",";
        }
        cout << "]," << endl;
    }
    cout << "]\n";
}

void
stest12(void) {
    cout << "------------String Trie test: " << __func__ << endl;
    String s;
    Trie t;
    std::string S1("hello");
    std::string S2("hello world");
    s.insert_word(S1, t.get_root());
    s.insert_word(S2, t.get_root());
    cout << "Word \"" << S1 << "\" exists in Trie ? " << status((enabled_t)s.word_exists(S1, t.get_root())) << endl;
    cout << "Word \"" << S2 << "\" exists in Trie ? " << status((enabled_t)s.word_exists(S2, t.get_root())) << endl;
    std::string S3("hel");
    cout << "Word \"" << S3 << "\" exists in Trie ? " << status((enabled_t)s.word_exists(S3, t.get_root())) << endl;
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
    stest9();
    stest10();
    stest11();
    stest12();
    return 0;
}
