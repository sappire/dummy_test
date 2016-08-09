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

    delete [] adj_;
    delete [] visited_;
}
