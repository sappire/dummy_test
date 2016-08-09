#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph {
public:
    Graph(int num_vertices);
    ~Graph();
    void add_edge(int start, int end);
    void toposort(void);
    void dfs(int vertex);
    
private:
    void toposort_util(int idx, stack<int> &s);
    void dfs_util(int idx);
    list<int> *adj_;
    bool *visited_;
    int num_vertices_;
};
