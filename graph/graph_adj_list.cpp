#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>

struct EdgeProperties
{
    EdgeProperties(const std::string& name)
        : name(name)
    {}

    std::string name;
};

struct VertexProperties
{
    VertexProperties(std::size_t id = 0)
        : id(id)
    {}

    std::size_t id;
};

int main()
{
    boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS, VertexProperties, EdgeProperties> graph(10);

    boost::add_edge(boost::vertex(0, graph), boost::vertex(1, graph), EdgeProperties("A"), graph);
    boost::add_edge(boost::vertex(1, graph), boost::vertex(2, graph), EdgeProperties("B"), graph);
    boost::add_edge(boost::vertex(1, graph), boost::vertex(4, graph), EdgeProperties("C"), graph);
    boost::add_edge(boost::vertex(2, graph), boost::vertex(3, graph), EdgeProperties("D"), graph);
    boost::add_edge(boost::vertex(3, graph), boost::vertex(5, graph), EdgeProperties("E"), graph);
    boost::add_edge(boost::vertex(3, graph), boost::vertex(6, graph), EdgeProperties("F"), graph);
    boost::add_edge(boost::vertex(4, graph), boost::vertex(2, graph), EdgeProperties("G"), graph);

    boost::print_edges(graph, "ABCDEFGHIK");
    boost::print_graph(graph);

    // const auto& edges = boost::edges(graph);
    // std::cout << "Edges of directed graph: " << std::endl;
    // for (auto iter = edges.first; iter != edges.second; iter++)
    // {
    //     const auto& edge = *iter;
    //     const auto& source = boost::source(edge, graph);
    //     const auto& dest = boost::target(edge, graph);

    //     std::cout << source << " -> " << dest << std::endl;
    // }

    boost::remove_edge(boost::vertex(4, graph), boost::vertex(2, graph), graph);

    boost::print_edges(graph, "ABCDEFGHIK");
    boost::print_graph(graph);

    // const auto& new_edges = boost::edges(graph);
    // std::cout << "Edges of directed graph: " << std::endl;
    // for (auto iter = new_edges.first; iter != new_edges.second; iter++)
    // {
    //     const auto& edge = *iter;
    //     const auto& source = boost::source(edge, graph);
    //     const auto& dest = boost::target(edge, graph);

    //     std::cout << source << " -> " << dest << std::endl;
    // }

    return 0;
}