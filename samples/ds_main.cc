#include<iostream>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<vector>

using namespace std;

void test1(void) {
    cout << "-------------1. Test ordering of keys with map and unordered map----------" << endl;
    map<int,int> m;
    unordered_map<int,int> um;
    m.emplace(6,10);
    m.emplace(1,30);
    m.emplace(3,33);
    um.emplace(6,10);
    um.emplace(1,30);
    um.emplace(3,33);
    cout << "map order:{";
    for(auto it=m.begin(); it != m.end(); it++) cout << it->first << ":" << it->second << ",";
    cout << "}" << endl;
    cout << "unordered map order:{";
    for(auto it=um.begin(); it != um.end(); it++) cout << it->first << ":" << it->second << ",";
    cout << "}" << endl;
}

int main() {
    test1();
    return 0;
}
