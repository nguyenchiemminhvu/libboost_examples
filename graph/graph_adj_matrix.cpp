#include <iostream>
#include <boost/graph/adjacency_matrix.hpp>
#include <boost/graph/graph_utility.hpp>

enum
{
    A,
    B,
    C,
    D,
    E,
    F,
    N
};
const char* name = "ABCDEF";

int main()
{
    boost::adjacency_matrix<boost::directedS> graph(N);

    boost::add_edge(B, C, graph);
    boost::add_edge(B, F, graph);
    boost::add_edge(C, A, graph);
    boost::add_edge(C, C, graph);
    boost::add_edge(D, E, graph);
    boost::add_edge(E, D, graph);
    boost::add_edge(F, A, graph);

    boost::print_edges(graph, name);
    boost::print_graph(graph);

    return 0;
}