#include "dp.h"

using namespace std;

bool 
DP::is_palindrome(string s, int l, int h) {
	while( l < h) {
		if (s[l] != s[h]) return false;
        l++;
        h--;
    }
    return true;
}

int 
DP::min_num_palin_split(string s) {
    int split[s.size()];
    for (int i=0; i < s.size(); i++) {
        split[i] = i;
    }

    for(int i=0; i < s.size(); i++) {
        if(is_palindrome(s,0,i)) {
            split[i] = 0;
            continue;
        }
        for (int j=0; j < i; j++) {
            if( is_palindrome(j+1,i) && split[i] > split[j] + 1) {
                split[i] = split[j] + 1;
            }
        }
    }
    return split[s.size()-1];
}
