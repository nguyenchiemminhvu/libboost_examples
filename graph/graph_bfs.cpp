#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/breadth_first_search.hpp>
#include <boost/property_map/property_map.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

class bfs_visitor : public boost::default_bfs_visitor
{
public:
    void discover_vertex(Vertex v, const Graph& g) const
    {
        std::cout << "Discover vertex: " << v << std::endl;
    }
};

int main()
{
    Graph graph;

    boost::add_edge(0, 2, graph);
    boost::add_edge(1, 1, graph);
    boost::add_edge(1, 3, graph);
    boost::add_edge(1, 4, graph);
    boost::add_edge(2, 1, graph);
    boost::add_edge(2, 3, graph);
    boost::add_edge(2, 4, graph);
    boost::add_edge(3, 1, graph);
    boost::add_edge(3, 4, graph);
    boost::add_edge(4, 0, graph);
    boost::add_edge(4, 1, graph);


    boost::print_graph(graph);

    bfs_visitor visitor;
    boost::breadth_first_search(graph, boost::vertex(0, graph), boost::visitor(visitor));

    return 0;
}