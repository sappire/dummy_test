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

string
String::long_sub_non_repeat_char(string &S) {
    int temp[26];
    int i = 0;
    int j = 0;
    string max = "";
    for (int m=0; m < 26; m++) temp[m] = -1;
    for(; j < S.size(); j++) {
        if (temp[S[j]-'a'] != -1) {
            i = temp[S[j]-'a'] + 1;
        }
        temp[S[j]-'a'] = j;
        if (max.size() < j-i+1) {
            max.clear();
            max += S.substr(i,j-i+1);
        }
    }
    return max;
}

string 
String::_expand_around_center(const string &S, int i, int j) {
    while(i >=0 && j < S.size() && S[i] == S[j]) {
        i--;
        j++;
    }
    return S.substr(i+1, j-i-1);
}

string
String::LPS(const string &S) {
    string lps;
    string s1,s2;
    for(int i=0; i < S.size(); i++) {
        s1.clear();
        s2.clear();
        s1 += _expand_around_center(S,i,i);
        if (s1.size() > lps.size()) {
            lps.clear();
            lps += s1;
        }
        s2 += _expand_around_center(S,i,i+1);
        if (s2.size() > lps.size()) {
            lps.clear();
            lps += s2;
        }
    }
    return lps;
}
