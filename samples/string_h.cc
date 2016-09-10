#include "string_h.h"

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
//    cout << "\t c: " << c << "-R: " << res << "-F: " << found;
    if(found == string::npos) {
//        cout << "Did not find entry";
        res.push_back(c);
    }
}

void
String::print_dups_of_str(string &S) {
    string res;
    for (int i=0; i< S.size(); i++) {
//        cout << "-i: "<< i;
        for(int j=i+1; j<S.size(); j++) {
            if (S[i] == S[j]) {
//                cout << "-j: " << j;                
                check_and_insert(S[i],res);
                break;
            }
        }
    }
    cout << res << endl;
}
