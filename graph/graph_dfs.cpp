#include <iostream>
#include <vector>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/visitors.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/property_map/property_map.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::undirectedS> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

class dfs_visitor : public boost::default_dfs_visitor
{
public:
    void discover_vertex(Vertex v, const Graph& g) const
    {
        std::cout << "Discover vertex: " << v << std::endl;
    }

    void finish_vertex(Vertex v, const Graph& g) const
    {
        std::cout << "Finish vertex: " << v << std::endl;
    }
};

int main()
{
    Graph graph;

    boost::add_edge(0, 2, graph);
    boost::add_edge(1, 1, graph);
    boost::add_edge(1, 4, graph);
    boost::add_edge(2, 1, graph);
    boost::add_edge(2, 3, graph);
    boost::add_edge(2, 4, graph);
    boost::add_edge(3, 1, graph);

    boost::print_graph(graph);

    dfs_visitor visitor;
    boost::depth_first_search(graph, boost::visitor(visitor).root_vertex(0));

    return 0;
}