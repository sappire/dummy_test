#include "graph.h"

Graph::Graph(int num_vertices)
          : num_vertices_(num_vertices) {
    adj_ = new list<int>[num_vertices_];
}

void
Graph::add_edge(int start, int end) {
    adj_[start].push_back(end);
}

void  
Graph::toposort_util(int idx, stack<int> &s) {
    visited_[idx] = true;

    list<int>::iterator it;
    for (it = adj_[idx].begin(); it != adj_[idx].end(); ++it) {
        if (visited_[*it] == false) {
            toposort_util(*it, s);
        }
    }
    s.push(idx);
}

void 
Graph::toposort(void) {
    cout << "TOPOSORT: ";
    stack<int> s;
    visited_ = new bool[num_vertices_];
    for (int i=0; i < num_vertices_; i++) {
        visited_[i] = false;
    }

    for (int i=0; i < num_vertices_; i++) {
        if (visited_[i] == false) {
            toposort_util(i, s);
        }
    }
    
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    delete [] visited_;
}

void  
Graph::dfs_util(int idx) {
    visited_[idx] = true;
    cout << idx << " ";
    list<int>::iterator it;
    for (it = adj_[idx].begin(); it != adj_[idx].end(); ++it) {
        if (visited_[*it] == false) {
            dfs_util(*it);
        }
    }
}

void 
Graph::dfs(int vertex) {
    cout << "DFS from vertex \"" << vertex << "\" is : ";
    visited_ = new bool[num_vertices_];
    for (int i=0; i < num_vertices_; i++) {
        visited_[i] = false;
    }

    dfs_util(vertex);

    cout << endl;
    delete [] visited_;
}
 
void  
Graph::bfs_util(queue<int> &q) {

    int idx = 0; 
    while (!q.empty()) {
        idx = q.front();
        q.pop();
        cout << idx << " ";
    
        list<int>::iterator it;
        for (it = adj_[idx].begin(); it != adj_[idx].end(); ++it) {
            if (visited_[*it] == false) {
                visited_[*it] = true;
                q.push(*it);
            }
        }
    }
    return;
}

void 
Graph::bfs(int vertex) {
    cout << "BFS from vertex \"" << vertex << "\" is : ";
    visited_ = new bool[num_vertices_];
    for (int i=0; i < num_vertices_; i++) {
        visited_[i] = false;
    }
    queue<int> q;
    visited_[vertex] = true;
    q.push(vertex);
    bfs_util(q);

    cout << endl;
    delete [] visited_;
}

Graph::~Graph() {
    delete[] adj_;
}
