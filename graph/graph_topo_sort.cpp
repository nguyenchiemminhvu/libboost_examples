#include <iostream>
#include <vector>
#include <list>
#include <boost/graph/adjacency_list.hpp>
#include <boost/graph/topological_sort.hpp>
#include <boost/graph/graph_utility.hpp>

typedef boost::adjacency_list<boost::vecS, boost::vecS, boost::directedS> Graph;
typedef boost::graph_traits<Graph>::vertex_descriptor Vertex;

void add_edges(Graph& g)
{
    boost::add_edge(0, 1, g);
    boost::add_edge(0, 2, g);
    boost::add_edge(1, 3, g);
    boost::add_edge(2, 3, g);
    boost::add_edge(3, 4, g);
}

int main()
{
    Graph g(5);
    add_edges(g);

    boost::print_graph(g);

    try
    {
        std::vector<Vertex> topo_order;
        boost::topological_sort(g, std::back_inserter(topo_order));

        std::cout << "Topological Sort Order:" << std::endl;
        for (auto it = topo_order.rbegin(); it != topo_order.rend(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }
    catch (const boost::not_a_dag& e)
    {
        std::cerr << "Error: The graph is not a DAG (contains a cycle)." << std::endl;
    }

    return 0;
}
