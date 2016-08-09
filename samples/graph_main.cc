#include "graph.h"

using namespace std;

int main() {
    Graph g(5);
    g.add_edge(1,2);
    g.add_edge(1,3);
    g.add_edge(2,0);
    g.add_edge(3,4);
    g.toposort();

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
