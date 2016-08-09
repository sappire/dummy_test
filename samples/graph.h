#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int num_vertices);
    void add_edge(int start, int end);
    void toposort(void);
    
private:
    void toposort_util(int idx, stack<int> &s);
    list<int> *adj_;
    bool *visited_;
    int num_vertices_;
};
