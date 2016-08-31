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
