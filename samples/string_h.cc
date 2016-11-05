#include "string_h.h"
#include <sstream>
#include <vector>

void
String::reverse(string &S) {
    if (S.size() < 2) return;

    int mid = (S.size()/2);
    for (int i=0; i < mid; i++) {
        char tmp = S[i];
        int j = S.size() - i - 1;
        S[i] = S[j];
        S[j] = tmp;
    }
}

void
String::check_and_insert(char c, string &res) {
    size_t found = res.find(c);
    if(found == string::npos) {
        res.push_back(c);
    }
}

void
String::print_dups_of_str(string &S) {
    string res;
    for (int i=0; i< S.size(); i++) {
        for(int j=i+1; j<S.size(); j++) {
            if (S[i] == S[j]) {
                check_and_insert(S[i],res);
                break;
            }
        }
    }
    cout << res << endl;
}

void
String::reverse_words(string &s) {
    stringstream ss;
    ss.str(s);
    string item;
    stringstream res;
    while(getline(ss,item,' ')) {
        res << item << ' ';
    }
//    if (res.str().size() > 0) res.str().erase(res.str().size()-1);
    cout << res.str() << endl;
/*    vector<string> res;
    string delim;
    delim = " ";
    while (getline(ss, item, ' ')) {
        res.insert(res.begin(), item);
        res.insert(res.begin(), delim);
        item.clear();
    }
    if (res.size() > 0) {
        res.erase(res.begin());
    }
    for (int i =0 ; i < res.size(); i++) {
        cout << res[i];
    }
    cout << endl;
*/
}
