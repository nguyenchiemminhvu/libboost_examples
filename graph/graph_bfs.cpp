#include <iostream>
#include <boost/graph/adjacency_list.hpp>

int main()
{
    boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> graph(10);

    boost::add_edge(0, 1, graph);
    boost::add_edge(1, 3, graph);
    boost::add_edge(2, 4, graph);
    boost::add_edge(2, 5, graph);
    boost::add_edge(4, 6, graph);
    boost::add_edge(1, 4, graph);
    boost::add_edge(0, 5, graph);

    const auto& edges = boost::edges(graph);
    std::cout << "Edges of undirected graph: " << std::endl;
    for (auto iter = edges.first; iter != edges.second; iter++)
    {
        const auto& edge = *iter;
        const auto& source = boost::source(edge, graph);
        const auto& dest = boost::target(edge, graph);

        std::cout << source << " <-> " << dest << std::endl;
    }

    return 0;
}