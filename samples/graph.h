#include <iostream>
#include <list>
#include <stack>
#include <queue>

using namespace std;

class Graph {
public:
    Graph(int num_vertices);
    ~Graph();
    void add_edge(int start, int end);
    void toposort(void);
    void dfs(int vertex);
    void bfs(int vertex);
    
private:
    void toposort_util(int idx, stack<int> &s);
    void dfs_util(int idx);
    void bfs_util(queue<int> &q);
    list<int> *adj_;
    bool *visited_;
    int num_vertices_;
};
