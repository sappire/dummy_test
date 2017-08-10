#include "string_h.h"
#include <sstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

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

int
String::_get_number(stack<char> &s) {
    int i=0;
    int num = 0;
    int mul = 1;
    char c;
    while(!s.empty()) {
        c = s.top();
        if(c >= '0' && c <= '9') {
            if (i == 0) {
                num = c-'0';
                i++;
            } else {
                mul *= 10;
                num += mul * (c-'0');
            }
            s.pop();
        } else {
            break;
        }
    }
    return num;
}

void
String::_correct_string(stack<char> &s) {
    string curr;
    char c = '\0';
    int mul_by = 0;
    while(!s.empty()) {
        c = s.top();
        s.pop();
        if(c != '[') {
            curr = c + curr;
        } else {
            mul_by = _get_number(s);
            string temp = curr;
            while(mul_by > 1) {
                curr = temp + curr;
                mul_by--;
            }
            break; 
        }
    }
    for(int i = 0; i < curr.size(); i++) s.push(curr[i]);
}

    //a3[b2[c]e2[d]]
    //a3[bccedd
string
String::decode(const string &S) {
    string res;
    stack<char> s;
    for(int m=0; m<S.size(); m++) {
        if(S[m] == ']') {
            _correct_string(s);
        } else {
            s.push(S[m]);
        }
    }

    while(!s.empty()) {
        res = s.top() + res;
        s.pop();
    }
    return res;
}

string
String::multiply_numbers(const string &S1, const string &S2) {
    //sz1 = 89    sz2 = 33
    int sz1 = S1.size();
    int sz2 = S2.size();
    int sz = sz1 + sz2;
    vector<int> pos(sz, 0);
    int sum = 0;
    int m;
    for(int i=sz1-1; i >= 0 ; i--) {
        m = (sz-1)-(sz1-i-1);
        for(int j=sz2-1; j>=0 ; j--) {
            sum = (S1[i]-'0')*(S2[j]-'0') + pos[m];
            pos[m] = sum%10;
            pos[m-1] += sum/10;
            m--;
        }
    }
    string res;
    for(int m=0; m < sz; m++) {
        if(res.size() < 1 && pos[m] == 0) continue;
        res += to_string(pos[m]);
    }
    return res;
}

int
String::unique_sub_strings(const string &S) {
    unordered_set<char> m;
    vector<int> arr;
    m.emplace(S[0]);
    for(int i=1; i < S.size(); i++) {
        arr.push_back(S[i]-S[i-1]);
        if (m.find(S[i]) == m.end()) {
            m.emplace(S[i]);
        }
    }

    int count = 0;
    int consec_ones = 0;
    for(int i=0; i < arr.size(); i++) {
        if(arr[i] == 1 || arr[i] == -25) {
            consec_ones++; 
        } else {
            count += (consec_ones*(consec_ones+1)/2);
            consec_ones = 0;
        }
    }
    if(consec_ones > 0) count += (consec_ones*(consec_ones+1)/2);
    return count+m.size();
}

string
String::min_substr_length_containing_all_chars_of_another_str(const string &S, const string &T) {
    int m[128]={0};
    for(int i=0 ; i<T.size(); i++) m[T[i]]++;
    int count = T.size(), res = INT_MAX, end = 0, begin = 0, head=0;
    //helloworldwieaew
    //ew
    while(end < S.size()) {
        if(m[S[end++]]-- > 0) count--;
        while(count == 0) {
            res = min(res, end-(head=begin));
            if(m[S[begin++]]++ == 0) count++;
        }
    }
    return res >= INT_MAX ? "": S.substr(head, res);
}

int
String::max_substr_length_containing_chars_atleast_ktimes(const string &S, int k) {
    unordered_map<char,int> m;
    for(int i =0 ; i< S.size(); i++) {
        m[S[i]]++;
    }

    for(int i =0 ; i< S.size(); i++) {
        if (m[S[i]] < k) {
            int left = max_substr_length_containing_chars_atleast_ktimes(S.substr(0,i), k);
            int right = 0;
            if ((i+1) < S.size()) {
                right = max_substr_length_containing_chars_atleast_ktimes(S.substr(i+1), k);
            }
            return max(left,right);
        }
    }
    return S.size();
}

int 
String::__to_integer(const string &S, const int &start_idx, int final_idx) {
    int res=0;
    int end = S.size();
    if (final_idx != 0) end = final_idx;
    for(int i=start_idx; i<end; i++) {
        res = res * 10 + (S[i]-'0');
    }
    return res;
}

int 
String::__get_netmask(const string &S) {
    int idx = S.find("/");
    return __to_integer(S, idx+1);
}

int
String::__get_total_fixed_chars(const string &S, const int &fixed_octets) {
    int count = 0;
    int i=0;
    for(; i < S.size() && count < fixed_octets ; i++) {
        if(S[i] == '.') {
            count++;
            if (count == fixed_octets) break;
        }
    }
    return i;
}

string
String::__get_fixed_prefix(const string &S, const int &fixed_octets) {
    int num_fixed_chars = __get_total_fixed_chars(S, fixed_octets);
    return S.substr(0, num_fixed_chars);
}

int
String::__get_base_prefix_current_octet(const string &S, const int &fixed_octets) {
    int start_idx = __get_total_fixed_chars(S, fixed_octets) + 1;
    int i=start_idx;
    for(; i < S.size(); i++) {
        if (S[i] == '.') return __to_integer(S, start_idx, i);
    }
    return __to_integer(S, start_idx, S.find("/"));
}

void
String::print_all_ips_of_subnet(const string &S) {
    cout << "Subnet is " << S << endl;
    vector<string> result;
    int netmask = __get_netmask(S);
    int fixed_octets = netmask/8;
    string fixed_prefix = __get_fixed_prefix(S, fixed_octets);
    cout << "FP: " << fixed_prefix << "\tNM: " << netmask << endl;
    for(int j=4; j > fixed_octets; j--) {
        int base_current_octet = __get_base_prefix_current_octet(S, fixed_octets);
        cout << "Base: " << base_current_octet << endl;
        int num_zeroes = j-fixed_octets-1;
        string prefix = "";
        if (fixed_prefix.size() > 0) prefix = fixed_prefix + ".";
        while (num_zeroes > 0) {
            prefix += to_string(base_current_octet) + ".";
            base_current_octet = 0;
            num_zeroes--;
        }
        int max_possible = base_current_octet + (1 << (8- (netmask%8)));
        cout << " MP: " << max_possible << endl;
        for(int i=base_current_octet; i < 256 && i < max_possible; i++) {
            result.push_back(prefix + to_string(i));
        }
    }
    for(int i=0; i<result.size(); i++) {
        cout << result[i] << "\t";
    }
    cout << endl;
}

/*
Given a string s, partition s such that every string of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["a","a","b"]
    ["aa","b"],
  ]
 Ordering the results in the answer : Entry i will come before Entry j if :
len(Entryi[0]) < len(Entryj[0]) OR
(len(Entryi[0]) == len(Entryj[0]) AND len(Entryi[1]) < len(Entryj[1])) OR
*
*
*
(len(Entryi[0]) == len(Entryj[0]) AND … len(Entryi[k] < len(Entryj[k]))
In the given example,
["a", "a", "b"] comes before ["aa", "b"] because len("a") < len("aa")
*/

bool
String::_is_palindrome(const string &A) {
    int i = 0;
    int j = A.size()-1;
    while(i < j) {
        if (A[i++] != A[j--]) return false;
    }
    return true;
}

void 
String::_palindrome_partition(vector<vector<string>> &res, vector<string> &curr, const string &A, int s, int e) {
    if (s >= e) {
        res.push_back(curr);
        return;
    }
    string tmp;
    for(int i=s ; i < e; i++) {
        tmp = A.substr(s,i-s+1);
        if(_is_palindrome(tmp)) {
            curr.push_back(tmp);
            _palindrome_partition(res, curr, A, i+1, e);
            curr.pop_back();
        }
    }
}

vector<vector<string>> 
String::palindrome_partition(const string &A) {
    vector<vector<string>> res;
    vector<string> curr;
    _palindrome_partition(res, curr, A, 0, A.size());
    return res;
}

void 
String::insert_word(const string& word, TrieNode& root) {
    TrieNode *tmp = &root;
    char ch;
    for(int i=0; i < word.size()-1; i++) {
        ch = word[i];
        if (tmp->arr[ch -'a'] == NULL) tmp->arr[ch-'a'] = new TrieNode();
        tmp = tmp->arr[ch-'a'];
    }
    if (word.size() > 0) {
        ch = word[word.size()-1];
        if (tmp->arr[ch -'a'] == NULL) tmp->arr[ch-'a'] = new TrieNode(true);
        else tmp->arr[ch -'a']->set_is_word(true);
    }
}

bool 
String::word_exists(const string& word, const TrieNode& root) {
    TrieNode *tmp = const_cast<TrieNode*> (&root);
    char ch;
    for(int i=0; i < word.size()-1; i++) {
        ch = word[i];
        if(tmp->arr[ch-'a'] == NULL) return false;
        tmp = tmp->arr[ch-'a'];
    } 
    if (word.size() > 0) {
        ch = word[word.size()-1];
        tmp = tmp->arr[ch-'a'];
        return ((tmp != NULL) && (tmp->is_word()));
    }
    return false;
}
