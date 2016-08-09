#include "graph.h"

using namespace std;

int main() {
    Graph g(5);
    g.add_edge(1,0);
    g.add_edge(1,2);
    g.add_edge(2,4);
    g.add_edge(4,3);
    g.toposort();
    //Starting from vertex below, print the DFS
    g.dfs(1);

/*	Graph g(6);
	g.add_edge(5, 2);
	g.add_edge(5, 0);
	g.add_edge(4, 0);
	g.add_edge(4, 1);
	g.add_edge(2, 3);
	g.add_edge(3, 1);
    g.toposort();
*/    return 1;
}
