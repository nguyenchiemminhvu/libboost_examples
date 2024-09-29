#include <iostream>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/depth_first_search.hpp>
#include <boost/graph/graph_utility.hpp>
#include <boost/graph/visitors.hpp>

class custom_dfs_visitor : public boost::default_dfs_visitor
{
public:
    template <typename Edge, typename Graph>
    void tree_edge(Edge e, const Graph& g) const
    {
        std::cout << "Tree edge: " << source(e, g) << " --> " << target(e, g) << std::endl;
    }

    template <typename Edge, typename Graph>
    void back_edge(Edge e, const Graph& g) const
    {
        std::cout << "Back edge (Cycle detected): " << source(e, g) << " --> " << target(e, g) << std::endl;
    }

    template <typename Edge, typename Graph>
    void forward_or_cross_edge(Edge e, const Graph& g) const
    {
        std::cout << "Forward/Cross edge: " << source(e, g) << " --> " << target(e, g) << std::endl;
    }

    template <typename Vertex, typename Graph>
    void discover_vertex(Vertex u, const Graph& g) const
    {
        std::cout << "Discovered vertex: " << u << std::endl;
    }

    template <typename Vertex, typename Graph>
    void finish_vertex(Vertex u, const Graph& g) const
    {
        std::cout << "Finished vertex: " << u << std::endl;
    }
};

int main()
{
    using Graph = boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS>;

    Graph g(6);

    add_edge(0, 1, g);
    add_edge(0, 2, g);
    add_edge(1, 3, g);
    add_edge(2, 3, g);
    add_edge(3, 4, g);
    add_edge(4, 5, g);
    add_edge(5, 1, g);

    custom_dfs_visitor vis;

    std::cout << "Starting Depth-First Search with Edge Classification:" << std::endl;
    boost::depth_first_search(g, visitor(vis).root_vertex(0));

    return 0;
}
